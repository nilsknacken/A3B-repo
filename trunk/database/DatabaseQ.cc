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
* Implementation of the Database
*
* Created by:
* Martin: All
*/

#include "DatabaseQ.h"
#include <iostream>
#include <iomanip>
#include <QString>
#include <cstring>
#include <stdlib.h>

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
        fill_db();  // only for testing to init some entries to the value
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
                                  const QString& reg_nr,
                                  const QString& start,
                                  const QString& end,
                                  const QString& status,
                                  const QString& name,
                                  const QString& tel,
                                  const QString& address,
                                  const QString& postal_nr,
                                  const QString& city)
{
    sqlite3_stmt* statement;
    const char* query = "INSERT or REPLACE INTO Reservations"
            "(res_nr, reg_nr, start, end, status, name, tel, address, postal_nr, city)"
            "values (?1, ?2, ?3, ?4, ?5, ?6, ?7, ?8, ?9, ?10)";

    if (sqlite3_prepare_v2(db, query, -1, &statement, 0) == SQLITE_OK)
    {
        sqlite3_bind_int(statement, 1, res_nr);
        sqlite3_bind_text(statement, 2, reg_nr.toStdString().c_str(), reg_nr.size(), SQLITE_TRANSIENT);
        sqlite3_bind_text(statement, 3, start.toStdString().c_str(), start.size(), SQLITE_TRANSIENT);
        sqlite3_bind_text(statement, 4, end.toStdString().c_str(), end.size(), SQLITE_TRANSIENT);
        sqlite3_bind_text(statement, 5, status.toStdString().c_str(), status.size(), SQLITE_TRANSIENT);
        sqlite3_bind_text(statement, 6, name.toStdString().c_str(), name.size(), SQLITE_TRANSIENT);
        sqlite3_bind_text(statement, 7, tel.toStdString().c_str(), tel.size(), SQLITE_TRANSIENT);
        sqlite3_bind_text(statement, 8, address.toStdString().c_str(), address.size(), SQLITE_TRANSIENT);
        sqlite3_bind_text(statement, 9, postal_nr.toStdString().c_str(), postal_nr.size(), SQLITE_TRANSIENT);
        sqlite3_bind_text(statement, 10, city.toStdString().c_str(), city.size(), SQLITE_TRANSIENT);

        sqlite3_step(statement);
        sqlite3_finalize(statement);
    }

    check_for_error();
}


// Updates/saves given reservation.
void Database::vehicle_update(const QString& reg_nr,
                              const QString& type,
                              const QString& status,
                              const QString& brand,
                              const QString& model,
                              const int mileage,
                              const QString& damage)
{
    sqlite3_stmt* statement;
    const char* query = "INSERT or REPLACE INTO Vehicles"
            "(reg_nr, type, status, brand, model, mileage, damage)"
            "values (?1, ?2, ?3, ?4, ?5, ?6, ?7)";

    if (sqlite3_prepare_v2(db, query, -1, &statement, 0) == SQLITE_OK)
    {
        sqlite3_bind_text(statement, 1, reg_nr.toStdString().c_str(), reg_nr.size(), SQLITE_TRANSIENT);
        sqlite3_bind_text(statement, 2, type.toStdString().c_str(), type.size(), SQLITE_TRANSIENT);
        sqlite3_bind_text(statement, 3, status.toStdString().c_str(), status.size(), SQLITE_TRANSIENT);
        sqlite3_bind_text(statement, 4, brand.toStdString().c_str(), brand.size(), SQLITE_TRANSIENT);
        sqlite3_bind_text(statement, 5, model.toStdString().c_str(), model.size(), SQLITE_TRANSIENT);
        sqlite3_bind_int(statement, 6, mileage);
        sqlite3_bind_text(statement, 7, damage.toStdString().c_str(), damage.size(), SQLITE_TRANSIENT);

        sqlite3_step(statement);
        sqlite3_finalize(statement);
    }

    check_for_error();
}


// Updates/saves settings table.
void Database::settings_update(
        const int open_hour,
        const int open_min,
        const int close_hour,
        const int close_min,
        const int min_rental)
{
    sqlite3_stmt* statement;
    const char* query = "INSERT or REPLACE INTO Settings"
            "(open_hour, open_min, close_hour, close_min, min_rental, id)"
            "values (?1, ?2, ?3, ?4, ?5, 1)";

    if (sqlite3_prepare_v2(db, query, -1, &statement, 0) == SQLITE_OK)
    {
        sqlite3_bind_int(statement, 1, open_hour);
        sqlite3_bind_int(statement, 2, open_min);
        sqlite3_bind_int(statement, 3, close_hour);
        sqlite3_bind_int(statement, 4, close_min);
        sqlite3_bind_int(statement, 5, min_rental);

        sqlite3_step(statement);
        sqlite3_finalize(statement);
    }

    check_for_error();
}


