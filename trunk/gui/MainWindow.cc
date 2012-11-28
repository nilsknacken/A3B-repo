#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <iostream>  //cou, cerr osv                                               //REMOVE

using namespace std;

/////////////////////////////////////////////////////////////////////
// Constructor, Destructor:
/////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    about(new QMessageBox(this)),
    settings(new Dialog_Settings(this)),   //'this' behövs för att destruktorn ska köras automatiskt vid avslut.
    SS_SIDEMENU_ENABLE("QPushButton {font: bold; color: white;}"),
    SS_SIDEMENU_DISABLE("QPushButton {font: bold; color: grey;}"),
    SS_BUTTON_ENABLE("QPushButton {background-color: rgb(0, 170, 255);"
                     "QPushButton:pressed {border-color: rgb(0, 170, 255);"
                     "background-color: rgb(255, 255, 255);"
                     "QPushButton:default {border-color: lightblue;}"),
    SS_BUTTON_DISABLE("QPushButton {background-color: light grey;}"
                      "QPushButton:pressed {border-color: none;"
                      "background-color: grey;}"
                      "QPushButton:default {border-color: none;}")
{
    ui->setupUi(this);
    custom_setup();
}

MainWindow::~MainWindow()
{
    cerr << "~MainWindow()" << endl;                                                 //REMOVE

    delete ui;
}


/////////////////////////////////////////////////////////////////////
// Private Slots:
/////////////////////////////////////////////////////////////////////
void MainWindow::on_actionAbout_triggered()
{
    about->about( this, QString::fromUtf8("Om A3B bilpark"),
                        QString::fromUtf8("\t<b>A3B bilpark</b><br>"
                                          "\tVersion 1.0<br><br>"
                                          "A3B bilpark är ... bla bla bla<br><br>"
                                          "Copyright 1951-2012 Such-and-such."
                                          "<Någonting annat här.><br><br>"
                                          "För teknisk support, ring 123456789 eller besök<br>"
                                          "<url>https://github.com/nilsknacken/A3B-repo</url><br>"));
    about->aboutQt(this, "suprice! :)");
}


void MainWindow::on_actionSettings_triggered()
{
    //settings = new Dialog_Settings(this);
    //settings->show();

    int i = settings->exec();

    (void)i;

    //if (settings->exec())
    //{
        // Ok knappen är tryckt här, spara inställningarna...
    //}

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
    int tab_index = ui->stackedWidgetP1Main->currentIndex();

    if(tab_index == 0)
    {
        ui->stackedWidgetP1Main->setCurrentIndex(++tab_index);
        //ui->pushButtonP1Back->setEnabled();
    }

    else if(tab_index == 1)
    {
        ui->stackedWidgetP1Main->setCurrentIndex(++tab_index);
        ui->pushButtonP1Next->setText(QString::fromUtf8("Bekräfta"));
    }

    else if(tab_index == 2)
    {
        about->information(this, QString::fromUtf8("Info"), QString::fromUtf8("Nu ska någonting hända!\nTyp en bekräftelse"));
        ui->stackedWidgetP1Main->setCurrentIndex(0);
        ui->pushButtonP1Next->setText(QString::fromUtf8("Nästa >"));
        //ui->pushButtonP1Back->setDisabled();
    }
    else
        about->warning(this, QString::fromUtf8("Internt fel"), QString::fromUtf8("Ett internt fel har uppstått!"));
}

void MainWindow::on_pushButtonP1Back_clicked()
{
    int index = ui->stackedWidgetP1Main->currentIndex();

    if(index == 1)
    {
        ui->stackedWidgetP1Main->setCurrentIndex(--index);
        //ui->pushButtonP1Back->setDisabled();
    }

    else if(index == 2)
    {
        ui->stackedWidgetP1Main->setCurrentIndex(--index);
        ui->pushButtonP1Next->setText(QString::fromUtf8("Nästa >"));
    }

    else
        about->warning(this, QString::fromUtf8("Internt fel"), QString::fromUtf8("Ett internt fel har uppstått!"));
}








