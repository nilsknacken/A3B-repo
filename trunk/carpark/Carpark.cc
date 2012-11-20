/*
 * FILENAME:    Carpark.cc
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

#include <string>
#include "Carpark.h"
#include "Database.h"
#include "Gui.h"

using namespace std;

/////////////////////////////////////////////////////////////////////
// Destructor:
/////////////////////////////////////////////////////////////////////
Carpark::~Carpark()
{
   Database::close();
}


/////////////////////////////////////////////////////////////////////
// Run:
/////////////////////////////////////////////////////////////////////
void Carpark::run(string& filename)
{
   try
   {
      if(! Database::open(filename))
         throw carpark_error("Kunde inte öppna databas\n");
      
      Gui gui;

   }
   catch(const exception& e)
   {
      cerr << ba.what() << endl;
   }
}