// Performs a search in the Reservations table
vector<vector<QString> >
Database::reservation_search(const QString& what, const QString& value)
{
    sqlite3_stmt* statement;
    vector<vector<QString> > result;

    if (what == "all")
    {
        const char* query = "SELECT * FROM Reservations";
        sqlite3_prepare_v2(db, query, -1, &statement,0);
    }
    else if (what == "reg_nr")
    {
        const char* query = "SELECT * FROM Reservations WHERE reg_nr = ?1";
        statement = bind_QString(query, value);
    }
    else if (what == "status")
    {
        const char* query = "SELECT * FROM Reservations WHERE status = ?1";
        statement = bind_QString(query, value);
    }
    else if (what == "name")
    {
        const char* query = "SELECT * FROM Reservations WHERE name = ?1";
        statement = bind_QString(query, value);
    }
    else if (what == "tel")
    {
        const char* query = "SELECT * FROM Reservations WHERE tel = ?1";
        statement = bind_QString(query, value);
    }
    else
    {
        throw database_error("Invalid what argument to reservations_search in db!");
    }

    result = ask(statement);
    check_for_error();
    return result;
}


// Performs a search in the Reservations table for res_nr
vector<vector<QString> >
Database::reservation_search(const int res_nr)
{
    sqlite3_stmt* statement;
    vector<vector<QString> > result;

    const char* query = "SELECT * FROM Reservations WHERE res_nr = ?1";
    if (sqlite3_prepare_v2(db, query, -1, &statement,0) == SQLITE_OK)
    {
        sqlite3_bind_int(statement, 1, res_nr);
    }

    result = ask(statement);
    check_for_error();
    return result;
}


// Performs a search in the Reservations table for res between given dates
vector<vector<QString> >
Database::reservation_search_date(const QString& start, const QString& end)
{
    sqlite3_stmt* statement;
    vector<vector<QString> > result;

    const char* query = "SELECT * FROM Reservations WHERE"
            "(start >= ?1 AND start <= ?2) OR (end >= ?1 AND end <= ?2)"
            " OR (start < ?1 and end > ?2)";

    if (sqlite3_prepare_v2(db, query, -1, &statement,0) == SQLITE_OK)
    {
        sqlite3_bind_text(statement, 1, start.toStdString().c_str(), start.size(), SQLITE_TRANSIENT);
        sqlite3_bind_text(statement, 2, end.toStdString().c_str(), end.size(), SQLITE_TRANSIENT);
        result = ask(statement);
    }

    check_for_error();
    return result;
}


// Performs a search in the Vehicles table
vector<vector<QString> >
Database::vehicle_search(const QString& what, const QString& value)
{
    sqlite3_stmt* statement;
    vector<vector<QString> > result;

    if (what == "all")
    {
        const char* query = "SELECT * FROM Vehicles";
        sqlite3_prepare_v2(db, query, -1, &statement,0);
    }
    else if (what == "reg_nr")
    {
        const char* query = "SELECT * FROM Vehicles WHERE reg_nr = ?1";
        statement = bind_QString(query, value);
    }
    else if (what == "type")
    {
        const char* query = "SELECT * FROM Vehicles WHERE type = ?1";
        statement = bind_QString(query, value);
    }
    else if (what == "status")
    {
        const char* query = "SELECT * FROM Vehicles WHERE status = ?1";
        statement = bind_QString(query, value);
    }
    else if (what == "brand")
    {
        const char* query = "SELECT * FROM Vehicles WHERE brand = ?1";
        statement = bind_QString(query, value);
    }
    else if (what == "model")
    {
        const char* query = "SELECT * FROM Vehicles WHERE model = ?1";
        statement = bind_QString(query, value);
    }
    else
    {
        throw database_error("Invalid what argument to vehicle_search in db!");
    }

    result = ask(statement);
    check_for_error();
    return result;

}


// Returns the available vehicles of given type during start->end
vector<vector<QString> >
Database::vehicle_search(const QString& type, const QString& start, const QString& end)
{
    sqlite3_stmt* statement;
    vector<vector<QString> > result;

    const char* query = "SELECT * FROM Vehicles WHERE type = ?1 AND Vehicles.reg_nr NOT IN "
            "(SELECT Reservations.reg_nr FROM Reservations WHERE "
            "(Reservations.start >= ?2 AND Reservations.start <= ?3) OR (Reservations.end >= ?2 AND Reservations.end <= ?3) )";

    if (sqlite3_prepare_v2(db, query, -1, &statement,0) == SQLITE_OK)
    {
        sqlite3_bind_text(statement, 1, type.toStdString().c_str(), type.size(), SQLITE_TRANSIENT);
        sqlite3_bind_text(statement, 2, start.toStdString().c_str(), start.size(), SQLITE_TRANSIENT);
        sqlite3_bind_text(statement, 3, end.toStdString().c_str(), end.size(), SQLITE_TRANSIENT);
        result = ask(statement);
    }

    check_for_error();

    return result;
}


