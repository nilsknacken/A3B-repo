#include "Dialog_Settings.h"
#include "ui_Dialog_Settings.h"

#include <iostream>                                                      //// REMOVE

using namespace std;

Dialog_Settings::Dialog_Settings(QWidget *parent, Settings*& settings)
    : QDialog(parent),
      ui(new Ui::Dialog_Settings),
      settings_(settings)
{
    ui->setupUi(this);
    ui->timeEditOpen->setTime(QTime(settings->get_open_hour(),settings->get_open_min()));
    ui->timeEditClose->setTime(QTime(settings->get_close_hour(),settings->get_close_min()));
    ui->timeEditRental->setTime(Qtime(settings->get_min_rental(),0);
}

Dialog_Settings::~Dialog_Settings()
{
    cerr << "~Dialog_Settings()" << endl;                      //REMOVE
    delete ui;
}

void Dialog_Settings::on_buttonBox_accepted()
{
    //Spara inställningarna
}

void Dialog_Settings::on_pushButtonCleanDB_clicked()
{
    //Rensa databas
}
