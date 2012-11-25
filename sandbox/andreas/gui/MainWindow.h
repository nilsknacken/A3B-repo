#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
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

private slots:
    void on_actionAbout_triggered();
    void on_actionSettings_triggered();
    void on_actionQuit_triggered();

    void on_pushButtonP1Next_clicked();
    void on_pushButtonP1Back_clicked();
    void on_pushButtonP1SmallCar_clicked();
    void on_pushButtonP1MiddleCar_clicked();
    void on_pushButtonP1BigCar_clicked();
    void on_pushButtonP1SmallTruck_clicked();
    void on_pushButtonP1BigTruck_clicked();
    void on_pushButtonP1Search_clicked();

public slots:
    //void on_pushButtonP1Next_clicked();
    //void on_pushButtonP1Back_clicked();
    
private:
    Ui::MainWindow *ui;
    QMessageBox* about;
    Dialog_Settings* settings;
};

#endif // MAINWINDOW_H
