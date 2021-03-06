/*
* FILENAMN:    Search_reservation.h
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-12-12
*
* DESCRIPTION
* 
* Declaration of the reservation search class.
*
* Created by:
* Conny: All
*/

#ifndef SEARCH_RESERVATION
#define SEARCH_RESERVATION

#include <QString>
#include <stdexcept>
#include <vector>
#include "DatabaseQ.h"
#include "ReservationQ.h"

/////////////////////////////////////////////////////////////////////
// Search_reservation:
/////////////////////////////////////////////////////////////////////
class Search_reservation
{
public:
    Search_reservation()  = default;
    ~Search_reservation();

    std::vector<Reservation*> all();
    std::vector<Reservation*> res_nr(int);
    std::vector<Reservation*> reg_nr(QString&);
    std::vector<Reservation*> name(QString&);
    std::vector<Reservation*> tel(QString&);
    std::vector<Reservation*> status(QString&);
    std::vector<Reservation*> start_end(QString&, QString&);
    std::vector<Reservation*> get_current_result() const;

    bool empty() const;
    void clear();

private:
    Search_reservation(const Search_reservation&)            = delete;
    Search_reservation(Search_reservation&&)                 = delete;

    Search_reservation& operator=(const Search_reservation&) = delete;
    Search_reservation& operator=(Search_reservation&&)      = delete;

    void correct_res_nr(const int);
    void correct_reg_nr(const QString&);
    void correct_name(const QString&);
    void correct_tel(const QString&);

    void create_result(std::vector<std::vector<QString>>&);

    std::vector<Reservation*> search_result;
};

// Error to be thrown in Search_reservation
class search_reservation_error : public std::logic_error
{
public:
    explicit search_reservation_error(const std::string& what_arg) noexcept
        : logic_error(what_arg) {}

    explicit search_reservation_error(const char* what_arg) noexcept
        : logic_error(what_arg) {}
};

#endif
