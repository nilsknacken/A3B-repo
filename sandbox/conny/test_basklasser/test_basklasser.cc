/*
* FILENAMN:    test_basklasser.cc
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-10-18
*
* DESCRIPTION
* 
* ///////////////Programbeskrivning
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Reservation.h"
#include "Vehicle.h"
#include "Settings.h"
#include "Search_reservation.h"
#include "Search_vehicle.h"
#include "Database.h"

using namespace std;

int main(int argc, char* argv[])
{
   if (argc == 2)
      Database::open(argv[1]);
   else
      Database::open("default_db.sqlite");
//=======================================================
   int    res_nr    = 100;                   //==========
   string reg_nr    = "ABC123";              //==========
   string name      = "Ole Bengtsson";       //==========
   string tel       = "07066666666";         //==========
   string adress    = "Liu";                 //==========
   string postal_nr = "66666";               //==========
   string city      = "Linköping";           //==========
   string status    = "kommande";            //==========
   string start     = "2012-12-12 08:00:00"; //==========
   string end       = "2012-12-13 13:30:00"; //==========
//=======================================================   
   Reservation person(res_nr, reg_nr, name, tel, 
                      adress, postal_nr, city, 
                      status, start, end);

   cout << "Person heter: " << person.get_name() << endl;
   
   person.save();
   
//=======================================================
          res_nr    = 200;                   //==========
          reg_nr    = "DEF345";              //==========
          name      = "Ole Bengtsson";       //==========
          tel       = "07066666666";         //==========
          adress    = "Liu";                 //==========
          postal_nr = "66666";               //==========
          city      = "Linköping";           //==========
          status    = "kommande";            //==========
          start     = "2012-12-12 08:00:00"; //==========
          end       = "2012-12-13 13:30:00"; //==========
//=======================================================   
   Reservation person2(res_nr, reg_nr, name, tel, 
                      adress, postal_nr, city, 
                      status, start, end);
                   
   cout << "Person2 reg_nr: " << person.get_reg_nr() << endl;
   
   person2.save();
//=======================================================   
//=======================================================     
   int    mileage = 10000;          //===================
          reg_nr  = "ABC123";       //===================
   string type    = "liten";        //===================
          status  = "ledig";        //===================
   string brand   = "Volvo";        //===================
   string model   = "240 GL";       //===================
   string damage  = "Inga skador."; //===================
//=======================================================
   Vehicle bil(mileage, reg_nr, type, status, brand, 
            model, damage);
         
   cout << "bilmodel = " << bil.get_model() << endl;
   
//=======================================================
//=======================================================   
   int open_hour  = 8000; //=============================
   int close_hour = 1800; //=============================
   int min_rental = 2;    //=============================
//=======================================================   
   Settings inst(open_hour, close_hour, min_rental);
   
   cout << "Öppettider: " << inst.get_open_hour() 
        << "-" << inst.get_close_hour() << endl;

//=======================================================
//=======================================================
   vector<vector<string>> res_str_vec; //================
          status  = "kommande";        //================
   string res_nr_ = "100";             //================
//======================================================= 
   vector<string> A = {res_nr_, reg_nr, name, tel, 
                 adress, postal_nr, city, 
                 status, start, end};
              
   res_str_vec.push_back(A);
   Search_reservation search_res; 
   //search_res.create_result1(res_str_vec);
   
   cout << "Bokningslistan tom? ";
   if(search_res.empty())
      cout << "Ja!" << endl;
   else
      cout << "Nej!" << endl;
   
   search_res.clear();
   
   cout << "Bokningslistan tom? ";
   if(search_res.empty())
      cout << "Ja!" << endl;
   else
      cout << "Nej!" << endl;
      
//=======================================================
//=======================================================
   vector<vector<string>> veh_str_vec; //================
             status   = "ledig";        //================
   string    mileage_ = "10000";       //================
//======================================================= 
   vector<string> B = {mileage_, reg_nr, type, status, brand, 
            model, damage};
              
   veh_str_vec.push_back(B);
   Search_vehicle search_veh; 
   //search_veh.create_result2(veh_str_vec);
   
   cout << "Billistan tom? ";
   if(search_veh.empty())
      cout << "Ja!" << endl;
   else
      cout << "Nej!" << endl;
   
   search_veh.clear();
   
   cout << "Billistan tom? ";
   if(search_veh.empty())
      cout << "Ja!" << endl;
   else
      cout << "Nej!" << endl;
      
//=======================================================
//=======================================================
   
      
   string what = "all";
   string value = "Liu";
   
   vector<vector<string> > result = Database::reservation_search(what, value);
      
   Database::display(result);

   Database::close();
   
   return 0;
}

