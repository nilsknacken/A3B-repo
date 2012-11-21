/*
* FILENAMN:    Vehicle.cc
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

#include <string>

#include "Database.h"
#include "Vehicle.h"

using namespace std;

/////////////////////////////////////////////////////////////////////
// Vehicle:
/////////////////////////////////////////////////////////////////////
// parameterized constructor
Vehicle::
Vehicle(std::string& reg_nr, std::string& type, 
        std::string& status, std::string& brand, std::string& model, 
        int mileage, std::string& damage)
         : reg_nr_(reg_nr), type_(type),
         status_(status), brand_(brand), model_(model),
         mileage_(mileage), damage_(damage)
{}
         

// Store the current object in the database.
void
Vehicle::
save()
{
   Database::vehicle_update(reg_nr_, type_, status_, 
                            brand_, model_, mileage_, damage_);
}


// Apply changes of the parameters.
void 
Vehicle::
set_mileage(const int mileage)
{
   mileage_ = mileage;
}

void 
Vehicle::
set_reg_nr(const string& reg_nr)
{
   reg_nr_ = reg_nr;
}

void 
Vehicle::
set_type(const string& type)
{
   type_ = type;
}

void 
Vehicle::
set_status(const string& status)
{
   status_ = status;
}

void 
Vehicle::
set_brand(const string& brand)
{
   brand_ = brand;
}

void 
Vehicle::
set_model(const string& model)
{
   model_ = model;
}

void 
Vehicle::
set_damage(const string& damage)
{
   damage_ = damage;
}

// Return a specific parameter.
int 
Vehicle::
get_mileage() const
{
   return mileage_;
}

string 
Vehicle::
get_reg_nr() const
{
   return reg_nr_;
}

string 
Vehicle::
get_type() const
{
   return type_;
}

string 
Vehicle::
get_status() const
{
   return status_;
}

string 
Vehicle::
get_brand() const
{
   return brand_;
}

string 
Vehicle::
get_model() const
{
   return model_;
}

string 
Vehicle::
get_damage() const
{
   return damage_;
}

