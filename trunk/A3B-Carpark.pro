#-------------------------------------------------
#
# Project created by QtCreator 2012-11-21T20:31:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = A3B-Carpark
TEMPLATE = app


SOURCES +=\
        gui/MainWindow.cc \
    gui/Dialog_Settings.cc \
    database/DatabaseQ.cc \
    database/sqlite3.c \
    backend/VehicleQ.cc \
    backend/SettingsQ.cc \
    backend/Search_vehicleQ.cc \
    backend/Search_reservationQ.cc \
    backend/ReservationQ.cc \
    gui/MainWindowP5.cpp \
    gui/MainWindowP4.cpp \
    gui/MainWindowP3.cpp \
    gui/MainWindowP2.cpp \
    gui/MainWindowP1.cpp \
    main.cpp

HEADERS  += gui/MainWindow.h \
    gui/Dialog_Settings.h \
    database/sqlite3.h \
    database/DatabaseQ.h \
    backend/VehicleQ.h \
    backend/SettingsQ.h \
    backend/Search_vehicleQ.h \
    backend/Search_reservationQ.h \
    backend/ReservationQ.h

FORMS    += gui/MainWindow.ui \
            gui/Dialog_Settings.ui

RESOURCES += gui/resource.qrc

QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wextra
QMAKE_LFLAGS += -static-libstdc++