void MainWindow::on_pushButtonP1S_Car_clicked()
{
    ui->stackedWidgetP1->setCurrentIndex(0);
    set_focus_pushbutton(SS_SIDEMENU_ENABLE, ui->pushButtonP1S_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1M_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Truck);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Truck);
}

void MainWindow::on_pushButtonP1M_Car_clicked()
{
    ui->stackedWidgetP1->setCurrentIndex(1);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Car);
    set_focus_pushbutton(SS_SIDEMENU_ENABLE, ui->pushButtonP1M_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Truck);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Truck);
}

void MainWindow::on_pushButtonP1L_Car_clicked()
{
    ui->stackedWidgetP1->setCurrentIndex(2);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1M_Car);
    set_focus_pushbutton(SS_SIDEMENU_ENABLE, ui->pushButtonP1L_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Truck);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Truck);
}

void MainWindow::on_pushButtonP1S_Truck_clicked()
{
    ui->stackedWidgetP1->setCurrentIndex(3);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1M_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Car);
    set_focus_pushbutton(SS_SIDEMENU_ENABLE, ui->pushButtonP1S_Truck);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Truck);
}

void MainWindow::on_pushButtonP1L_Truck_clicked()
{
    ui->stackedWidgetP1->setCurrentIndex(4);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1M_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Truck);
    set_focus_pushbutton(SS_SIDEMENU_ENABLE, ui->pushButtonP1L_Truck);
}

void MainWindow::on_pushButtonP1Search_clicked()
{

}


void MainWindow::on_pushButtonP2S_Car_clicked()
{
    ui->stackedWidgetP2->setCurrentIndex(0);
    set_focus_pushbutton(SS_SIDEMENU_ENABLE, ui->pushButtonP2S_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2M_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2L_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2S_Truck);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2L_Truck);
}

void MainWindow::on_pushButtonP2M_Car_clicked()
{
    ui->stackedWidgetP2->setCurrentIndex(1);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2S_Car);
    set_focus_pushbutton(SS_SIDEMENU_ENABLE, ui->pushButtonP2M_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2L_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2S_Truck);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2L_Truck);
}

void MainWindow::on_pushButtonP2L_Car_clicked()
{
    ui->stackedWidgetP2->setCurrentIndex(2);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2S_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2M_Car);
    set_focus_pushbutton(SS_SIDEMENU_ENABLE, ui->pushButtonP2L_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2S_Truck);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2L_Truck);
}

void MainWindow::on_pushButtonP2S_Truck_clicked()
{
    ui->stackedWidgetP2->setCurrentIndex(3);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2S_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2M_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2L_Car);
    set_focus_pushbutton(SS_SIDEMENU_ENABLE, ui->pushButtonP2S_Truck);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2L_Truck);
}

void MainWindow::on_pushButtonP2L_Truck_clicked()
{
    ui->stackedWidgetP2->setCurrentIndex(4);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2S_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2M_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2L_Car);
    set_focus_pushbutton(SS_SIDEMENU_DISABLE, ui->pushButtonP2S_Truck);
    set_focus_pushbutton(SS_SIDEMENU_ENABLE, ui->pushButtonP2L_Truck);
}






/////////////////////////////////////////////////////////////////////
// Private functions:
/////////////////////////////////////////////////////////////////////
void MainWindow::set_focus_pushbutton(const QString& stylesheet, QPushButton*& p) const
{

    p->setStyleSheet(stylesheet);
/*
    if(enable)
    {
        p->setStyleSheet(SS_SIDEMENU_ENABLE);
    }
    else
    {
        p->setStyleSheet(SS_SIDEMENU_DISABLE);
    }*/
}


void MainWindow::custom_setup()
{
    on_pushButtonP1S_Car_clicked();
    on_pushButtonP2S_Car_clicked();
    //ui->stackedWidgetP1->setCurrentIndex(0);
    //ui->stackedWidgetP2->setCurrentIndex(0);
    ui->stackedWidgetP1Main->setCurrentIndex(0);
    ui->tabWidgetMainTab->setCurrentIndex(0);
}
