/*
* FILENAMN:    Search_vehicle.cc
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
#include "Vehicle.h"
#include "Search_vehicle.h"

using namespace std;

/////////////////////////////////////////////////////////////////////
// Search_vehicle:
/////////////////////////////////////////////////////////////////////

// Search for all vehicles in the database.
vector<Vehicle*> 
Search_vehicle::
all()
{
   vector<vector<string>> vehicle_str_vector = 
      Database::vehicle_search("all", "");

   create_result(vehicle_str_vector);
   
   return search_result;
}

// Search for a specific vehicle by it's reg_nr in the database.
vector<Vehicle*> 
Search_vehicle::
reg_nr(string& reg_nr)
{
   vector<vector<string>> vehicle_str_vector = 
      Database::vehicle_search("reg_nr", reg_nr);

   create_result(vehicle_str_vector);
   
   return search_result;
}

// Search for specific type of vehicles in the database.
vector<Vehicle*> 
Search_vehicle::
type(string& type)
{
   vector<vector<string>> vehicle_str_vector = 
      Database::vehicle_search("type", type);

   create_result(vehicle_str_vector);
   
   return search_result;
}

// Search for specific status of vehicles in the database.
vector<Vehicle*> 
Search_vehicle::
status(string& status)
{
   vector<vector<string>> vehicle_str_vector = 
      Database::vehicle_search("status", status);

   create_result(vehicle_str_vector);
   
   return search_result;
}

// Search for specific brand of vehicles in the database.
vector<Vehicle*> 
Search_vehicle::
brand(string& brand)
{
   vector<vector<string>> vehicle_str_vector = 
      Database::vehicle_search("brand", brand);

   create_result(vehicle_str_vector);
   
   return search_result;
}

// Search for specific brand and model of vehicles in the database.
vector<Vehicle*> 
Search_vehicle::
model(string& model)
{
   vector<vector<string>> vehicle_str_vector = 
      Database::vehicle_search("model", model);

   create_result(vehicle_str_vector);
   
   return search_result;
}
/*
// Search for specific type and date of vehicles in the database.
vector<Vehicle*> 
Search_vehicle::
type_date(string& type, string& start, string& end)
{
   vector<vector<string>> vehicle_str_vector = 
      Database::vehicle_search_date(type, start, end);

   create_result(vehicle_str_vector);

   return search_result;
}
*/
// Return the result ny a list, from last search.
vector<Vehicle*> 
Search_vehicle::
get_current_result() const
{
   return search_result;
}

// Helpfunction to create object from string vectors, 
// send by the database, throw if wrong indata.
void 
Search_vehicle::
create_result(vector<vector<string>>& str_vector)
{
   clear();
   vector<vector<string>>::iterator it;
   
   for(it = str_vector.begin(); it < str_vector.end(); it++)
   {
      vector<string> current = *it;
      int mileage = atoi(current[5].c_str());
      
      if(current.size() == 7)
      {
         search_result.push_back(new Vehicle(current[0], current[1], 
            current[2], current[3], current[4], mileage, 
            current[6]));
      }
      else
         throw search_vehicle_error("The lenght of the vector is not 7.");
   }
}

// Return true if search_result is empty, else false.
bool 
Search_vehicle::
empty() const
{
   return search_result.empty();
}

// Clear the search_result.
void 
Search_vehicle::
clear()
{
   search_result.clear();
}