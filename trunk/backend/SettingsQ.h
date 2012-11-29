/*
* FILENAMN:    Settings.h
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

#ifndef SETTINGS
#define SETTINGS

#include <stdexcept>

#include "../database/DatabaseQ.h"

/////////////////////////////////////////////////////////////////////
// Settings:
/////////////////////////////////////////////////////////////////////
class Settings
{
public:
    Settings(int, int, int);
    ~Settings() = default;

    void save();

    void set_open_hour(const int);
    void set_close_hour(const int);
    void set_min_rental(const int);

    int get_open_hour()  const;
    int get_close_hour() const;
    int get_min_rental() const;

private:
    Settings()                           = delete;
    Settings(const Settings&)            = delete;
    Settings(Settings&&)                 = delete;

    Settings& operator=(const Settings&) = delete;
    Settings& operator=(Settings&&)      = delete;

    int open_hour_;
    int close_hour_;
    int min_rental_;
};

// Error to be thrown in Settings
class settings_error : public std::logic_error
{
public:
    explicit settings_error(const std::string& what_arg) noexcept
        : logic_error(what_arg) {}

    explicit settings_error(const char* what_arg) noexcept
        : logic_error(what_arg) {}
};

#endif
