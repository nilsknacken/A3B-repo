#include "Dialog_Settings.h"
#include "ui_Dialog_Settings.h"

#include <iostream>                                                      //// REMOVE
#include <QDialog>

using namespace std;

Dialog_Settings::Dialog_Settings(QWidget *parent, Settings* settings)
    : QDialog(parent),
      ui(new Ui::Dialog_Settings),
      settings_(settings)
{
    ui->setupUi(this);
    settings->update();
    uppdate_qtimeedit(settings);
}

Dialog_Settings::~Dialog_Settings()
{
    cerr << "~Dialog_Settings()" << endl;                      //REMOVE
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
}

void Dialog_Settings::on_pushButtonCleanDB_clicked()
{
    //Rensa databas
    int i = QMessageBox::warning(this,
                                 QString::fromUtf8("Rensa databas"),
                                 QString::fromUtf8("Du är påväg att rensa databasen.\nVill du verkligen göra det?"),
                                 QMessageBox::Cancel, QMessageBox::Yes);
    if(i == 16384)
    {
        cerr << "Databasen är inte rensad egentligen, detta ska implementeras!" << endl; //!!!!!!!!
        QMessageBox::information(this,
                                 QString::fromUtf8("Bekräftelse"),
                                 QString::fromUtf8("Nu är databasen rensad."),
                                 QMessageBox::Ok);
    }
}

void Dialog_Settings::on_buttonBox_rejected()
{
    uppdate_qtimeedit(settings_);
}

void Dialog_Settings::uppdate_qtimeedit(Settings* settings)
{
    ui->timeEditOpen  ->setTime(QTime(settings->get_open_hour(), settings->get_open_min()));
    ui->timeEditClose ->setTime(QTime(settings->get_close_hour(),settings->get_close_min()));
    ui->timeEditRental->setTime(QTime(settings->get_min_rental(),0));
}
