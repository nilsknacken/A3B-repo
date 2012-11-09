/*
* FILENAMN:    bilpark.cc
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  910124-2411 Y3a conan414@student.liu.se
*              Andreas Bolin    820406-2098 Y3a andbo467@student.liu.se
*              Martin Andersson 890929-0566 Y3a maran703@student.liu.se
*              Adam Andersson               Y3a adaan690@student.liu.se
* DATE:        2012-10-12
*
* DESCRIPTION
* 
* ///////////////Programbeskrivning
*/
#include <iostream>
#include "Carpark.h"

using namespace std;

int main
{
   Carpark carpark;

   try
   {
      carpark.run();
   }
   catch (...)
   {
      cout << "Ett okänt fel har inträffat.\n";
   }
   
   return 0;
}