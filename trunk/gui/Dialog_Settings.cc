/*
* FILENAMN:    Dialog_Settings.cpp
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-12-05
*
* DESCRIPTION
*
* Hämtar inställningar från databasen. Gör det möjligt att ändra dessa, "OK" bekräftar.
* Dessutom raderar man databasen från inställningar.
*
* Created by:
* Conny:
*  on_buttonBox_accepted
*  on_buttonBox_rejected
*  on_pushButtonCleanDB_clicked
*  update_qtimeedit
*
* Andreas:
*  Dialog_Settings
*  ~Dialog_Settings
*  restore_appearance
*
*/

#include "Dialog_Settings.h"
#include "ui_Dialog_Settings.h"
#include <QDialog>
#include <iostream>                                                             //// REMOVE

using namespace std;

Dialog_Settings::Dialog_Settings(QWidget* parent, Settings* settings)
    : QDialog(parent),
      ui(new Ui::Dialog_Settings),
      settings_(settings)
{
    ui->setupUi(this);
    settings_->update();
    update_qtimeedit(settings_);
}

Dialog_Settings::~Dialog_Settings()
{
    cerr << "~Dialog_Settings()" << endl;                                        //REMOVE
    delete ui;
}

void Dialog_Settings::on_buttonBox_accepted()
{
    //Spara inställningarna
    QTime open       = ui->timeEditOpen  ->time();
    QTime close      = ui->timeEditClose ->time();
    QTime min_rental = ui->timeEditRental->time();

    settings_->set_open_hour(open.hour());
    settings_->set_open_min(open.minute());
    settings_->set_close_hour(close.hour());
    settings_->set_close_min(close.minute());
    settings_->set_min_rental(min_rental.hour());

    settings_->save();
    restore_appearance();
}

void Dialog_Settings::on_buttonBox_rejected()
{
    update_qtimeedit(settings_);
    restore_appearance();
}

void Dialog_Settings::on_pushButtonCleanDB_clicked()
{
    //Rensa databas
    switch(QMessageBox::warning(this,
                                QString::fromUtf8("Rensa databas"),
                                QString::fromUtf8("Du är påväg att rensa databasen.\nVill du verkligen göra det?"),
                                QMessageBox::Cancel,
                                QMessageBox::Yes))
    {
    case QMessageBox::Yes:
    {
        cerr << "Databasen är inte rensad egentligen, detta ska implementeras!" << endl; //!!!!!!!!
        ui->pushButtonCleanDB->setDisabled(true);
        ui->pushButtonCleanDB->setText(QString::fromUtf8("Databas rensad"));
        //QMessageBox::information(this,
        //                         QString::fromUtf8("Bekräftelse"),
        //                         QString::fromUtf8("Nu är databasen rensad."),
        //                         QMessageBox::Ok);
        break;
    }

    default:
        break;
    }
}


void Dialog_Settings::update_qtimeedit(Settings* settings)
{
    ui->timeEditOpen  ->setTime(QTime(settings->get_open_hour(), settings->get_open_min()));
    ui->timeEditClose ->setTime(QTime(settings->get_close_hour(),settings->get_close_min()));
    ui->timeEditRental->setTime(QTime(settings->get_min_rental(),0));
}

void Dialog_Settings::restore_appearance()
{
    ui->pushButtonCleanDB->setDisabled(false);
    ui->pushButtonCleanDB->setText(QString::fromUtf8("Rensa databas"));
}
