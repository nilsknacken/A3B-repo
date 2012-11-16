/*
* Filename:    Database.cc
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-10-12
*
* DESCRIPTION:
* 
* Database
*/

#include "Database.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

// Init of the db pointer
sqlite3* Database::db;

// Opens database with name specified in filename
bool Database::open(const char* filename)
{
   db = NULL;

   if (sqlite3_open(filename, &db) == SQLITE_OK)
   {
      init_db();
      return true;
   }
   else
   {
      throw database_error("Could not open database!\n");
      return false;
   }
}


// Closes the connection to the database
void Database::close()
{
   sqlite3_close_v2(db);
}


// Updates/saves given reservation.
void Database::reservation_update(const int res_nr,
                                  const string& reg_nr,
                                  const string& start,
                                  const string& end,
                                  const string& status,
                                  const string& name,
                                  const string& tel,
                                  const string& address,
                                  const string& postal_nr,
                                  const string& city)
{
   cerr << "res update start\n";
   
   sqlite3_stmt* statement;
   const char* query = "INSERT or REPLACE INTO Reservations"
      "(res_nr, reg_nr, start, end, status, name, tel, address, postal_nr, city)"
      "values (?1, ?2, ?3, ?4, ?5, ?6, ?7, ?8, ?9, ?10)";

   if (sqlite3_prepare_v2(db, query, -1, &statement, 0) == SQLITE_OK)
   {
      sqlite3_bind_int(statement, 1, res_nr);
      sqlite3_bind_text(statement, 2, reg_nr.c_str(), reg_nr.size(), SQLITE_TRANSIENT);
      sqlite3_bind_text(statement, 3, start.c_str(), start.size(), SQLITE_TRANSIENT);
      sqlite3_bind_text(statement, 4, end.c_str(), end.size(), SQLITE_TRANSIENT);
      sqlite3_bind_text(statement, 5, status.c_str(), status.size(), SQLITE_TRANSIENT);
      sqlite3_bind_text(statement, 6, name.c_str(), name.size(), SQLITE_TRANSIENT);
      sqlite3_bind_text(statement, 7, tel.c_str(), tel.size(), SQLITE_TRANSIENT);
      sqlite3_bind_text(statement, 8, address.c_str(), address.size(), SQLITE_TRANSIENT);
      sqlite3_bind_text(statement, 9, postal_nr.c_str(), postal_nr.size(), SQLITE_TRANSIENT);
      sqlite3_bind_text(statement, 10, city.c_str(), city.size(), SQLITE_TRANSIENT);

      sqlite3_step(statement);
      sqlite3_finalize(statement);
   }
   else
   {
      check_for_error();
      // throw database_error("Failed to prepare statement in reservation update!");
   }

   cerr << "res update end\n";
}


// Performs a search in the Reservations table
vector<vector<string>>
Database::reservation_search(const string& what, const string& value)
{
   cerr << "res search start\n";
   
   sqlite3_stmt* statement;
   vector<vector<string>> result;
   
   if (what == "all")
   {
      const char* query = "SELECT * FROM Reservations";
      if (sqlite3_prepare_v2(db, query, -1, &statement,0) == SQLITE_OK)
      {
         result = ask(statement);
      }
   }
   else if (what == "res_nr")
   {
   }
   else
   {
      if (what == "reg_nr")
      {
      }
      else if (what == "status")
      {
      }

      //allmän prepare
   }

   cerr << "res search end\n";
   return result;
      
}


// Displays results, only for testing
void Database::display(vector<vector<string>> result)
{
   cout << endl;
   
   for(vector<vector<string> >::iterator it = result.begin(); it < result.end(); ++it)
   {
      vector<string> row = *it;

     
      for (unsigned int i = 0; i < row.size(); ++i)
         cout << setw(18) << row[i];

      cout << endl;
      
   }

   cout << endl;
}
      
// Initializes the database if not already done.
void Database::init_db()
{
   cerr <<"Init db\n";
   
   sqlite3_exec(db,
                "CREATE TABLE IF NOT EXISTS Reservations ("
                "res_nr INTEGER NOT NULL UNIQUE, reg_nr TEXT, start TEXT, end TEXT,"
                "status TEXT, name TEXT, tel TEXT, address TEXT,"
                "postal_nr TEXT, city TEXT)", NULL, 0, NULL);
   
   check_for_error();
      
   // Skapa Vehicles, Settings             
   cerr << "Init klar\n";
}


// Asks the prepared statement to the database. Returns a vector with
// the all the rows of the result, where each row consits of a vector with
// each column as an element.
vector<vector<string>> Database::ask(sqlite3_stmt* statement)
{
   cerr << "ask start\n";
   
   vector<vector<string>> results;
   
   int cols = sqlite3_column_count(statement);
   int result = 0;

   while(true)
   {
      result = sqlite3_step(statement);
			
      if(result == SQLITE_ROW)
      {
         vector<string> values;
         string val;
         
         for(int col = 0; col < cols; col++)
         {
            char * ptr = (char*)sqlite3_column_text(statement, col);

            if(ptr)
               val = ptr;
            
            values.push_back(val);
         }
         results.push_back(values);
      }
      else
      {
         break;   
      }
   }
	   
   sqlite3_finalize(statement);
   
   check_for_error();

   cerr << "ask end\n";
   return results;
}


// Checks if the database has an error
void Database::check_for_error()
{
   string error = sqlite3_errmsg(db);
   if(error != "not an error")
      throw database_error(error);
}
