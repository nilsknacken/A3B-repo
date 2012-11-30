// This file is only used to insert some entries to the database

#include "DatabaseQ.h"

void Database::fill_db()
{
    Database::reservation_update(12345,
                                 "ABC123",
                                 "2013-01-09 11:00",
                                 "2013-01-11 11:00",
                                 "kommande",
                                 "Eva Andersson",
                                 "0707047264",
                                 "Storgatan 12",
                                 "58533",
                                 "Storstaden");

    Database::reservation_update(38253,
                                 "ABC123",
                                 "2013-01-11 11:30",
                                 "2013-01-13 12:30",
                                 "kommande",
                                 "Peter Svensson",
                                 "0703423456",
                                 "Lugna gatan 3B",
                                 "58253",
                                 "Hålan");

    Database::reservation_update(32474,
                                 "DEF456",
                                 "2013-02-10 11:00",
                                 "2013-02-11 12:00",
                                 "kommande",
                                 "Peter Bláha",
                                 "0707147975",
                                 "Bredvidgatan 13",
                                 "58653",
                                 "Mellanstaden");

    Database::reservation_update(54321,
                                 "HFT643",
                                 "2013-01-10 08:00",
                                 "2013-01-11 09:00",
                                 "kommande",
                                 "Andre Agassi",
                                 "0707123456",
                                 "Storgatan 1",
                                 "58253",
                                 "Storstaden");

    Database::reservation_update(83726,
                                 "REV666",
                                 "2012-11-10 08:00",
                                 "2012-12-14 09:00",
                                 "aktiv",
                                 "Tommy Olsson",
                                 "070747110",
                                 "Proffesorsgatan 23",
                                 "14711",
                                 "Radixsort");

    Database::reservation_update(54321,
                                 "HFT643",
                                 "2010-01-10 08:00",
                                 "2010-01-11 09:00",
                                 "avslutad",
                                 "Björn Borg",
                                 "0707324233",
                                 "Mastergatan 1",
                                 "08253",
                                 "Storstaden");

    Database::vehicle_update("ABC123",
                             "Liten bil",
                             "ledig",
                             "Ford",
                             "Ka",
                             67457,
                             "hö backspegel, växelspak saknas");

    Database::vehicle_update("KSU638",
                             "Liten lastbil",
                             "ledig",
                             "Citroen",
                             "Jumpy",
                             674573,
                             "hö bakhjul saknas");

    Database::vehicle_update("DHR937",
                             "Stor lastbil",
                             "ledig",
                             "Volvo",
                             "FH12",
                             674573,
                             "hö bakhjul saknas");


    Database::vehicle_update("REV666",
                             "Mellanbil",
                             "uthyrd",
                             "Hyundai",
                             "i30",
                             234621,
                             "lätt rökskadad");

    Database::vehicle_update("NRG372",
                             "Mellanbil",
                             "uthyrd",
                             "Volvo",
                             "v40",
                             2343,
                             "");

    Database::vehicle_update("WJD729",
                             "Stor bil",
                             "uthyrd",
                             "Volvo",
                             "XC90",
                             234334,
                             "lerig");


    Database::vehicle_update("HFT643",
                             "Liten bil",
                             "ledig",
                             "Ford",
                             "Ka",
                             4711,
                             "hö backspegel repad");
}
