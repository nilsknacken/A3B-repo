#include "Dialog_Settings.h"
#include "ui_Dialog_Settings.h"

Dialog_Settings::Dialog_Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Settings)
{
    ui->setupUi(this);
}

Dialog_Settings::~Dialog_Settings()
{
    delete ui;
}
