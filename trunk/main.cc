
#include <QApplication>
#include "MainWindow.h"
#include "DatabaseQ.h"
#include <iostream>
#include <exception>

#include <QResource>
//int i = QResource::registerResource("./resource.rcc");

int main(int argc, char *argv[])
{
    try
    {
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
