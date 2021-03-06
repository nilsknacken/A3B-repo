#ifndef DIALOG_SETTINGS_H
#define DIALOG_SETTINGS_H

#include <QDialog>

#include "../backend/SettingsQ.h"

namespace Ui
{
    class Dialog_Settings;
}

class Dialog_Settings : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog_Settings(QWidget *parent = 0, Settings* = nullptr);
    ~Dialog_Settings();
    
private slots:
    void on_buttonBox_accepted();
    void on_pushButtonCleanDB_clicked();

private:
    Ui::Dialog_Settings *ui;
    Settings* settings_;
};

#endif // DIALOG_SETTINGS_H
