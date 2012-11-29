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

#include <QtDebug>

#include <iostream>
#include <iomanip>
#include <QString>
#include <vector>

#include "backend/ReservationQ.h"
#include "backend/Vehicle.hQ"
#include "backend/Settings.hQ"
#include "backend/Search_reservationQ.h"
#include "backend/Search_vehicleQ.h"
#include "backend/DatabaseQ.h"

using namespace std;

int main(int argc, char* argv[])
{
       try //!!!!!!!!!!!!!
    {
        if (argc == 2)
            Database::open(argv[1]);
        else
            Database::open("default_db.sqlite");
        //=======================================================
        int     res_nr     = 10000;                    //========
        QString reg_nr     = "ABC123";                 //========
        QString start      = "2012-12-12 08:00:00";    //========
        QString end        = "2012-12-13 13:30:00";    //========
        QString status_res = "kommande";               //========
        QString name       = "Ole Bengtsson";          //========
        QString tel        = "07066666666";            //========
        QString adress     = "Liu";                    //========
        QString postal_nr  = "66666";                  //========
        QString city       = "Linkoping";              //========
        //=======================================================
        
        Reservation* person =
                make_reservation(reg_nr, start, end, name, tel, adress,
                                 postal_nr, city);
        
        qDebug() << "Person har res nr.: " << person->get_res_nr() << endl;
        
        person->save();
        
        //=======================================================
        res_nr     =  10000;                //===================
        reg_nr     = "DEF345";              //===================
        start      = "2012-12-12 08:00:00"; //===================
        end        = "2012-12-13 13:30:00"; //===================
        status_res = "kommande";            //===================
        name       = "Ole Bengtsson";       //===================
        tel        = "07066666666";         //===================
        adress     = "Liu";                 //===================
        postal_nr  = "66666";               //===================
        city       = "Linkoping";           //===================
        //=======================================================
        Reservation person2(res_nr, reg_nr, start, end, status_res,
                            name, tel, adress, postal_nr, city);
        
        qDebug() << "Person2 reg_nr: " << person2.get_reg_nr() << endl;
        
        person2.save();
        //=======================================================
        //=======================================================
        reg_nr = "ABC123";                //=====================
        QString type    = "liten_bil";    //=====================
        QString status_veh = "utlånad";   //=====================
        QString brand   = "Volvo";        //=====================
        QString model   = "240 GL";       //=====================
        int    mileage = 10000;           //=====================
        QString damage  = "Inga skador."; //=====================
        //=======================================================
        Vehicle bil(reg_nr, type, status_veh, brand,
                    model, mileage, damage);
        
        qDebug() << "bilmodel = " << bil.get_model() << endl;
        
        bil.save();
        //=======================================================
        //=======================================================
        int open_hour  = 8000; //================================
        int close_hour = 1800; //================================
        int min_rental = 2;    //================================
        //=======================================================
        Settings inst(open_hour, close_hour, min_rental);
        
        qDebug() << "Öppettider: " << inst.get_open_hour()
                 << "-" << inst.get_close_hour() << endl;
        
        //=======================================================
        //=======================================================
        Search_reservation search_res;
        vector <Reservation*> list_res;
        //QString status2 = "kommande";
        //=======================================================
        list_res = search_res.status(status_res);
        
        
        qDebug() << "Bokningslistan tom? ";
        if(search_res.empty())
            qDebug() << "Ja!" << endl;
        else
            qDebug() << "Nej!" << endl;
        
        search_res.clear();
        
        qDebug() << "Bokningslistan tom? ";
        if(search_res.empty())
            qDebug() << "Ja!" << endl;
        else
            qDebug() << "Nej!" << endl;
        
        //=======================================================
        //=======================================================
        Search_vehicle search_veh;
        vector <Vehicle*> list_veh;
        //QString status3 = "utlånad";
        //=======================================================
        list_veh = search_veh.status(status_veh);
        
        qDebug() << "Billistan tom? ";
        if(search_veh.empty())
            qDebug() << "Ja!" << endl;
        else
            qDebug() << "Nej!" << endl;
        
        search_veh.clear();
        
        qDebug() << "Billistan tom? ";
        if(search_veh.empty())
            qDebug() << "Ja!" << endl;
        else
            qDebug() << "Nej!" << endl;
        
        //=======================================================
        //=======================================================
        
        Database::close();
    }
    catch (const exception& e)
    {
        qDebug() << e.what() << '\n';
    }//!!!!!!!!!!!!
   
   return 0;
}

