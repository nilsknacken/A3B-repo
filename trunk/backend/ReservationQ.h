/*
* FILENAMN:    Reservation.h
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-10-18
*
* DESCRIPTION
* 
* The reservation class, uses as a connection between the database and the GUI.
* Declaration av the reservation class.
*
* Created by:
* Conny: All
*/

#ifndef RESERVATION
#define RESERVATION

#include <QString>
#include <stdexcept>
#include "DatabaseQ.h"

/////////////////////////////////////////////////////////////////////
// Reservation:
/////////////////////////////////////////////////////////////////////
class Reservation
{
public:
    Reservation(int, QString&, QString&,
                QString&, QString&, QString&,
                QString&, QString&, QString&,
                QString&);
    Reservation()                              = default;
    Reservation(const Reservation&)            = default;
    Reservation(Reservation&&)                 = default;
    ~Reservation()                             = default;

    Reservation& operator=(const Reservation&) = default;
    Reservation& operator=(Reservation&&)      = default;

    void save();
    void remove();

    void set_res_nr(const int);
    void set_reg_nr(const QString&);
    void set_name(const QString&);
    void set_tel(const QString&);
    void set_adress(const QString&);
    void set_postal_nr(const QString&);
    void set_city(const QString&);
    void set_status(const QString&);
    void set_start(const QString&);
    void set_end(const QString&);

    int     get_res_nr()    const;
    QString get_reg_nr()    const;
    QString get_name()      const;
    QString get_tel()       const;
    QString get_adress()    const;
    QString get_postal_nr() const;
    QString get_city()      const;
    QString get_status()    const;
    QString get_start()     const;
    QString get_end()       const;

private:
    void correct_reg_nr(const QString&);
    void correct_status(const QString&);
    void correct_name(const QString&);
    void correct_tel(const QString&);
    void correct_postal_nr(const QString&);
    void correct_city(const QString&);

    int     res_nr_;
    QString reg_nr_;
    QString start_;
    QString end_;
    QString status_;
    QString name_;
    QString tel_;
    QString adress_;
    QString postal_nr_;
    QString city_;
};

// Help functions
Reservation* 
make_reservation(QString&, QString&, QString&,
                 QString&, QString&, QString&,
                 QString&, QString&);


// Reservation's error class
class reservation_error : public std::logic_error
{
public:
    explicit reservation_error(const std::string& what_arg) noexcept
        : logic_error(what_arg) {}

    explicit reservation_error(const char* what_arg) noexcept
        : logic_error(what_arg) {}
};

#endif
