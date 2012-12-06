#include "Dialog_Settings.h"
#include "ui_Dialog_Settings.h"

#include <iostream>                                                      //// REMOVE

using namespace std;

Dialog_Settings::Dialog_Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Settings)
{
    ui->setupUi(this);
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

void Dialog_Settings::on_pushButton_clicked()
{
    //Rensa databas
}
