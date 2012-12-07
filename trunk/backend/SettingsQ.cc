/*
* FILENAMN:    Settings.cc
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-10-18
*
* DESCRIPTION
* 
* Defination av the settings class and it's functions.
*
* Created by:
* Conny: All
*/

#include "SettingsQ.h"

using namespace std;

/////////////////////////////////////////////////////////////////////
// Settings:
/////////////////////////////////////////////////////////////////////
// Store the current object in the database.
void 
Settings::
save()
{
   Database::settings_update(open_hour_, open_min_, close_hour_, close_min_, min_rental_);
}

// Update the current object from information from the database.
void
Settings::
update()
{
    QString open_hour  = Database::settings_search("open_hour");
    QString open_min   = Database::settings_search("open_min");
    QString close_hour = Database::settings_search("close_hour");
    QString close_min  = Database::settings_search("close_min");
    QString min_rental = Database::settings_search("min_rental");

    if(open_hour.isEmpty())
        open_hour_ = 0;
    else
        open_hour_ = open_hour.toInt();

    if(open_min.isEmpty())
        set_open_min(0);
    else
        set_open_min(open_min.toInt());

    if(close_hour.isEmpty())
        set_close_hour(0);
    else
        set_close_hour(close_hour.toInt());

    if(close_min.isEmpty())
        set_close_min(0);
    else
        set_close_min(close_min.toInt());

    if(min_rental.isEmpty())
        set_min_rental(0);
    else
        set_min_rental(min_rental.toInt());
}

// Clean the database of all information except the settings.
void
Settings::
clean_db()
{
    Database::erase_all();
}

// Apply changes of the parameters.
void
Settings::
set_open_hour(const int open_hour)
{
    open_hour_ = open_hour;
}

void
Settings::
set_open_min(const int open_min)
{
    open_min_ = open_min;
}

void 
Settings::
set_close_hour(const int close_hour)
{
    close_hour_ = close_hour;
}

void
Settings::
set_close_min(const int close_min)
{
    close_min_ = close_min;
}

void 
Settings::
set_min_rental(const int min_rental)
{
    min_rental_ = min_rental;
}

// Return a specific parameter.
int 
Settings::
get_open_hour() const
{
    return open_hour_;
}

int
Settings::
get_open_min() const
{
    return open_min_;
}

int 
Settings::
get_close_hour() const
{
    return close_hour_;
}

int
Settings::
get_close_min() const
{
    return close_min_;
}

int 
Settings::
get_min_rental() const
{
    return min_rental_;
}
