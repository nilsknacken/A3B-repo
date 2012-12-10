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
* Andreas: main()
*/

#include <QApplication>
#include <QFile>
#include <iostream>
#include <exception>
#include "MainWindow.h"
#include "DatabaseQ.h"

int main(int argc, char *argv[])
{
    int exit_code = 0;

    try
    {
        if (argc == 2)
        {
            if(! Database::open(argv[1]))
                return EXIT_FAILURE;
        }
        else
        {
            if(! Database::open("default_db.sqlite"))
                return EXIT_FAILURE;
        }


        QApplication app(argc, argv);
        MainWindow main_window;


QFile file(":/ss_default.qss");
file.open(QFile::ReadOnly);
QString styleSheet = QLatin1String(file.readAll());

qApp->setStyleSheet(styleSheet);


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
