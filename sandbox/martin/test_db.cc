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

   Database::reservation_update(12345,
                                "ABC123",
                                "2011-11-09 11:11",
                                "2011-11-11 11:11",
                                "kommande",
                                "För Efternamn",
                                "0707123456",
                                "Storgatan 1",
                                "58253",
                                "Storstaden");
   Database::reservation_update(38253,
                                "ABC123",
                                "2011-11-11 11:11",
                                "2011-11-12 11:12",
                                "kommande",
                                "För Efternamn",
                                "0707123456",
                                "Storgatan 1",
                                "58253",
                                "Storstaden");
   
   Database::reservation_update(32474,
                                "DEF456",
                                "2011-11-10 11:11",
                                "2011-11-14 11:12",
                                "kommande",
                                "För Efternamn",
                                "0707123456",
                                "Storgatan 1",
                                "58253",
                                "Storstaden");

   Database::vehicle_update("ABC123",
                            "small_car",
                            "tillgänglig",
                            "Ford",
                            "Ka",
                            67457,
                            "hö backspegel, växelspak saknas");

   Database::vehicle_update("REV666",
                            "medium_car",
                            "uthyrd",
                            "Hyundai",
                            "i30",
                            234621,
                            "lätt rökskadad");
                            
   Database::vehicle_update("HFT643",
                            "small_car",
                            "tillgänglig",
                            "Ford",
                            "Ka",
                            4711,
                            "hö backspegel repad");
   string what;
   string value;
   vector<vector<string>> result; 
   
   what = "all";
   value = "5678";
   result = Database::reservation_search(what, value);
   Database::display(result);

   what = "all";
   value = "ABC123";
   result = Database::vehicle_search(what, value);
   Database::display(result);

   Database::close();
   
   return 0;
}
      
