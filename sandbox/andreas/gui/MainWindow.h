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


    //void on_stackedWidgetP1Main_currentChanged(int arg1);

private:
    //int p1_sidemenu_index = NULL;
    //int p2_sidemenu_index = NULL;

    Ui::MainWindow *ui;
    QMessageBox* about;
    Dialog_Settings* settings;

    void set_stylesheet(const QString&, QPushButton*&) const;
    void custom_setup();

    // StyleSheet
    const QString SS_SIDEMENU_ENABLE = "QPushButton {font: bold; color: white;}";
    const QString SS_SIDEMENU_DISABLE = "QPushButton {font: bold; color: grey;}";
    const QString SS_BUTTON_ENABLE = "QPushButton {background-color: rgb(0, 170, 255);}"
                                     "QPushButton:pressed {border-color: rgb(0, 170, 255);"
                                                          "background-color: rgb(255, 255, 255);"
                                                          "font:;color: black;}"
                                     "QPushButton:default {border-color: lightblue;}"
                                     "QPushButton:disabled {background-color: lightgrey;}";
    const QString SS_BUTTON_DISABLE = "QPushButton {background-color: lightgrey;}"
                                      "QPushButton:pressed {border-color: transparent;"
                                                           "background-color: lightgrey;"
                                                           "font:;color: white;}"
                                      "QPushButton:default {border-color: transparent;}";
};

#endif // MAINWINDOW_H