// Returns the given value what from the settings-table
QString Database::settings_search(const QString& what)
{

    sqlite3_stmt* statement;
    vector<vector<QString> > result;
    const char* query;

    if (what == "open_hour")
    {
        query = "SELECT open_hour FROM Settings WHERE id = 1";
    }
    else if (what == "close_hour")
    {
        query = "SELECT close_hour FROM Settings WHERE id = 1";
    }
    else if (what == "open_min")
    {
        query = "SELECT open_min FROM Settings WHERE id = 1";
    }
    else if (what == "close_min")
    {
        query = "SELECT close_min FROM Settings WHERE id = 1";
    }
    else if (what == "min_rental")
    {
        query = "SELECT min_rental FROM Settings WHERE id = 1";
    }
    else
    {
        throw database_error("Invalid what argument to vehicle_search in db!");
    }

    if (sqlite3_prepare_v2(db, query, -1, &statement,0) == SQLITE_OK)
    {
        result = ask(statement);
    }

    check_for_error();
    if (result.empty())
        return "";
    else
        return result[0][0];

}

// Returns true if reservations already is in database
bool Database::exists_reservation(int res_nr)
{
    vector<vector<QString> > search_vector;
    search_vector = reservation_search(res_nr);

    if(search_vector.empty())
        return false;
    else
        return true;

}


// Returns true if reservations already is in database
bool Database::exists_vehicle(QString& reg_nr)
{
    vector<vector<QString> > search_vector;
    search_vector = vehicle_search("reg_nr", reg_nr);

    if(search_vector.empty())
        return false;
    else
        return true;

}


// Removes given reservation
void Database::remove_reservation(int res_nr)
{
    sqlite3_stmt* statement;
    const char* query = "DELETE FROM Reservations WHERE res_nr = ?1";

    if (sqlite3_prepare_v2(db, query, -1, &statement, 0) == SQLITE_OK)
    {
        sqlite3_bind_int(statement, 1, res_nr);
        sqlite3_step(statement);
    }

    sqlite3_finalize(statement);
    check_for_error();
}


// Removes given vehicle
void Database::remove_vehicle(QString& reg_nr)
{
    sqlite3_stmt* statement;
    const char* query = "DELETE FROM Vehicles WHERE reg_nr = ?1";

    if (sqlite3_prepare_v2(db, query, -1, &statement, 0) == SQLITE_OK)
    {
        sqlite3_bind_text(statement, 1, reg_nr.toStdString().c_str(), reg_nr.size(), SQLITE_TRANSIENT);
        sqlite3_step(statement);
    }

    sqlite3_finalize(statement);
    check_for_error();
}

// Erases all reservations and vehicles from the database
void Database::erase_all()
{
    sqlite3_exec(db,
                 "DELETE FROM Reservations",
                 NULL, 0, NULL);
    check_for_error();

    sqlite3_exec(db,
                 "DELETE FROM Vehicles",
                 NULL, 0, NULL);
    check_for_error();

}

// Initializes the database if not already done.
void Database::init_db()
{
    sqlite3_exec(db,
                 "CREATE TABLE IF NOT EXISTS Reservations ("
                 "res_nr INTEGER NOT NULL UNIQUE, reg_nr TEXT COLLATE NOCASE,"
                 "start TEXT, end TEXT, status TEXT, name TEXT COLLATE NOCASE,"
                 "tel TEXT, address TEXT COLLATE NOCASE, postal_nr TEXT,"
                 "city TEXT COLLATE NOCASE)", NULL, 0, NULL);
    check_for_error();

    sqlite3_exec(db,
                 "CREATE TABLE IF NOT EXISTS Vehicles ("
                 "reg_nr TEXT NOT NULL UNIQUE, type TEXT, status TEXT,"
                 "brand TEXT COLLATE NOCASE, model TEXT COLLATE NOCASE,"
                 "mileage INTEGER, damage TEXT)", NULL, 0, NULL);
    check_for_error();

    sqlite3_exec(db,
                 "CREATE TABLE IF NOT EXISTS Settings ("
                 "open_hour INTEGER, open_min INTEGER, close_hour INTEGER, close_min INTEGER,"
                 "min_rental INTEGER, id INTEGER NOT NULL UNIQUE)",
                 NULL, 0, NULL);

    check_for_error();
}


// Prepares and binds given QString to ?1 in the query
sqlite3_stmt* Database::bind_QString(const char* query, const QString& value)
{
    sqlite3_stmt* statement;
    if (sqlite3_prepare_v2(db, query, -1, &statement,0) == SQLITE_OK)
    {
        sqlite3_bind_text(statement, 1, value.toStdString().c_str(), value.size(), SQLITE_TRANSIENT);
    }
    else
    {
        check_for_error();
    }

    return statement;
}

// Asks the prepared statement to the database. Returns a vector with
// the all the rows of the result, where each row consits of a vector with
// each column as an element.
vector<vector<QString> > Database::ask(sqlite3_stmt* statement)
{
    vector<vector<QString> > results;

    int cols = sqlite3_column_count(statement);
    int result = 0;

    while(true)
    {
        result = sqlite3_step(statement);

        if(result == SQLITE_ROW)
        {
            vector<QString> values;
            QString val;

            for(int col = 0; col < cols; col++)
            {
                char * ptr = (char*)sqlite3_column_text(statement, col);

                if(ptr)
                    val = ptr;
                else
                    val = "NULL";

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
    return results;
}


// Checks if the database has an error
void Database::check_for_error()
{
    string error = sqlite3_errmsg(db);
    if(error != "not an error")
        throw database_error(error);
}
