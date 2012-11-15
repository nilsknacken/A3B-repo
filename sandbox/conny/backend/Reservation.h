/*
* FILENAMN:    Reservation.h
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-10-12
*
* DESCRIPTION
* 
* ///////////////Programbeskrivning
*/

#ifndef RESERVATION
#define RESERVATION

#include <string>

/////////////////////////////////////////////////////////////////////
// Reservation:
/////////////////////////////////////////////////////////////////////
class Reservation
{
public:
   Reservation();
   Reservation(Reservation&);
   Reservation(Reservation&&);
   ~Reservation();
   
   void        save();
   
   void        set_res_nr(int);
   void        set_reg_nr(std::string&);
   void        set_name(std::string&);
   void        set_tel(std::string&);
   void        set_adress(std::string&);
   void        set_postal_nr(std::string&);
   void        set_city(std::string&);
   void        set_status(std::string&);
   void        set_start_time(int);
   void        set_end_time(int);
   void        set_start_date(int);
   void        set_end_date(int);
   
   int         get_res_nr();
   std::string get_reg_nr();
   std::string get_name();
   std::string get_tel();
   std::string get_adress();
   std::string get_postal_nr();
   std::string get_city();
   std::string get_status();
   int         get_start_time();
   int         get_end_time();
   int         get_start_date();
   int         get_end_date();

private:
   int res_nr;
   std::string reg_nr
   std::string name
   std::string tel
   std::string adress
   std::string postal_nr
   std::string city
   std::string status
   int start_time
   int end_time
   int start_date
   int end_date
};

#endif
