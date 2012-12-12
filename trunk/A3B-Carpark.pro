#
# FILENAMN:    A3B-Carpark.pro
# PROJECT:     A3B
# PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
#              Andreas Bolin    Y3a andbo467@student.liu.se
#              Martin Andersson Y3a maran703@student.liu.se
#              Adam Andersson   Y3a adaan690@student.liu.se
# DATE:        2012-12-08
#
# DESCRIPTION
#
# QT Projectfile. Make a makefile with:
# $ qmake -makefile A3B-Carpark.pro
# Then compile with
# $ make
#
# Created by:
# Andreas:  allt
#

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = A3B-Carpark
TEMPLATE = app


SOURCES += main.cc \
           gui/MainWindow.cc \
           gui/Dialog_Settings.cc \
           database/DatabaseQ.cc \
           database/sqlite3.c \
           backend/VehicleQ.cc \
           backend/SettingsQ.cc \
           backend/Search_vehicleQ.cc \
           backend/Search_reservationQ.cc \
           backend/ReservationQ.cc \
           gui/MainWindowP1.cc \
           gui/MainWindowP2.cc \
           gui/MainWindowP3.cc \
           gui/MainWindowP4.cc \
           gui/MainWindowP5.cc \
           database/fill_db.cc

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

INCLUDEPATH += ./gui/ \
               ./backend/ \
               ./database

QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wextra
QMAKE_LFLAGS += -static-libstdc++

OTHER_FILES += \
    gui/stylesheet/ss_default.qss
