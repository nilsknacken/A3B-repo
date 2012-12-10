/*
* FILENAMN:    MainWindow.cpp
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-12-05
*
* DESCRIPTION
*
* Här defineras huvudfönstrets funktioner.
*
* Created by:
* Martin:   generate_vehicle_list
*           generate_reservation_list
*           setup_tableWidget_vehicle
*           setup_tableWidget_reservation
*
* Andreas:  code structure / code skeleton / signal & slots
*           MainWindow
*           ~MainWindow
*           on_actionAbout_triggered
*           on_actionSettings_triggered
*           on_actionQuit_triggered
*           set_stylesheet
*           custom_setup                       + någon mer
*           setup_stylesheet
*           on_tabWidgetMainTab_currentChanged + någon mer
*
*Adam:      on_actionAbout_triggered
*
*/

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SettingsQ.h"
#include <QMessageBox>


#include <iostream>  //cout, cerr osv                                               //REMOVE

/////////////////////////////////////////////////////////////////////
// Constructor, Destructor:
/////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      about(new QMessageBox(this)),
      settings(new Settings()),
      gui_settings(new Dialog_Settings(this, settings))
{
    ui->setupUi(this);
    custom_setup();
    setup_stylesheet();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete about;
    delete settings;
    delete gui_settings;

    delete new_reservationP1;
    delete new_vehicleP5;
}


/////////////////////////////////////////////////////////////////////
// Private Slots:
/////////////////////////////////////////////////////////////////////
void MainWindow::on_actionAbout_triggered()
{
    about->about(this, QString::fromUtf8("Om A3B bilpark"),
                       QString::fromUtf8("<b>A3B bilpark</b><br>"
                                         "Version 1.0<br><br>"

                                         "A3B bilpark är en programmvara utvecklad av den nystartade gruppen A3B "
                                         "som består utav 4 stycken independent-utvecklare. "
                                         "Programmvaran är gjord så att aktörer inom biluthyrning, stora som små, "
                                         "ska kunna sköta sina uthyrningar på ett smidigt sätt.<br><br>"

                                         "För teknisk support, konsultera README-filen eller kontakta oss på någon utav följande mailadresser:<br>"
                                         "maran703@student.liu.se, conan414@student.liu.se, andbo467@student.liu.se, "
                                         "adaan690@student.liu.se <br><br>"

                                         "Mvh A3B - \"Because we do more than take you from A 2 B\" <br><br>"
                                         "&copy;2012 A3B"));
}


void MainWindow::on_actionSettings_triggered()
{
    gui_settings->exec();
}

void MainWindow::on_actionQuit_triggered()
{
    delete ui;
    delete about;
    delete settings;
    delete gui_settings;
    delete current_resP1;
    delete current_resP2;
    delete current_resP3;
    delete current_resP4;
    delete current_vehicleP1;
    delete current_vehicleP3;
    delete current_vehicleP4;
    delete current_vehicleP5;
    exit(EXIT_SUCCESS);
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
    ui->stackedWidgetP4->setCurrentIndex(0);
    ui->stackedWidgetP5->setCurrentIndex(0);

    setup_tableWidgetP1S_Car();
    setup_tableWidgetP1M_Car();
    setup_tableWidgetP1L_Car();
    setup_tableWidgetP1S_Truck();
    setup_tableWidgetP1L_Truck();

    setup_tableWidgetP2bok_nr();
    setup_tableWidgetP2date();
    setup_tableWidgetP2date();
    setup_tableWidgetP2name();
    setup_tableWidgetP2phone_nr();
    setup_tableWidgetP2reg_nr();

    setup_tableWidgetP3();
    setup_tableWidgetP4();
    setup_tableWidgetP5();

    set_date_now();
    please_press_search();
}

void MainWindow::setup_stylesheet() const
{
    //Set stylesheet
    ui->frameP1vehicle_info->setStyleSheet("QFrame{"
                                           "border-left: 1px solid lightgrey;"
                                           "border-right: none;"
                                           "border-bottom: none;"
                                           "border-top: none; }"
                                           "QLabel{"
                                           "border: none; }");
}

void MainWindow::generate_vehicle_list(std::vector<Vehicle*> input, QTableWidget* tableWidget)
{
    tableWidget->clearContents();

    if(! input.empty())
    {
        tableWidget->setRowCount(input.size());
        Vehicle* current = nullptr;

        tableWidget->setSortingEnabled(false);
        for(unsigned long i = 0; i < input.size(); i++)
        {
            current = input[i];
            QString id = QString::number(i);

            tableWidget->setItem(i,0,new QTableWidgetItem(current->get_reg_nr(),0));
            tableWidget->setItem(i,1,new QTableWidgetItem(current->get_type(),0));
            tableWidget->setItem(i,2,new QTableWidgetItem(current->get_brand(),0));
            tableWidget->setItem(i,3,new QTableWidgetItem(current->get_model(),0));
            tableWidget->setItem(i,4, new QTableWidgetItem(id,0));
        }
        tableWidget->setSortingEnabled(true);
        tableWidget->sortItems(0);
        tableWidget->setDisabled(false);
    }
    else
    {
        tableWidget->setRowCount(1);

        QTableWidgetItem* reg = new QTableWidgetItem();
        QTableWidgetItem* type = new QTableWidgetItem();
        QTableWidgetItem* brand = new QTableWidgetItem();

        reg->setText("Ingen");
        type->setText("post");
        brand->setText("funnen!");

        tableWidget->setItem(0, 0, reg);
        tableWidget->setItem(0, 1, type);
        tableWidget->setItem(0, 2, brand);

        tableWidget->setDisabled(true);

    }
}


