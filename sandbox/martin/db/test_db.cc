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
                                "aktiv",
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
                                "2011-08-10 11:11",
                                "2011-08-11 12:12",
                                "avslutad",
                                "För Efternamn",
                                "0707123456",
                                "Storgatan 1",
                                "58253",
                                "Storstaden");

   Database::reservation_update(54321,
                                "HFT643",
                                "2011-09-10 11:11",
                                "2011-10-11 12:12",
                                "kommande",
                                "För Efternamn",
                                "0707123456",
                                "Storgatan 1",
                                "58253",
                                "Storstaden");

   Database::vehicle_update("ABC123",
                            "liten_bil",
                            "available",
                            "Ford",
                            "Ka",
                            67457,
                            "hö backspegel, växelspak saknas");

   Database::vehicle_update("REV666",
                            "mellan_bil",
                            "rented",
                            "Hyundai",
                            "i30",
                            234621,
                            "lätt rökskadad");
                            
   Database::vehicle_update("HFT643",
                            "liten_bil",
                            "ledig",
                            "Ford",
                            "Ka",
                            4711,
                            "hö backspegel repad");

   Database::vehicle_update("DEF456",
                            "liten_bil",
                            "ledig",
                            "Ford",
                            "Ka",
                            4711,
                            "vä backspegel repad");

   Database::settings_update(10, 20, 6);

   cout << "Settings table\nopen_hour: " << Database::settings_search("open_hour") << endl;
   cout << "close_hour: " << Database::settings_search("close_hour") << endl;
   cout << "min_rental: " << Database::settings_search("min_rental") << endl << endl; 

   string what;
   string value;
   string type;
   string start;
   string end;

   vector<vector<string>> result; 
   
   cout << "All vehicles\n";
   what = "all";
   value = "5678";
   result = Database::vehicle_search(what, value);
   Database::display(result);

   string reg_nr = "DEF456";

   if(Database::remove_vehicle(reg_nr))
     cout << "remove lyckades\n";
   else
    cout << "remove genomfördes ej\n";

   cout << "All reservations\n";
   what = "all";
   value = "5678";
   result = Database::vehicle_search(what, value);
   Database::display(result);


   
                           
   Database::close();
   
   return 0;
}
      
