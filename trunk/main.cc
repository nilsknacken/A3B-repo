/*
* Filename:    main.cc
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-10-12
*
* DESCRIPTION:
*
* Our main function
*
* Created by:
* Andreas:
*/

#include <QApplication>
#include "MainWindow.h"
#include "DatabaseQ.h"
#include <iostream>
#include <exception>


int main(int argc, char *argv[])
{
    int exit_code;

    try
    {
        Database::open("default_db.sqlite");

        QApplication app(argc, argv);
        MainWindow main_window;
        main_window.show();
        exit_code = app.exec();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    Database::close();
    return exit_code;
}
