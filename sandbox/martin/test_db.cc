/*
* Filename:    test_db.cc
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-10-12
*
* DESCRIPTION:
* 
* Database
*/

#include "Database.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
   if (argc == 2)
      Database::open(argv[1]);
   else
      Database::open("default_db.sqlite");

   Database::reservation_update(1234, "ABC123");
   Database::reservation_update(5678, "ABC123");
   Database::reservation_update(1234, "DEF456");

   string what = "all";
   string value = "1";
   vector<vector<string> > result = Database::reservation_search(what, value);


   Database::display(result);
   
   return 0;
}
      
