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

#include <QString>

#include "VehicleQ.h"

using namespace std;

/////////////////////////////////////////////////////////////////////
// Vehicle:
/////////////////////////////////////////////////////////////////////
// parameterized constructor
Vehicle::
Vehicle(QString& reg_nr, QString& type,
        QString& status, QString& brand, QString& model,
        int mileage, QString& damage)
    : reg_nr_(reg_nr), type_(type),
      status_(status), brand_(brand), model_(model),
      mileage_(mileage), damage_(damage)
{
    correct_reg_nr(reg_nr);
    correct_type(type);
    correct_status(status);
    correct_mileage(mileage);
}


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
set_reg_nr(const QString& reg_nr)
{
    reg_nr_ = reg_nr;
}

void 
Vehicle::
set_type(const QString& type)
{
    type_ = type;
}

void 
Vehicle::
set_status(const QString& status)
{
    status_ = status;
}

void 
Vehicle::
set_brand(const QString& brand)
{
    brand_ = brand;
}

void 
Vehicle::
set_model(const QString& model)
{
    model_ = model;
}

void 
Vehicle::
set_damage(const QString& damage)
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

QString 
Vehicle::
get_reg_nr() const
{
    return reg_nr_;
}

QString 
Vehicle::
get_type() const
{
    return type_;
}

QString 
Vehicle::
get_status() const
{
    return status_;
}

QString 
Vehicle::
get_brand() const
{
    return brand_;
}

QString 
Vehicle::
get_model() const
{
    return model_;
}

QString 
Vehicle::
get_damage() const
{
    return damage_;
}

// Correct indata?
void
Vehicle::
correct_reg_nr(const QString& reg_nr)
{
    if(reg_nr.size() != 6)
        throw vehicle_error("Reg nr. får endast innehålla tre bokstäver "
                                "följt av tre siffror");

    for(int i = 0; i < reg_nr.size(); i++)
    {
        char c = reg_nr.toStdString()[i];

        if(i < 3)
        {
            if(! isalpha(c))
                throw vehicle_error("Reg nr. får endast innehålla tre bokstäver"
                                        " följt av tre siffror");
        }
        if(i >= 3)
        {
            if(! isdigit(c))
                throw vehicle_error("Reg nr. får endast innehålla tre bokstäver "
                                        "följt av tre siffror");
        }
    }
}

void
Vehicle::
correct_type(const QString& type)
{
    if((type != "Liten bil")       &&
            (type != "Mellanbil") &&
            (type != "Stor bil") &&
            (type != "Liten lastbil") &&
            (type != "Stor lastbil"))
        throw vehicle_error("Typ får endast vara: Liten bil, Mellanbil, "
                            "Stor_bil, Liten lastbil, Stor lastbil.");
}

void
Vehicle::
correct_status(const QString& status)
{
    if((status != "uthyrd") &&
            (status != "ledig"))
        throw vehicle_error("Status får endast vara: uthyrd, ledig.");
}

void
Vehicle::
correct_mileage(const int mileage)
{
    if(mileage < 0)
        throw vehicle_error("Trippmätaren får endast ha positiva värden");
}

