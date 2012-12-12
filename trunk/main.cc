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
* Vår main funktion, här görs en Qt applikation, därefter öppnas databasen,
* om inget argument kommer in till funktionen så öppnas defaultdatabasen, annars
* den angivna filen. Därefter skapas och körs MainWindow.
*
* Created by:
* Andreas:  main
*           Dialog_Settings.ui
*
* Adam & Andreas: MainWindow.ui
*/

#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include <iostream>
#include <exception>
#include <string>
#include "MainWindow.h"
#include "DatabaseQ.h"


int main(int argc, char *argv[])
{
    std::string version_nr = "1.0";
    int exit_code;

    if(argc == 2 && (argv[1] == std::string("-h") || argv[1] == std::string("--help")))
    {
        std::cout << "A3B-Carpark v" << version_nr << "  -  Because we do more than take you from A 2 B\n\n"
                     "Start the program with " << argv[0] << " [ARGUMENT]\n\n"
                     "   [ARGUMENT]       [DESCRIPTION]\n"
                     "   -h               This help page.\n"
                     "   --help           This help page.\n"
                     "   -d filename      Start program with a non default database. If the database\n"
                     "                    does not exist an empty database will be created.\n" << std::endl;
        return 0;
    }

    else if(argc == 1 || (argc == 3 && argv[1] == std::string("-d")))
    {
        try
        {
            QApplication app(argc, argv);

            QFile file(":/ss_default.qss");
            file.open(QFile::ReadOnly);
            QString styleSheet = QString::fromUtf8(file.readAll());
            qApp->setStyleSheet(styleSheet);

            try
            {
                if(argc == 3)
                    Database::open(argv[2]);

                else
                    Database::open("default_db.sqlite");
            }
            catch(database_error& e) // Om databasen inte kan öppnas
            {
                QMessageBox::warning(nullptr,
                                     QString::fromUtf8("Databasfel"),
                                     QString::fromUtf8("Följande databasfel har påträffats:\n\n"
                                                       "\"%1\""
                                                       "\n\nProgrammet kommer att avslutas.").arg(e.what()));
                std::cerr << e.what() << std::endl;
                return EXIT_FAILURE;
            }

            MainWindow main_window;
            main_window.show();
            exit_code = app.exec();
        }
        catch(std::exception& e) // Övriga oförutsedda fel
        {
            QMessageBox::warning(nullptr,
                                 QString::fromUtf8("Fel"),
                                 QString::fromUtf8("Ett oväntat fel har påträffats:\n\n"
                                                   "\"%1\""
                                                   "\n\nProgrammet kommer att avslutas.").arg(e.what()));
            std::cerr << e.what() << std::endl;
            Database::close();
            return EXIT_FAILURE;
        }

        Database::close();
        return exit_code;
    }

    else
    {
        std::cerr << "Invalid argument. Type \"" << argv[0] << " --help\" for valid arguments." << std::endl;
        return EXIT_FAILURE;
    }
}
