#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //tabWidget tab(mainwindow,);
    //ui->tabWidget->resizeEvent(ui);

}

MainWindow::~MainWindow()
{
    delete ui;
}
