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
#include <string>
#include <cstring>

using namespace std;

// Init of the db pointer
sqlite3* Database::db;

// Opens database with name specified in filename
bool Database::open(const char* filename)
{
   db = NULL;

/*   // Converts string filename to char*
   char* char_file = new char[filename.size()+1];
   char_file[filename.size()]=0;
   memcpy(char_file, filename.c_str(), filename.size());
*/   
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


// Initializes the database if not already done.
void Database::init_db()
{
   cerr <<"Init db\n";
}

      
