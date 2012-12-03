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
* ///////////////Programbeskrivning
*/

#include <iostream>
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
