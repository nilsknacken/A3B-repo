/*
* FILENAMN:    Vehicle.h
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

#ifndef VEHICLE
#define VEHICLE

#include <string>

/////////////////////////////////////////////////////////////////////
// Vehicle:
/////////////////////////////////////////////////////////////////////
class Vehicle
{
public:
   Vehicle(int, std::string&, std::string&, std::string&, 
           std::string&, std::string&, std::string&);
   ~Vehicle();
   
   void save();
   
   void set_mileage(int);
   void set_reg_nr(std::string&);
   void set_type(std::string&);
   void set_status(std::string&);
   void set_brand(std::string&);
   void set_model(std::string&);
   void set_damage(std::string&);

   int get_mileage();
   std::string get_reg_nr();
   std::string get_type();
   std::string get_status();
   std::string get_brand();
   std::string get_model();
   std::string get_damage();

private:
   int         mileage;
   std::string reg_nr;
   std::string type;
   std::string status; 
   std::string brand;
   std::string model;
   std::string damage; 
};

#endif
