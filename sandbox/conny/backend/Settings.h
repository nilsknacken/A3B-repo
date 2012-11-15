/*
* FILENAMN:    Settings.h
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

#ifndef SETTINGS
#define SETTINGS

/////////////////////////////////////////////////////////////////////
// Settings:
/////////////////////////////////////////////////////////////////////
class Settings
{
public:
   Settings();
   ~Settings();

   void save();
   void set_open_hour(int);
   void set_close_hour(int);
   void set_get_min_rental(int);
   
   int get_open_hour();
   int get_close_hour();
   int get_min_rental();
   
private:
   int open_hour;
   int close_hour;
   int min_rental;
};

#endif
