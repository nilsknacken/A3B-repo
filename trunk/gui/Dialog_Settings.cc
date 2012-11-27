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
