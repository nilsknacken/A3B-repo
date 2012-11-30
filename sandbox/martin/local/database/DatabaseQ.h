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

#include <QString>
#include <vector>
#include <stdexcept>
#include "sqlite3.h"


// Error to be thrown in database
class database_error : public std::logic_error
{
public:
   explicit database_error(const std::string& what_arg) :
        logic_error(what_arg) {}

   explicit database_error(const char* what_arg) :
        logic_error(what_arg) {}
};


class Database
{
public:
   Database() = delete;
   ~Database() = delete;
   
   static bool open(const char*);
   static void close();

   static void reservation_update(const int,
                                  const QString&,
                                  const QString&,
                                  const QString&,
                                  const QString&,
                                  const QString&,
                                  const QString&,
                                  const QString&,
                                  const QString&,
                                  const QString&);

   static void vehicle_update(const QString&,
                              const QString&,
                              const QString&,
                              const QString&,
                              const QString&,
                              const int,
                              const QString&);
      
  static void settings_update(const int,
                              const int,
                              const int,
                              const int,
                              const int);

   static
   std::vector<std::vector<QString> >
   reservation_search(const QString&, const QString&);

   static
   std::vector<std::vector<QString> >
   reservation_search(const int);

   static
   std::vector<std::vector<QString> >
   reservation_search_date(const QString&, const QString&);

   static
   std::vector<std::vector<QString> >
   vehicle_search(const QString&, const QString&);

   static
   std::vector<std::vector<QString> >
   vehicle_search(const QString&, const QString&, const QString&);

   static 
   QString
   settings_search(const QString&);

   static bool exists_reservation(int);
   static bool exists_vehicle(QString&);
   static void remove_reservation(int);
   static void remove_vehicle(QString& reg_nr);
   
   static void display(std::vector<std::vector<QString> >); // used for testing
  
   
private:
   static sqlite3* db;

   static void init_db();

   static sqlite3_stmt* bind_QString(const char*, const QString&);
   
   static std::vector<std::vector<QString> > ask(sqlite3_stmt*);

   static void check_for_error();

   static void fill_db();
};



#endif

