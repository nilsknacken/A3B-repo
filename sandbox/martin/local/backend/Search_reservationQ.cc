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
* Defination av the reservation search class and it's functions.
* The class handle searchings in the database of reservations and
* create a proper output.
*
* Created by:
* Conny: All
* Martin: minor bug fix
*/

#include <stdlib.h>
#include <QString>
#include <vector>
#include "ReservationQ.h"
#include "Search_reservationQ.h"

using namespace std;

/////////////////////////////////////////////////////////////////////
// Search_reservation:
/////////////////////////////////////////////////////////////////////
// First off, do delete on every pointer in the vector.
// Then clear the vector.
Search_reservation::
~Search_reservation()
{
    clear();
}

// Search for all  reservations in the database.
vector<Reservation*>
Search_reservation::
all()
{
    vector<vector<QString>> reservation_str_vector =
            Database::reservation_search("all", "value");

    create_result(reservation_str_vector);

    return search_result;
}

// Search for a specific reservation by it's res_nr in the database.
vector<Reservation*> 
Search_reservation::
res_nr(int res_nr)
{
    vector<vector<QString>> reservation_str_vector =
            Database::reservation_search(res_nr);

    create_result(reservation_str_vector);

    return search_result;
}

// Search for a specific reservations by it's reg_nr in the database.
vector<Reservation*> 
Search_reservation::
reg_nr(QString& reg_nr)
{
    vector<vector<QString>> reservation_str_vector =
            Database::reservation_search("reg_nr", reg_nr);

    create_result(reservation_str_vector);

    return search_result;
}

// Search for a specific reservations by it's name in the database.
vector<Reservation*> 
Search_reservation::
name(QString& name)
{
    vector<vector<QString>> reservation_str_vector =
            Database::reservation_search("name", name);

    create_result(reservation_str_vector);

    return search_result;
}

// Search for a specific reservation by it's tel in the database.
vector<Reservation*> 
Search_reservation::
tel(QString& tel)
{
    vector<vector<QString>> reservation_str_vector =
            Database::reservation_search("tel", tel);

    create_result(reservation_str_vector);

    return search_result;
}

// Search for a specific reservations by it's status in the database.
vector<Reservation*> 
Search_reservation::
status(QString& status)
{
    vector<vector<QString>> reservation_str_vector =
            Database::reservation_search("status", status);

    create_result(reservation_str_vector);

    return search_result;
}

// Search for a specific reservations by it's start- and 
// endtime in the database.
vector<Reservation*> 
Search_reservation::
start_end(QString& start, QString& end)
{
    vector<vector<QString>> reservation_str_vector =
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

// Helpfunction to create object from QString vectors, 
// send by the database, throw if wrong indata.
void 
Search_reservation::
create_result(vector<vector<QString>>& str_vector)
{
    clear();
    try
    {
        vector<vector<QString>>::iterator it;

        for(it = str_vector.begin(); it < str_vector.end(); it++)
        {
            vector<QString> current = *it;
            int res_nr = current[0].toInt();

            if(current.size() == 10)
            {
                search_result.push_back(new Reservation(res_nr, current[1], current[2],
                                                        current[3], current[4], current[5],
                                                        current[6], current[7], current[8],
                                                        current[9]));
            }
            else
                throw search_reservation_error("The lenght of the vector is not 10.");
        }
    }
    catch (const bad_alloc& ba)
    {
        clear();
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
    while(! search_result.empty())
    {
        delete search_result.back();
        search_result.back() = nullptr;

        search_result.pop_back();
     }
}
