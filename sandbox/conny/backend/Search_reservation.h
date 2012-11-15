/*
* FILENAMN:    Search_reservation.h
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

#ifndef SEARCH_RESERVATION
#define SEARCH_RESERVATION

#include <string>
#include <vector>

/////////////////////////////////////////////////////////////////////
// Search_reservation:
/////////////////////////////////////////////////////////////////////
class Search_reservation
{
public:
   Search_reservation();
   ~Search_reservation();
   
   void res_nr(std::string&);
   void reg_nr(std::string&);
   void name(std::string&;
   void tel(std::string&);
   void status(std::string&);
   void start_end(int, int, int, int);
   
   bool empty();

   void clear();
   
private:
   vector<Reservation*> search_result;
};

#endif
