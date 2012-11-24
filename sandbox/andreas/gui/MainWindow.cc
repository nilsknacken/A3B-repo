#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    about(new QMessageBox(this)),
    settings(new Dialog_Settings(this))   //'this' behövs för att destruktorn ska köras
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete about;      //tror inte denna ska behövas när 'this' finns i konstruktorn?
    delete settings;   //tror inte denna ska behövas när 'this' finns i konstruktorn?
}


void MainWindow::on_actionAbout_triggered()
{
    about->about( this, "Om A3B bilpark",
                        "A3B bilpark är ... bla bla bla\n\n"
                        "Copyright 1951-2012 Such-and-such.  "
                        "<Någonting annat här.>\n\n"
                        "För teknisk support, ring 123456789 eller besök\n"
                        "https://github.com/nilsknacken/A3B-repo\n" );
    about->aboutQt(this, "suprice! :)");
}

void MainWindow::on_actionSettings_triggered()
{
    //settings = new Dialog_Settings;
    settings->show();
}

void MainWindow::on_actionQuit_triggered()
{
    exit(0);
}
