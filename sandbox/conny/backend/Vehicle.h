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

#include <string>
#include <stdexcept>

/////////////////////////////////////////////////////////////////////
// Vehicle:
/////////////////////////////////////////////////////////////////////
class Vehicle
{
public:
   Vehicle(int, std::string&, std::string&, std::string&, 
           std::string&, std::string&, std::string&);
   ~Vehicle() = default;
   
   //void save();
   
   void set_mileage(const int);
   void set_reg_nr(const std::string&);
   void set_type(const std::string&);
   void set_status(const std::string&);
   void set_brand(const std::string&);
   void set_model(const std::string&);
   void set_damage(const std::string&);

   int         get_mileage() const;
   std::string get_reg_nr()  const;
   std::string get_type()    const;
   std::string get_status()  const;
   std::string get_brand()   const;
   std::string get_model()   const;
   std::string get_damage()  const;

private:
   Vehicle()                          = delete;
   Vehicle(const Vehicle&)            = delete;
   Vehicle(Vehicle&&)                 = delete;

   Vehicle& operator=(const Vehicle&) = delete;
   Vehicle& operator=(Vehicle&&)      = delete;   
   
   int         mileage_;
   std::string reg_nr_;
   std::string type_;
   std::string status_; 
   std::string brand_;
   std::string model_;
   std::string damage_; 
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
