/*
* FILENAMN:    Search_vehicle.h
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

#ifndef SEARCH_VEHICLE
#define SEARCH_VEHICLE

#include <QString>
#include <vector>
#include <stdexcept>
#include "DatabaseQ.h"
#include "VehicleQ.h"

/////////////////////////////////////////////////////////////////////
// Search_vehicle:
/////////////////////////////////////////////////////////////////////
class Search_vehicle
{
public:
    Search_vehicle()  = default;
    ~Search_vehicle() = default;

    std::vector<Vehicle*> all();
    std::vector<Vehicle*> reg_nr(QString&);
    std::vector<Vehicle*> type(QString&);
    std::vector<Vehicle*> status(QString&);
    std::vector<Vehicle*> brand(QString&);
    std::vector<Vehicle*> model(QString&);
    std::vector<Vehicle*> type_date(QString&, QString&,
                                    QString&);
    std::vector<Vehicle*> get_current_result()                    const;

    bool empty() const;
    void clear();

private:
    Search_vehicle(const Search_vehicle&)            = delete;
    Search_vehicle(Search_vehicle&&)                 = delete;

    Search_vehicle& operator=(const Search_vehicle&) = delete;
    Search_vehicle& operator=(Search_vehicle&&)      = delete;

    void create_result(std::vector<std::vector<QString>>&);

    std::vector<Vehicle*> search_result;
};

// Error to be thrown in Search_vehicle
class search_vehicle_error : public std::logic_error
{
public:
    explicit search_vehicle_error(const std::string& what_arg) noexcept
        : logic_error(what_arg) {}

    explicit search_vehicle_error(const char* what_arg) noexcept
        : logic_error(what_arg) {}
};


#endif
