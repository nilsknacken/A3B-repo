/*
* FILENAMN:    Search_reservation.cc
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-10-18
*
* DESCRIPTION
* 
* ///////////////Programbeskrivning
*/

#include <stdlib.h>
#include <string>
#include <vector>

#include "Database.h"
#include "Reservation.h"
#include "Search_reservation.h"

using namespace std;

/////////////////////////////////////////////////////////////////////
// Search_reservation:
/////////////////////////////////////////////////////////////////////

// Search for a specific reservation by it's res_nr in the database.
vector<Reservation*> 
Search_reservation::
res_nr(int res_nr)
{
   vector<vector<string>> reservation_str_vector = 
      Database::reservation_search(res_nr);

   create_result(reservation_str_vector);
   
   return search_result;
}

// Search for a specific reservations by it's reg_nr in the database.
vector<Reservation*> 
Search_reservation::
reg_nr(string& reg_nr)
{
   vector<vector<string>> reservation_str_vector = 
      Database::reservation_search("reg_nr", reg_nr);

   create_result(reservation_str_vector);
   
   return search_result;
}

// Search for a specific reservations by it's name in the database.
vector<Reservation*> 
Search_reservation::
name(string& name)
{
   vector<vector<string>> reservation_str_vector = 
      Database::reservation_search("name", name);

   create_result(reservation_str_vector);
   
   return search_result;
}

// Search for a specific reservation by it's tel in the database.
vector<Reservation*> 
Search_reservation::
tel(string& tel)
{
   vector<vector<string>> reservation_str_vector = 
      Database::reservation_search("tel", tel);

   create_result(reservation_str_vector);
   
   return search_result;
}

// Search for a specific reservations by it's status in the database.
vector<Reservation*> 
Search_reservation::
status(string& status)
{
   vector<vector<string>> reservation_str_vector = 
      Database::reservation_search("status", status);

   create_result(reservation_str_vector);
   
   return search_result;
}

// Search for a specific reservations by it's start- and 
// endtime in the database.
vector<Reservation*> 
Search_reservation::
start_end(string& start, string& end)
{
   vector<vector<string>> reservation_str_vector = 
      Database::reservation_search_date(start, end);

   create_result(reservation_str_vector);

   return search_result;
}

// Return the result ny a list, from last search.
vector<Reservation*> 
Search_reservation::
get_current_result() const
{
   return search_result;
}

// Helpfunction to create object from string vectors, 
// send by the database, throw if wrong indata.
void 
Search_reservation::
create_result(vector<vector<string>>& str_vector)
{
   clear();
   vector<vector<string>>::iterator it;
   
   for(it = str_vector.begin(); it < str_vector.end(); it++)
   {
      vector<string> current = *it;
      int res_nr = atoi(current[0].c_str());
      
      if(current.size() == 10)
      {
         search_result.push_back(new Reservation(res_nr, current[1], 
            current[2], current[3], current[4], current[5], 
            current[6], current[7], current[8], current[9]));
      }
      else
         throw search_reservation_error("The lenght of the vector is not 10.");
   }
}

// Return true if search_result is empty, else false.
bool 
Search_reservation::
empty() const
{
   return search_result.empty();
}

// Clear the search_result.
void 
Search_reservation::
clear()
{
   search_result.clear();
}