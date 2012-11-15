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

private:
   static sqlite3* db;

   static void init_db();

   std::vector<std::vector<std::string>> ask(sqlite3_stmt*);
   
};



#endif

