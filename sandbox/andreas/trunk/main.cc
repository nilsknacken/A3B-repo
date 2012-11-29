
#include <QApplication>
#include "gui/MainWindow.h"
#include "database/DatabaseQ.h"

#include <iostream>
#include <exception>

#include <QResource>
int i = QResource::registerResource("./resource.rcc");

int main(int argc, char *argv[])
{
    try
    {
        Database::open("default_db.sqlite");

        QApplication a(argc, argv);
        MainWindow w;
        w.show();

        return a.exec();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }


}
