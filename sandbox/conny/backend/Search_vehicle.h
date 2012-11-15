/*
* FILENAMN:    Search_vehicle.h
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

#ifndef SEARCH_VEHICLE
#define SEARCH_VEHICLE

#include <sting>
#include <vector>

/////////////////////////////////////////////////////////////////////
// Search_vehicle:
/////////////////////////////////////////////////////////////////////
class Search_vehicle
{
public:
   Search_vehicle();
   ~Search_vehicle();
   
   void all();
   void reg_nr(std::string&);
   void type(std::string&);
   void status(std::string&);
   void brand(std::string&);
   void brand_model(std::string&, std::string&);
   void type_date(std::string&, int, int, int, int);

   bool empty();
   void clear();
   
private:
   vector<Vehicle*> search_result;
   
};

#endif
