#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "../backend/SettingsQ.h"

#include <iostream>  //cout, cerr osv                                               //REMOVE

using namespace std;

/////////////////////////////////////////////////////////////////////
// Constructor, Destructor:
/////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      about(new QMessageBox(this)),
      settings(new Settings()),
      gui_settings(new Dialog_Settings(this, settings))
{
    ui->setupUi(this);
    custom_setup();
    Database::open("default_db.sqlite");
}

MainWindow::~MainWindow()
{
    Database::close();
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

    int i = gui_settings->exec();

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
    delete gui_settings;
    exit(0);
}



/////////////////////////////////////////////////////////////////////
// Private functions:
/////////////////////////////////////////////////////////////////////
void MainWindow::set_stylesheet(const QString& stylesheet, QPushButton*& p) const
{
    p->setStyleSheet(stylesheet);
}


void MainWindow::custom_setup()
{
    on_pushButtonP1S_Car_clicked();
    on_pushButtonP2bok_nr_clicked();
    ui->stackedWidgetP1Main->setCurrentIndex(0);
    ui->tabWidgetMainTab->setCurrentIndex(0);
    ui->stackedWidgetP2toggle_date_string->setCurrentIndex(0);
    ui->stackedWidgetP4->setCurrentIndex(0);
    //ui->pushButtonP1back->setDisabled(true);
    //ui->pushButtonP1back->setDisabled(true);

    setup_tableWidgetP1S_Car();
    setup_tableWidgetP1M_Car();
    setup_tableWidgetP1L_Car();
    setup_tableWidgetP1S_Truck();
    setup_tableWidgetP1L_Truck();

    setup_tableWidgetP2bok_nr();
    setup_tableWidgetP2date();
    setup_tableWidgetP2date();
    setup_tableWidgetP2name();
    setup_tableWidgetP2per_nr();
    setup_tableWidgetP2phone_nr();
    setup_tableWidgetP2reg_nr();

    setup_tableWidgetP3();
    setup_tableWidgetP4();
    setup_tableWidgetP5();
}


void MainWindow::generate_vehicle_list(vector<Vehicle*> input, QTableWidget* tableWidget)
{
    if(! input.empty())
    {
        tableWidget->setRowCount(input.size());

        Vehicle* current = nullptr;
        for(unsigned long i = 0; i < input.size(); i++)
        {
            cerr << "i = " << i << endl;
            current = input[i];
            tableWidget->setItem(i,0,new QTableWidgetItem(current->get_reg_nr(),0));
            tableWidget->setItem(i,1,new QTableWidgetItem(current->get_brand(),0));
            tableWidget->setItem(i,2,new QTableWidgetItem(current->get_model(),0));
        }
        tableWidget->sortItems(0);
    }
    else
    {
        tableWidget->setRowCount(1);
        tableWidget->setItem(0,0,new QTableWidgetItem("Ingen post funnen!",0));

    }
}


void MainWindow::generate_reservation_list(vector<Reservation*> input, QTableWidget* tableWidget)
{
    if(! input.empty())
    {
        tableWidget->setRowCount(input.size());

        Reservation* current = nullptr;
        for(unsigned long i = 0; i < input.size(); i++)
        {
            cerr << "i = " << i << endl;
            current = input[i];
            tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(current->get_res_nr()),0));
            tableWidget->setItem(i,1,new QTableWidgetItem(current->get_reg_nr(),0));
            tableWidget->setItem(i,2,new QTableWidgetItem(current->get_name(),0));
            tableWidget->setItem(i,3,new QTableWidgetItem(current->get_status(),0));
            tableWidget->setItem(i,4,new QTableWidgetItem(current->get_start(),0));
            tableWidget->setItem(i,5,new QTableWidgetItem(current->get_end(),0));

        }
        tableWidget->sortItems(0);
    }
    else
    {
        tableWidget->setRowCount(1);
        tableWidget->setItem(0,0,new QTableWidgetItem("Ingen post funnen!",0));

    }
}
