#include <QApplication>
#include "MainWindow.h"

#include <QResource>
int i = QResource::registerResource("./resource.rcc");

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
