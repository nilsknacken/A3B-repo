
#include <QApplication>
#include "MainWindow.h"
#include "DatabaseQ.h"
#include <iostream>
#include <exception>

#include <QResource>
//int i = QResource::registerResource("./resource.rcc");

int main(int argc, char *argv[])
{
    int i;

    try
    {
        Database::open("default_db.sqlite");

        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        i =  a.exec();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    Database::close();
    return i;

}
