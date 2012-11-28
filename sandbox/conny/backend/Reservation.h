/*
* FILENAMN:    Reservation.h
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-10-18
*
* DESCRIPTION
* 
* The reservation class, uses as a connection between the database and the GUI.
*/

#ifndef RESERVATION
#define RESERVATION

#include <string>
#include <stdexcept>

/////////////////////////////////////////////////////////////////////
// Reservation:
/////////////////////////////////////////////////////////////////////
class Reservation
{
public:
   Reservation(int, std::string&, std::string&,
               std::string&, std::string&, std::string&, 
               std::string&, std::string&, std::string&, 
               std::string&);
   Reservation(const Reservation&)            = default;
   Reservation(Reservation&&)                 = default;
   ~Reservation()                             = default;
   
   Reservation& operator=(const Reservation&) = default;
   Reservation& operator=(Reservation&&)      = default;
   
   void        save();
   
   void        set_res_nr(const int);
   void        set_reg_nr(const std::string&);
   void        set_name(const std::string&);
   void        set_tel(const std::string&);
   void        set_adress(const std::string&);
   void        set_postal_nr(const std::string&);
   void        set_city(const std::string&);
   void        set_status(const std::string&);
   void        set_start(const std::string&);
   void        set_end(const std::string&);
   
   int         get_res_nr()    const;
   std::string get_reg_nr()    const;
   std::string get_name()      const;
   std::string get_tel()       const;
   std::string get_adress()    const;
   std::string get_postal_nr() const;
   std::string get_city()      const;
   std::string get_status()    const;
   std::string get_start()     const;
   std::string get_end()       const;

private:
   Reservation() = delete;
   
   void correct_reg_nr(const std::string&);
   void correct_name(const std::string&);
   void correct_tel(const std::string&);
   void correct_adress(const std::string&);
   void correct_postal_nr(const std::string&);
   void correct_city(const std::string&);
   void correct_time(const std::string&, const std::string&);

   
   int         res_nr_;
   std::string reg_nr_;
   std::string start_;
   std::string end_;
   std::string status_;
   std::string name_;
   std::string tel_;
   std::string adress_;
   std::string postal_nr_;
   std::string city_; 
};

// Help functions
Reservation* 
make_reservation(std::string&, std::string&, std::string&, 
                 std::string&, std::string&, std::string&,
                 std::string&, std::string&);


// Reservation's error class
class reservation_error : public std::logic_error
{
public:
   explicit reservation_error(const std::string& what_arg) noexcept
      : logic_error(what_arg) {}

   explicit reservation_error(const char* what_arg) noexcept
      : logic_error(what_arg) {}
};

#endif
