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

#include <cctype>
#include <cstdlib>
#include <iostream> //!!!!!!!!!!!!!!!!!!!!!!!

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
   correct_time(start, end);
   correct_name(name);
   correct_tel(tel);
   correct_adress(adress);
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
   reg_nr_ = reg_nr;
}
void 
Reservation::
set_name(const QString& name)
{
   name_ = name;
}

void 
Reservation::
set_tel(const QString& tel)
{
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
   postal_nr_ = postal_nr;
}

void 
Reservation::
set_city(const QString& city)
{
   city_ = city;
}

void 
Reservation::
set_status(const QString& status)
{
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
       char c = reg_nr.toStdString()[i];
      
      if(i < 3)
      {
         if(! isalpha(c))
            throw reservation_error("Reg nr. får ändast innehålla tre bokstäver"
                                    " följt av tre siffror");
      }
      if(i >= 3)
      {
         if(! isdigit(c))
            throw reservation_error("Reg nr. får ändast innehålla tre bokstäver "
                                    "följt av tre siffror");
      }
   }
}

void 
Reservation::
correct_name(const QString& name)
{
   unsigned int count_space = 0;
   for(int i = 0; i < name.size(); i++)
   {
      char c = name.toStdString()[i];
      
      if(c == ' ')
         count_space++;
      else if(! isalpha(c))
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
      char c = tel.toStdString()[i];
      
      if(! isdigit(c) && ! (c == ' '))
         throw reservation_error("Felaktigt telefonnummer, "
                                 "ska bara innehålla siffror.");
   }
}

void 
Reservation::
correct_adress(const QString& adress)
{
   (void)adress;
   // Kan utökas vid behov.
}

void
Reservation::
correct_postal_nr(const QString& postal_nr)
{
   int count_digit = 0;
   unsigned int count_space = 0;
   
   for(int i = 0; i < postal_nr.size(); i++)
   {
      char c = postal_nr.toStdString()[i];
      
      if(isdigit(c))
         count_digit++;
      else if(c == ' ')
         count_space++;
      else
         throw reservation_error("Postnummer får endast innehålla "
                                 "siffror och ha längden 5.");
   }
   if((! count_digit == 5) &&
      (! count_space <= 1))
      throw reservation_error("Postnummer får endast innehålla "
                              "siffror och ha längden 5.");
      
}

void
Reservation::
correct_city(const QString& city)
{
      for(int i = 0; i < city.size(); i++)
   {
      char c = city.toStdString()[i];
      
      if(! isalpha(c))
         throw reservation_error("Felaktigt stad, "
                                 "ska bara innehålla bokstäver.");
   }
}

void
Reservation::
correct_time(const QString& start, const QString& end)
{
   (void)start;
   (void)end;
   // Kolla så GUI håller koll på detta!
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
   //while(false);
   while(Database::exists_reservation(res_nr));
   
   return new Reservation(res_nr, reg_nr, start, end, status,
                          name, tel, adress, postal_nr, city);
}

