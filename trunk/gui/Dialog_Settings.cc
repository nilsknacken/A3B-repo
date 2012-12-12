/*
* FILENAMN:    Dialog_Settings.cc
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-12-12
*
* DESCRIPTION
*
* Hämtar inställningar från databasen. Gör det möjligt att ändra dessa, "OK" bekräftar.
* Dessutom raderar man databasen från inställningar.
*
* Created by:
* Conny:    on_buttonBox_accepted
*           on_buttonBox_rejected
*           on_pushButtonCleanDB_clicked
*           update_qtimeedit
*
* Andreas:  code structure / code skeleton / signals & slots
*           Dialog_Settings
*           ~Dialog_Settings
*           restore_appearance
*
*/

#include <QDialog>
#include "Dialog_Settings.h"
#include "ui_Dialog_Settings.h"

/////////////////////////////////////////////////////////////////////
// Dialog_Settings:
/////////////////////////////////////////////////////////////////////
// parameterized constructor
Dialog_Settings::Dialog_Settings(QWidget* parent, Settings* settings)
    : QDialog(parent),
      ui(new Ui::Dialog_Settings),
      settings_(settings)
{
    ui->setupUi(this);
    settings_->update();
    update_qtimeedit(settings_);
}

// Destructor
Dialog_Settings::~Dialog_Settings()
{
    delete ui;
}

// Save the settings
void Dialog_Settings::on_buttonBox_accepted()
{
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

// Restores the old settings
void Dialog_Settings::on_buttonBox_rejected()
{
    update_qtimeedit(settings_);
    restore_appearance();
}

// Clean database
void Dialog_Settings::on_pushButtonCleanDB_clicked()
{
    switch(QMessageBox::warning(this,
                                QString::fromUtf8("Rensa databas"),
                                QString::fromUtf8("Du är påväg att rensa databasen.\nVill du verkligen göra det?"),
                                QMessageBox::Cancel,
                                QMessageBox::Yes))
    {
    case QMessageBox::Yes:
    {
        settings_->clean_db();
        ui->pushButtonCleanDB->setDisabled(true);
        ui->pushButtonCleanDB->setText(QString::fromUtf8("Databas rensad"));
        break;
    }

    default:
        break;
    }
}

// Load qtimeedit with stored data from the database
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

// Make sure open < close
void Dialog_Settings::on_timeEditClose_timeChanged(const QTime& close)
{
    QTime open = ui->timeEditOpen->time();

    if(open == close)
    {
        QMessageBox::information(this,
                                 QString::fromUtf8("Felaktig inmatning"),
                                 QString::fromUtf8("Felaktig inmatning: "
                                                   "Du kan inte stänga "
                                                   "innan du har öppnat."),
                                 QMessageBox::Ok);

        ui->timeEditClose->setTime(close.addSecs(3600));
    }
}

void Dialog_Settings::on_timeEditOpen_timeChanged(const QTime& open)
{
    QTime close = ui->timeEditClose->time();

    if(open == close)
    {
        QMessageBox::information(this,
                                 QString::fromUtf8("Felaktig inmatning"),
                                 QString::fromUtf8("Felaktig inmatning: "
                                                   "Du kan inte stänga "
                                                   "innan du har öppnat."),
                                 QMessageBox::Ok);

        ui->timeEditOpen->setTime(open.addSecs(-3600));

    }
}
