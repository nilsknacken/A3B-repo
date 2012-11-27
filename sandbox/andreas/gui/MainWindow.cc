#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <iostream>  cou, cerr osv                                               //REMOVE

using namespace std;

/////////////////////////////////////////////////////////////////////
// Constructor, Destructor:
/////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    about(new QMessageBox(this)),
    settings(new Dialog_Settings(this))   //'this' behövs för att destruktorn ska köras automatiskt vid avslut.
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    cerr << "~MainWindow()" << endl;                                                 //REMOVE

    delete ui;
}


/////////////////////////////////////////////////////////////////////
// Public Slots:
/////////////////////////////////////////////////////////////////////
void MainWindow::on_actionAbout_triggered()
{
    about->about( this, tr("Om A3B bilpark"),
                        tr("\tA3B bilpark\n"
                           "\tVersion 1.0\n\n"
                           "A3B bilpark är ... bla bla bla\n\n"
                           "Copyright 1951-2012 Such-and-such."
                           "<Någonting annat här.>\n\n"
                           "För teknisk support, ring 123456789 eller besök\n"
                           "https://github.com/nilsknacken/A3B-repo\n"));
    about->aboutQt(this, "suprice! :)");
}


void MainWindow::on_actionSettings_triggered()
{
    //settings = new Dialog_Settings(this);
    settings->show();

    if (settings->exec())
    {
        // Ok knappen är tryckt här, spara inställningarna...
    }

    //delete settings;
}

void MainWindow::on_actionQuit_triggered()
{
    delete ui;
    delete about;
    delete settings;
    exit(0);
}

void MainWindow::on_pushButtonP1Next_clicked()
{
    int tab_index = ui->tabWidget1_2->currentIndex();

    if(tab_index == 0)
    {
        ui->tabWidget1_2->setCurrentIndex(++tab_index);
        //ui->pushButtonP1Back->setEnabled();
    }

    else if(tab_index == 1)
    {
        ui->tabWidget1_2->setCurrentIndex(++tab_index);
        ui->pushButtonP1Next->setText(tr("Bekräfta"));
    }

    else if(tab_index == 2)
    {
        about->information(this, tr("Info"), tr("Nu ska någonting hända!\nTyp en bekräftelse"));
        ui->tabWidget1_2->setCurrentIndex(0);
        ui->pushButtonP1Next->setText(tr("Nästa >"));
        //ui->pushButtonP1Back->setDisabled();
    }
    else
        about->warning(this, tr("Internt fel"), tr("Ett internt fel har uppstått!"));
}

void MainWindow::on_pushButtonP1Back_clicked()
{
    int index = ui->tabWidget1_2->currentIndex();

    if(index == 1)
    {
        ui->tabWidget1_2->setCurrentIndex(--index);
        //ui->pushButtonP1Back->setDisabled();
    }

    else if(index == 2)
    {
        ui->tabWidget1_2->setCurrentIndex(--index);
        ui->pushButtonP1Next->setText(tr("Nästa >"));
    }

    else
        about->warning(this, tr("Internt fel"), tr("Ett internt fel har uppstått!"));
}

void MainWindow::on_pushButtonP1SmallCar_clicked()
{
    ui->tabWidget1_3->setCurrentIndex(0);
}

void MainWindow::on_pushButtonP1MiddleCar_clicked()
{
    ui->tabWidget1_3->setCurrentIndex(1);
}

void MainWindow::on_pushButtonP1BigCar_clicked()
{
    ui->tabWidget1_3->setCurrentIndex(2);
}

void MainWindow::on_pushButtonP1SmallTruck_clicked()
{
    ui->tabWidget1_3->setCurrentIndex(3);
}

void MainWindow::on_pushButtonP1BigTruck_clicked()
{
    ui->tabWidget1_3->setCurrentIndex(4);
}

void MainWindow::on_pushButtonP1Search_clicked()
{

}
