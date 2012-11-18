/*
* FILENAMN:    Reservation.cc
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

#include "Reservation.h"
#include "Database.h"

using namespace std;

/////////////////////////////////////////////////////////////////////
// Reservation:
/////////////////////////////////////////////////////////////////////
// parameterized constructor
Reservation::
Reservation(int res_nr, string& reg_nr, string& name,
            string& tel, string& adress, string& postal_nr, 
            string& city, string& status, string& start_,
            string& end_)
            : res_nr_(res_nr), reg_nr_(reg_nr), name_(name), 
              tel_(tel), adress_(adress), postal_nr_(postal_nr), 
              city_(city), status_(status), 
              start_(start_), end_(end_)
{}

// Store the current object in the database.
void 
Reservation::
save()
{
   Database::reservation_update(res_nr_, reg_nr_, start_, end_, status_, name_, 
                                tel_, adress_, postal_nr_, city_);
}

// Apply changes of the parameters.
void 
Reservation::
set_res_nr(const int res_nr)
{
   res_nr_ = res_nr;
}

void 
Reservation::
set_reg_nr(const string& reg_nr)
{
   reg_nr_ = reg_nr;
}
void 
Reservation::
set_name(const string& name)
{
   name_ = name;
}

void 
Reservation::
set_tel(const string& tel)
{
   tel_ = tel;
}

void 
Reservation::
set_adress(const string& adress)
{
   adress_ = adress;
}

void 
Reservation::
set_postal_nr(const string& postal_nr)
{
   postal_nr_ = postal_nr;
}

void 
Reservation::
set_city(const string& city)
{
   city_ = city;
}

void 
Reservation::
set_status(const string& status)
{
   status_ = status;
}

void 
Reservation::
set_start(const string& start)
{
   start_ = start;
}

void 
Reservation::
set_end(const string& end)
{
   end_ = end;
}

// Return a specific parameter.
int
Reservation::
get_res_nr() const
{
   return res_nr_;
}

string 
Reservation::
get_reg_nr() const
{
   return reg_nr_;
}

string 
Reservation::
get_name() const
{
   return name_;
}

string
Reservation::
get_tel() const
{
   return tel_;
}

string 
Reservation::
get_adress() const
{
   return adress_;
}

string 
Reservation::
get_postal_nr() const
{
   return postal_nr_;
}

string 
Reservation::
get_city() const
{
   return city_;
}

string 
Reservation::
get_status() const
{
   return status_;
}

string 
Reservation::
get_start() const
{
   return start_;
}

string 
Reservation::
get_end() const
{
   return end_;
}
