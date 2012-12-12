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
* Defination av the reservation class and it's functions.
*
* Created by:
* Conny: All
*/

#include <cctype>
#include <cstdlib>
#include <QChar>

#include "ReservationQ.h"

using namespace std;

/////////////////////////////////////////////////////////////////////
// Reservation:
/////////////////////////////////////////////////////////////////////
// parameterized constructor
Reservation::
Reservation(int res_nr, QString& reg_nr, QString& start, QString& end,
            QString& status, QString& name, QString& tel,
            QString& adress, QString& postal_nr, QString& city)
    : res_nr_(res_nr), reg_nr_(reg_nr), start_(start),
      end_(end), status_(status), name_(name), tel_(tel),
      adress_(adress), postal_nr_(postal_nr), city_(city)

{
    //Throw if parameter is incorrect.
    correct_reg_nr(reg_nr);
    correct_status(status);
    correct_name(name);
    correct_tel(tel);
    correct_postal_nr(postal_nr);
    correct_city(city);
}

// Store the current object in the database.
void 
Reservation::
save()
{
    Database::reservation_update(res_nr_, reg_nr_, start_,
                                 end_, status_, name_, tel_,
                                 adress_, postal_nr_, city_);
}

// Remove the current object from the database.
void
Reservation::
remove()
{
    Database::remove_reservation(res_nr_);
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
set_reg_nr(const QString& reg_nr)
{
    correct_reg_nr(reg_nr);

    reg_nr_ = reg_nr;
}
void 
Reservation::
set_name(const QString& name)
{
    correct_name(name);

    name_ = name;
}

void 
Reservation::
set_tel(const QString& tel)
{
    correct_tel(tel);

    tel_ = tel;
}

void 
Reservation::
set_adress(const QString& adress)
{
    adress_ = adress;
}

void 
Reservation::
set_postal_nr(const QString& postal_nr)
{
    correct_postal_nr(postal_nr);

    postal_nr_ = postal_nr;
}

void 
Reservation::
set_city(const QString& city)
{
    correct_city(city);

    city_ = city;
}

void 
Reservation::
set_status(const QString& status)
{
    correct_status(status);

    status_ = status;
}

void 
Reservation::
set_start(const QString& start)
{  
    start_ = start;
}

void 
Reservation::
set_end(const QString& end)
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

QString 
Reservation::
get_reg_nr() const
{
    return reg_nr_;
}

QString 
Reservation::
get_name() const
{
    return name_;
}

QString
Reservation::
get_tel() const
{
    return tel_;
}

QString 
Reservation::
get_adress() const
{
    return adress_;
}

QString 
Reservation::
get_postal_nr() const
{
    return postal_nr_;
}

QString 
Reservation::
get_city() const
{
    return city_;
}

QString 
Reservation::
get_status() const
{
    return status_;
}

QString 
Reservation::
get_start() const
{
    return start_;
}

QString 
Reservation::
get_end() const
{
    return end_;
}

// Correct indata?
void 
Reservation::
correct_reg_nr(const QString& reg_nr)
{   
    if(reg_nr.size() != 6)
        throw reservation_error("Reg nr. får ändast innehålla tre bokstäver "
                                "följt av tre siffror");

    for(int i = 0; i < reg_nr.size(); i++)
    {
        QChar qc = reg_nr[i];

        if(i < 3)
        {
            if(! qc.isLetter())
                throw reservation_error("Reg nr. får ändast innehålla tre bokstäver"
                                        " följt av tre siffror");
        }
        if(i >= 3)
        {
            if(! qc.isDigit())
                throw reservation_error("Reg nr. får ändast innehålla tre bokstäver "
                                        "följt av tre siffror");
        }
    }
}

void
Reservation::
correct_status(const QString& status)
{
    if((status != "aktiv")       &&
            (status != "kommande") &&
            (status != "avslutad"))
        throw reservation_error("Status får ändast vara: aktiv, kommande, "
                                "avslutad.");
}

void 
Reservation::
correct_name(const QString& name)
{    
    unsigned int count_space = 0;
    unsigned int count_alpha = 0;

    for(int i = 0; i < name.size(); i++)
    {
        QChar qc = name[i];

        if((i == name.size() - 1) && ! count_space)
            throw reservation_error("Namn får endast innehålla bokstäver, "
                                    "och för- och efternamn ska ingå.");

        if(qc == ' ' && count_alpha)
            count_space++;

        else if(qc.isLetter())
            count_alpha++;

        else
            throw reservation_error("Namn får endast innehålla bokstäver, "
                                    "och för- och efternamn ska ingå.");
    }
    if(count_space == 0)
        throw reservation_error("Namn får endast innehålla bokstäver, "
                                "och för- och efternamn ska ingå.");
}

void 
Reservation::
correct_tel(const QString& tel)
{
    for(int i = 0; i < tel.size(); i++)
    {
        QChar qc = tel[i];

        if(! qc.isDigit() && qc != ' ')
            throw reservation_error("Felaktigt telefonnummer, "
                                    "ska bara innehålla siffror.");
    }
}

void
Reservation::
correct_postal_nr(const QString& postal_nr)
{
    int count_digit = 0;
    unsigned int count_space = 0;

    for(int i = 0; i < postal_nr.size(); i++)
    {
        QChar qc = postal_nr[i];

        if(qc.isDigit())
            count_digit++;
        else if(qc == ' ')
            count_space++;
        else
            throw reservation_error("Postnummer får endast innehålla "
                                    "siffror och ha längden 5.");
    }
    if((count_digit != 5) || (count_space > 1))
        throw reservation_error("Postnummer får endast innehålla "
                                "siffror och ha längden 5.");

}

void
Reservation::
correct_city(const QString& city)
{
    for(int i = 0; i < city.size(); i++)
    {
        QChar qc = city[i];

        if(! qc.isLetter())
            throw reservation_error("Felaktigt stad, "
                                    "ska bara innehålla bokstäver.");
    }
}

/////////////////////////////////////////////////////////////////////
// Help functions:
/////////////////////////////////////////////////////////////////////

Reservation* 
make_reservation(QString& reg_nr,    QString& start, QString& end, 
                 QString& name,      QString& tel,   QString& adress,
                 QString& postal_nr, QString& city)
{
    QString status = "kommande";
    int min_ = 10000;
    int max_ = 99999;
    int res_nr;

    do
    {
        res_nr = (rand()%(max_ - min_)) + min_;
    }
    while(Database::exists_reservation(res_nr));

    Reservation* temp = NULL;
    try
    {
        temp = new Reservation(res_nr, reg_nr, start, end, status,
                               name, tel, adress, postal_nr, city);
    }
    catch(const bad_alloc& ba)
    {
        delete temp;
    }

    return temp;
}

