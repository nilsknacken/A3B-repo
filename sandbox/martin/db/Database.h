/*
* Filename:    Database.h
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-10-12
*
* DESCRIPTION:
* 
* Handles permanent storage of data in the system.
* SQlite3 is used as databse.
*/

#ifndef DATABASE_H_
#define DATABASE_H_

#include <string>
#include <vector>
#include <stdexcept>
#include "sqlite3.h"


// Error to be thrown in database
class database_error : public std::logic_error
{
public:
   explicit database_error(const std::string& what_arg) noexcept
      : logic_error(what_arg) {}

   explicit database_error(const char* what_arg) noexcept
      : logic_error(what_arg) {}
};


class Database
{
public:
   Database() = delete;
   ~Database() = delete;
   
   static bool open(const char*);
   static void close();

   static void reservation_update(const int,
                                  const std::string&,
                                  const std::string&,
                                  const std::string&,
                                  const std::string&,
                                  const std::string&,
                                  const std::string&,
                                  const std::string&,
                                  const std::string&,
                                  const std::string&);

   static void vehicle_update(const std::string&,
                              const std::string&,
                              const std::string&,
                              const std::string&,
                              const std::string&,
                              const int,
                              const std::string&);
      
  static void settings_update(const int, const int, const int);

   static
   std::vector<std::vector<std::string>>
   reservation_search(const std::string&, const std::string&);

   static
   std::vector<std::vector<std::string>>
   reservation_search(const int);

   static
   std::vector<std::vector<std::string>>
   reservation_search_date(const std::string&, const std::string&);

   static
   std::vector<std::vector<std::string>>
   vehicle_search(const std::string&, const std::string&);

   static
   std::vector<std::vector<std::string>>
   vehicle_search(const std::string&, const std::string&, const std::string&);

   static 
   std::string
   settings_search(const std::string&);

   static bool exists_reservation(int);
   static bool exists_vehicle(std::string&);
   static void remove_reservation(int);
   static void remove_vehicle(std::string& reg_nr);
   
   static void display(std::vector<std::vector<std::string>>); // used for testing
  
   
private:
   static sqlite3* db;

   static void init_db();

   static sqlite3_stmt* bind_string(const char*, const std::string&);
   
   static std::vector<std::vector<std::string>> ask(sqlite3_stmt*);

   static void check_for_error();

};



#endif

