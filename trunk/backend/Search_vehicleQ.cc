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
#include <QString>
#include <vector>
#include "VehicleQ.h"
#include "Search_vehicleQ.h"

using namespace std;

/////////////////////////////////////////////////////////////////////
// Search_vehicle:
/////////////////////////////////////////////////////////////////////
// First off, do delete on every pointer in the vector.
// Then clear the vector.
Search_vehicle::
~Search_vehicle()
{
    clear();
}

// Search for all vehicles in the database.
vector<Vehicle*> 
Search_vehicle::
all()
{
    vector<vector<QString>> vehicle_str_vector =
            Database::vehicle_search("all", "");

    create_result(vehicle_str_vector);

    return search_result;
}

// Search for a specific vehicle by it's reg_nr in the database.
vector<Vehicle*> 
Search_vehicle::
reg_nr(QString& reg_nr)
{
    vector<vector<QString>> vehicle_str_vector =
            Database::vehicle_search("reg_nr", reg_nr);

    create_result(vehicle_str_vector);

    return search_result;
}

// Search for specific type of vehicles in the database.
vector<Vehicle*> 
Search_vehicle::
type(QString& type)
{
    vector<vector<QString>> vehicle_str_vector =
            Database::vehicle_search("type", type);

    create_result(vehicle_str_vector);

    return search_result;
}

// Search for specific status of vehicles in the database.
vector<Vehicle*> 
Search_vehicle::
status(QString& status)
{
    vector<vector<QString>> vehicle_str_vector =
            Database::vehicle_search("status", status);

    create_result(vehicle_str_vector);

    return search_result;
}

// Search for specific brand of vehicles in the database.
vector<Vehicle*> 
Search_vehicle::
brand(QString& brand)
{
    vector<vector<QString>> vehicle_str_vector =
            Database::vehicle_search("brand", brand);

    create_result(vehicle_str_vector);

    return search_result;
}

// Search for specific brand and model of vehicles in the database.
vector<Vehicle*> 
Search_vehicle::
model(QString& model)
{
    vector<vector<QString>> vehicle_str_vector =
            Database::vehicle_search("model", model);

    create_result(vehicle_str_vector);

    return search_result;
}

// Search for specific type and date of vehicles in the database.
vector<Vehicle*> 
Search_vehicle::
type_date(QString& type, QString& start, QString& end)
{
    vector<vector<QString>> vehicle_str_vector =
            Database::vehicle_search(type, start, end);

    create_result(vehicle_str_vector);

    return search_result;
}

// Return the result ny a list, from last search.
vector<Vehicle*> 
Search_vehicle::
get_current_result() const
{
    return search_result;
}

// Helpfunction to create object from QString vectors, 
// send by the database, throw if wrong indata.
void 
Search_vehicle::
create_result(vector<vector<QString>>& str_vector)
{
    try
    {
        clear();
        vector<vector<QString>>::iterator it;

        for(it = str_vector.begin(); it < str_vector.end(); it++)
        {
            vector<QString> current = *it;
            int mileage = current[5].toInt();

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
    catch(const bad_alloc& ba)
    {
        clear();
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
    /*vector<Vehicle*>::iterator i;

    for(i = search_result.begin(); i < search_result.end(); i++)
    {
        delete *i;
    }
    search_result.clear();


    for (int i = 0; i < search_result.size(); ++i)
    {
        delete search_result[i];
        search_result[i] = nullptr;
    }
*/
}