void MainWindow::generate_reservation_list(std::vector<Reservation*> input, QTableWidget* tableWidget)
{
    tableWidget->clearContents();

    if(! input.empty())
    {
        tableWidget->setSortingEnabled(false);

        tableWidget->setRowCount(input.size());

        Reservation* current = nullptr;
        for(unsigned long i = 0; i < input.size(); i++)
        {
            current = input[i];
            QString id = QString::number(i);
            tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(current->get_res_nr()),0));
            tableWidget->setItem(i,1,new QTableWidgetItem(current->get_reg_nr(),0));
            tableWidget->setItem(i,2,new QTableWidgetItem(current->get_name(),0));
            tableWidget->setItem(i,3,new QTableWidgetItem(current->get_status(),0));
            tableWidget->setItem(i,4,new QTableWidgetItem(current->get_start(),0));
            tableWidget->setItem(i,5,new QTableWidgetItem(current->get_end(),0));
            tableWidget->setItem(i,6,new QTableWidgetItem(id,0));

        }
        tableWidget->setSortingEnabled(true);
        tableWidget->setDisabled(false);
    }
    else
    {
        tableWidget->setRowCount(1);

        QTableWidgetItem* reg = new QTableWidgetItem();
        QTableWidgetItem* name = new QTableWidgetItem();
        QTableWidgetItem* status = new QTableWidgetItem();

        reg->setText("Ingen");
        name->setText("post");
        status->setText("funnen!");

        tableWidget->setItem(0, 0, reg);
        tableWidget->setItem(0, 1, name);
        tableWidget->setItem(0, 2, status);

        tableWidget->setDisabled(true);
    }
}

int MainWindow::get_row_reservation(QTableWidget* tableWidget) const
{
    int currentRow = tableWidget->currentRow();

    if (currentRow >= 0)
    {
        QString id = tableWidget->item(tableWidget->currentRow(),6)->text();
        return id.toInt();
    }
    else
    {
        tableWidget->setCurrentCell(-1,-1);
        return -1;
    }
}

int MainWindow::get_row_vehicle(QTableWidget* tableWidget) const
{
    int currentRow = tableWidget->currentRow();

    if (currentRow >= 0)
    {
        QString id = tableWidget->item(tableWidget->currentRow(),4)->text();
        return id.toInt();
    }
    else
    {
        tableWidget->setCurrentCell(-1,-1);
        return -1;
    }
}

void MainWindow::on_tabWidgetMainTab_currentChanged(int index)
{
    if(index == 0) // bokning
    {
       // set_date_now();
    }

    else if (index == 1) //sök
    {}

    else if (index == 2) // lämna ut
    {
        QString kommande = "kommande";
        generate_reservation_list(search_resP3.status(kommande), ui->tableWidgetP3);
        ui->pushButtonP3checkout->setDisabled(true);
        ui->pushButtonP3remove_reservation->setDisabled(true);
    }
    else if (index == 3) // återlämna
    {
        QString aktiv = "aktiv";
        generate_reservation_list(search_resP4.status(aktiv), ui->tableWidgetP4);
        ui->pushButtonP4next->setDisabled(true);
    }
    else if(index == 4) // fordon
        on_pushButtonP5search_clicked();
}

void MainWindow::setup_tableWidget_vehicle(QTableWidget* tableWidget) const
{
    tableWidget->setColumnCount(5);
    tableWidget->setHorizontalHeaderLabels(QStringList()
                                           << QString::fromUtf8("Reg. nr")
                                           << QString::fromUtf8("Typ")
                                           << QString::fromUtf8("Fabrikat")
                                           << QString::fromUtf8("Modell")
                                           << QString::fromUtf8("ID"));
    tableWidget->setShowGrid(false);
    tableWidget->hideColumn(4);
    tableWidget->verticalHeader()->hide();
    tableWidget->setAlternatingRowColors(true);
    tableWidget->setEditTriggers(0);
    tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setSortingEnabled(true);
}

void MainWindow::setup_tableWidget_reservation(QTableWidget* tableWidget) const
{
    tableWidget->setColumnCount(7);
    tableWidget->setHorizontalHeaderLabels(QStringList()
                                           << QString::fromUtf8("Res. nr")
                                           << QString::fromUtf8("Reg. nr")
                                           << QString::fromUtf8("Namn")
                                           << QString::fromUtf8("Status")
                                           << QString::fromUtf8("Starttid")
                                           << QString::fromUtf8("Slutttid")
                                           << QString::fromUtf8("ID"));
    tableWidget->setShowGrid(false);
    tableWidget->hideColumn(6);
    tableWidget->verticalHeader()->hide();
    tableWidget->setAlternatingRowColors(true);
    tableWidget->setEditTriggers(0);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    tableWidget->setSortingEnabled(true);
}
