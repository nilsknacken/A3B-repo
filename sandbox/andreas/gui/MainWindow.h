#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include "Dialog_Settings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    //void on_pushButtonP1Next_clicked();
    //void on_pushButtonP1Back_clicked();

private slots:
    // Menu-Bar
    void on_actionAbout_triggered();
    void on_actionSettings_triggered();
    void on_actionQuit_triggered();

    // Tab 1 - Reservate
    void on_pushButtonP1Next_clicked();
    void on_pushButtonP1Back_clicked();
    void on_pushButtonP1Search_clicked();
    void on_pushButtonP1S_Car_clicked();
    void on_pushButtonP1M_Car_clicked();
    void on_pushButtonP1L_Car_clicked();
    void on_pushButtonP1S_Truck_clicked();
    void on_pushButtonP1L_Truck_clicked();

    // Tab 2 - Search
    void on_pushButtonP2S_Car_clicked();
    void on_pushButtonP2M_Car_clicked();
    void on_pushButtonP2L_Car_clicked();
    void on_pushButtonP2S_Truck_clicked();
    void on_pushButtonP2L_Truck_clicked();


private:
    //int p1_sidemenu_index = NULL;
    //int p2_sidemenu_index = NULL;

    Ui::MainWindow *ui;
    QMessageBox* about;
    Dialog_Settings* settings;

    void set_focus_pushbutton(const QString&, QPushButton*&) const;
    void custom_setup();

    // StyleSheet
    const QString SS_SIDEMENU_ENABLE;
    const QString SS_SIDEMENU_DISABLE;
    const QString SS_BUTTON_ENABLE;
    const QString SS_BUTTON_DISABLE;

};

#endif // MAINWINDOW_H
