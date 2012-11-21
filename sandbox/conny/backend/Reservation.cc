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

#include "Reservation.h"
#include "Database.h"

using namespace std;

/////////////////////////////////////////////////////////////////////
// Reservation:
/////////////////////////////////////////////////////////////////////
// parameterized constructor
Reservation::
Reservation(int res_nr, string& reg_nr, string& start, string& end,
            string& status, string& name, string& tel, 
            string& adress, string& postal_nr, string& city)
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

// Correct indata?
void 
Reservation::
correct_reg_nr(const string& reg_nr)
{   
   if(reg_nr.size() != 6)
      throw reservation_error("Reg nr. f�r �ndast inneh�lla tre bokst�ver "
                                    "f�ljt av tre siffror");
   
   for(unsigned int i = 0; i < reg_nr.size(); i++)
   {
      char c = reg_nr.at(i);
      
      if(i < 3)
      {
         if(! isalpha(c))
            throw reservation_error("Reg nr. f�r �ndast inneh�lla tre bokst�ver"
                                    " f�ljt av tre siffror");
      }
      if(i >= 3)
      {
         if(! isdigit(c))
            throw reservation_error("Reg nr. f�r �ndast inneh�lla tre bokst�ver "
                                    "f�ljt av tre siffror");
      }
   }
}

void 
Reservation::
correct_name(const string& name)
{
   unsigned int count_space = 0;
   for(unsigned int i = 0; i < name.size(); i++)
   {
      char c = name.at(i);
      
      if(c == ' ')
         count_space++;
      else if(! isalpha(c))
         throw reservation_error("Namn f�r endast inneh�lla bokst�ver, "
                                 "och f�r- och efternamn ska ing�.");
   }
   if(count_space == 0)
      throw reservation_error("Namn f�r endast inneh�lla bokst�ver, "
                              "och f�r- och efternamn ska ing�.");
}

void 
Reservation::
correct_tel(const string& tel)
{
   for(unsigned int i = 0; i < tel.size(); i++)
   {
      char c = tel.at(i);
      
      if(! isdigit(c) && ! (c == ' '))
         throw reservation_error("Felaktigt telefonnummer, "
                                 "ska bara inneh�lla siffror.");
   }
}

void 
Reservation::
correct_adress(const string& adress)
{
   (void)adress;
   // Kan ut�kas vid behov.
}

void
Reservation::
correct_postal_nr(const string& postal_nr)
{
   int count_digit = 0;
   unsigned int count_space = 0;
   
   for(unsigned int i = 0; i < postal_nr.size(); i++)
   {
      char c = postal_nr.at(i);
      
      if(isdigit(c))
         count_digit++;
      else if(c == ' ')
         count_space++;
      else
         throw reservation_error("Postnummer f�r endast inneh�lla "
                                 "siffror och ha l�ngden 5.");
   }
   if((! count_digit == 5) &&
      (! count_space <= 1))
      throw reservation_error("Postnummer f�r endast inneh�lla "
                              "siffror och ha l�ngden 5.");
      
}

void
Reservation::
correct_city(const string& city)
{
      for(unsigned int i = 0; i < city.size(); i++)
   {
      char c = city.at(i);
      
      if(! isalpha(c))
         throw reservation_error("Felaktigt stad, "
                                 "ska bara inneh�lla bokst�ver.");
   }
}

void
Reservation::
correct_time(const string& start, const string& end)
{
   (void)start;
   (void)end;
   // Kolla s� GUI h�ller koll p� detta!
}

/////////////////////////////////////////////////////////////////////
// Help functions:
/////////////////////////////////////////////////////////////////////

Reservation* 
make_reservation(string& reg_nr,    string& start, string& end, 
                 string& name,      string& tel,   string& adress, 
                 string& postal_nr, string& city)
{
   string status = "kommande";
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
