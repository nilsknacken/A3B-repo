#-------------------------------------------------
#
# Project created by QtCreator 2012-11-21T20:31:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = A3B-Carpark_Gui
TEMPLATE = app


SOURCES += gui.cc\
        MainWindow.cc \
    Dialog_Settings.cpp

HEADERS  += MainWindow.h \
    Dialog_Settings.h

FORMS    += MainWindow.ui \
    Dialog_Settings.ui
