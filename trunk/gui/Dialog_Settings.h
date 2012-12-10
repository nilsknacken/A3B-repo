/*
* FILENAMN:    Dialog_Settings.h
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-12-05
*
* DESCRIPTION
*
* Deklaration av inställningsfönstret som körs via menyraden.
*
* Created by:
* Andreas:
*
*/

#ifndef DIALOG_SETTINGS_H
#define DIALOG_SETTINGS_H

#include <QMessageBox>
#include "SettingsQ.h"

namespace Ui
{
    class Dialog_Settings;
}

class Dialog_Settings : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_Settings(QWidget* = 0, Settings* = nullptr);
    ~Dialog_Settings();

private slots:
    void on_pushButtonCleanDB_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::Dialog_Settings* ui;
    Settings*            settings_;

    void update_qtimeedit(Settings*);
    void restore_appearance();
};

#endif // DIALOG_SETTINGS_H
