/*
 * FILENAME:    Carpark.h
 * PROJECT:     A3B
 * PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
 *              Andreas Bolin    Y3a andbo467@student.liu.se
 *              Martin Andersson Y3a maran703@student.liu.se
 *              Adam Andersson   Y3a adaan690@student.liu.se
 * DATE:        2012-11-15
 *
 * DESCRIPTION
 * 
 * ///////////////Programbeskrivning
 */
#ifndef CARPARK_H
#define CARPARK_H

#include <string>

/////////////////////////////////////////////////////////////////////
// Carpark class
/////////////////////////////////////////////////////////////////////
class Carpark
{
public:
   Carpark(){};
   ~Carpark(){};
   
   void run(std::string&);
   
private:
   Carpark(const Carpark&)            = delete;
   Carpark(Carpark&&)                 = delete;
   Carpark& operator=(const Carpark&) = delete;
   Carpark& operator=(Carpark&&)      = delete;
}


/////////////////////////////////////////////////////////////////////
// carpark_error:
// Kastas om fel uppstår i en Carpark-operation.
/////////////////////////////////////////////////////////////////////
class carpark_error : public std::logic_error
{
public:
   explicit carpark_error(const std::string& what_arg) noexcept
      : std::logic_error(what_arg) {}
  
   explicit carpark_error(const char* what_arg) noexcept
      : std::logic_error(what_arg) {}
};

#endif