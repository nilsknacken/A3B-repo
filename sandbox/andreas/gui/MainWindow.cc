#include "MainWindow.h"
#include "ui_MainWindow.h"

using namespace std;

/////////////////////////////////////////////////////////////////////
// :
/////////////////////////////////////////////////////////////////////
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
                        "\tA3B bilpark\n"
                        "\tVersion 1.0\n\n"
                        "A3B bilpark är ... bla bla bla\n\n"
                        "Copyright 1951-2012 Such-and-such.  "
                        "<Någonting annat här.>\n\n"
                        "För teknisk support, ring 123456789 eller besök\n"
                        "https://github.com/nilsknacken/A3B-repo\n" );
    about->aboutQt(this, "suprice! :)");
}


/////////////////////////////////////////////////////////////////////
// Public Slots:
/////////////////////////////////////////////////////////////////////
void MainWindow::on_actionSettings_triggered()
{
    //settings = new Dialog_Settings;
    settings->show();
}

void MainWindow::on_actionQuit_triggered()
{
    exit(0);
}

void MainWindow::on_pushButtonP1Next_clicked()
{
    int index = ui->tabWidget1_2->currentIndex();

    if(index == 0)
    {
        ui->tabWidget1_2->setCurrentIndex(++index);
        //ui->pushButtonP1Back->setEnabled();
    }

    else if(index == 1)
    {
        ui->tabWidget1_2->setCurrentIndex(++index);
        ui->pushButtonP1Next->setText("Bekräfta");
    }

    else if(index == 2)
    {
        about->information(this, "Info",
                           "Nu ska någonting hända!\nTyp en bekräftelse" );
        ui->tabWidget1_2->setCurrentIndex(0);
        ui->pushButtonP1Next->setText("Nästa >");
        //ui->pushButtonP1Back->setDisabled();
    }
    else
        about->warning(this, "Internt fel", "Ett internt fel har uppstått!");
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
        ui->pushButtonP1Next->setText("Nästa >");
    }

    else
        about->warning(this, "Internt fel", "Ett internt fel har uppstått!");
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
