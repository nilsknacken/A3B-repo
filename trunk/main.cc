/*
* Filename:    main.cc
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-12-12
*
* DESCRIPTION:
*
* Our main function
*
* Created by:
* Andreas: main
*/

#include <QApplication>
#include <QFile>
#include <iostream>
#include <exception>
#include <QMessageBox>
#include "MainWindow.h"
#include "DatabaseQ.h"

int main(int argc, char *argv[])
{
    int exit_code = 59;

    try
    {
        QApplication app(argc, argv);
        QFile file(":/ss_default.qss");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());
        qApp->setStyleSheet(styleSheet);

        try
        {
            if (argc >= 2)
            {
                Database::open(argv[1]);
            }
            else
            {
                Database::open("default_db.sqlite");
            }
        }
        catch(database_error& e)
        {
            QMessageBox::warning(nullptr,
                                 QString::fromUtf8("Databasfel"),
                                 QString::fromUtf8("Följande databasfel har påträffats:\n\n\"")
                                 + e.what()
                                 + QString::fromUtf8("\"\n\nProgrammet kommer att avslutas."));
            std::cerr << e.what() << std::endl;
            return EXIT_FAILURE;
        }

        MainWindow main_window;
        main_window.show();
        exit_code = app.exec();
    }
    catch(std::exception& e)
    {
        QMessageBox::warning(nullptr,
                             QString::fromUtf8("Fel"),
                             QString::fromUtf8("Ett oväntat fel har påträffats:\n\n\"")
                             + e.what()
                             + QString::fromUtf8("\"\n\nProgrammet kommer att avslutas."));
        std::cerr << e.what() << std::endl;
        Database::close();
        return EXIT_FAILURE;
    }

    Database::close();
    return exit_code;
}
