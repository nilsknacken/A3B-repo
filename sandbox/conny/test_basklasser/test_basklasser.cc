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
   try
   {
      if (argc == 2)
      Database::open(argv[1]);
      else
      Database::open("default_db.sqlite");
      //=======================================================
      int    res_nr    = 10000;                    //==========
      string reg_nr    = "ABC123";                 //==========
      string start     = "2012-12-12 08:00:00";    //==========
      string end       = "2012-12-13 13:30:00";    //==========
      string status    = "kommande";               //==========
      string name      = "Ole Bengtsson";          //==========
      string tel       = "07066666666";            //==========
      string adress    = "Liu";                    //==========
      string postal_nr = "66666";                  //==========
      string city      = "Linkoping";              //==========
      //=======================================================   
      /*
      Reservation person(res_nr, reg_nr, name, tel, 
      adress, postal_nr, city, 
      status, start, end);
      */
      Reservation* person = 
         make_reservation(reg_nr, start, end, name, tel, adress, 
                          postal_nr, city);

      cout << "Person har res nr.: " << person->get_res_nr() << endl;
      
      person->save();
      
      //=======================================================
      res_nr    =  10000;                //====================
      reg_nr    = "DEF345";              //====================
      start     = "2012-12-12 08:00:00"; //====================
      end       = "2012-12-13 13:30:00"; //====================
      status    = "kommande";            //====================
      name      = "Ole Bengtsson";       //====================
      tel       = "07066666666";         //====================
      adress    = "Liu";                 //====================
      postal_nr = "66666";               //====================
      city      = "Linkoping";           //====================
      //=======================================================   
      Reservation person2(res_nr, reg_nr, start, end, status, 
                          name, tel, adress, postal_nr, city);
      
      cout << "Person2 reg_nr: " << person2.get_reg_nr() << endl;
      
      person2.save();
      //=======================================================   
      //=======================================================     
             reg_nr = "ABC123";           //===================
      string type    = "liten";           //===================
             status = "ledig";            //===================
      string brand   = "Volvo";           //===================
      string model   = "240 GL";          //===================
      int    mileage = 10000;             //===================
      string damage  = "Inga skador.";    //===================
      //=======================================================
      Vehicle bil(reg_nr, type, status, brand, 
      model, mileage, damage);
      
      cout << "bilmodel = " << bil.get_model() << endl;
      
      //=======================================================
      //=======================================================   
      int open_hour  = 8000;    //=============================
      int close_hour = 1800;    //=============================
      int min_rental = 2;       //=============================
      //=======================================================   
      Settings inst(open_hour, close_hour, min_rental);
      
      cout << "Öppettider: " << inst.get_open_hour() 
      << "-" << inst.get_close_hour() << endl;

      //=======================================================
      //=======================================================
      Search_reservation search_res;
      vector <Reservation*> list;
      string status2 = "kommande";
      //======================================================= 
      list = search_res.status(status2);
      
      
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
      vector<vector<string>> veh_str_vec;    //================
      status   = "ledig";                    //================
      string    mileage_ = "10000";          //================
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
      string what = "all";  //=================================
      string value = "Liu"; //=================================
      //=======================================================   
      vector<vector<string> > result = 
         Database::reservation_search(what, value);
      
      Database::display(result);

      Database::close();
   }
   catch (const exception& e)
   {
      cerr << e.what() << '\n';
   }
   
   return 0;
}

