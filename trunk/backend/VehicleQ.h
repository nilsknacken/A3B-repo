/*
* FILENAMN:    Vehicle.h
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

#ifndef VEHICLE
#define VEHICLE

#include <QString>
#include <stdexcept>
#include "DatabaseQ.h"

/////////////////////////////////////////////////////////////////////
// Vehicle:
/////////////////////////////////////////////////////////////////////
class Vehicle
{
public:
    Vehicle(QString&, QString&, QString&,
            QString&, QString&, int, QString&);
    Vehicle() = default;

    ~Vehicle() = default;

    void save();

    void set_mileage(const int);
    void set_reg_nr(const QString&);
    void set_type(const QString&);
    void set_status(const QString&);
    void set_brand(const QString&);
    void set_model(const QString&);
    void set_damage(const QString&);

    int     get_mileage() const;
    QString get_reg_nr()  const;
    QString get_type()    const;
    QString get_status()  const;
    QString get_brand()   const;
    QString get_model()   const;
    QString get_damage()  const;

private:
    Vehicle(const Vehicle&)            = delete;
    Vehicle(Vehicle&&)                 = delete;

    Vehicle& operator=(const Vehicle&) = delete;
    Vehicle& operator=(Vehicle&&)      = delete;

    void correct_reg_nr(const QString&);
    void correct_type(const QString&);
    void correct_status(const QString&);
    void correct_mileage(const int);

    QString reg_nr_;
    QString type_;
    QString status_;
    QString brand_;
    QString model_;
    int     mileage_;
    QString damage_;
};

// Error to be thrown in Search_vehicleehicle
class vehicle_error : public std::logic_error
{
public:
    explicit vehicle_error(const std::string& what_arg) noexcept
        : logic_error(what_arg) {}

    explicit vehicle_error(const char* what_arg) noexcept
        : logic_error(what_arg) {}
};

#endif
