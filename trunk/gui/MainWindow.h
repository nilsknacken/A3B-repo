#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QTableWidget>
#include "Dialog_Settings.h"
#include "Search_reservationQ.h"
#include "Search_vehicleQ.h"
#include "VehicleQ.h"
#include "ReservationQ.h"


namespace Ui
{
    class MainWindow;
}

class MainWindow
        : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

private slots:
    void on_tabWidgetMainTab_currentChanged(int index);

    // Menu-Bar
    void on_actionAbout_triggered();
    void on_actionSettings_triggered();
    void on_actionQuit_triggered();

    // Tab 1 - Reservate
    void on_pushButtonP1next_clicked();
    void on_pushButtonP1back_clicked();
    void on_pushButtonP1search_clicked();
    void on_pushButtonP1S_Car_clicked();
    void on_pushButtonP1M_Car_clicked();
    void on_pushButtonP1L_Car_clicked();
    void on_pushButtonP1S_Truck_clicked();
    void on_pushButtonP1L_Truck_clicked();

    // Tab 2 - Search
    void on_pushButtonP2search_clicked();
    void on_pushButtonP2delete_clicked();
    void on_pushButtonP2change_clicked();
    void on_pushButtonP2show_clicked();
    void on_pushButtonP2bok_nr_clicked();
    void on_pushButtonP2reg_nr_clicked();
    void on_pushButtonP2name_clicked();
    void on_pushButtonP2per_nr_clicked();
    void on_pushButtonP2phone_nr_clicked();
    void on_pushButtonP2date_clicked();

    // Tab 3 - Checkout
    void on_pushButtonP3remove_reservation_clicked();
    void on_pushButtonP3checkout_clicked();

    // Tab 4 - Checkin
    void on_pushButtonP4next_clicked();
    void on_pushButtonP4back_clicked();
    void on_checkBoxP4damages_yes_toggled(bool checked);

    // Tab 5 - Vehicle Search
    void on_pushButtonP5search_clicked();
    void on_tableWidgetP5_cellClicked(int row, int column);
    void on_pushButtonP5add_clicked();
    void on_pushButtonP5change_clicked();
    void on_pushButtonP5remove_clicked();

private:
    bool pushbuttonP5change_clicked = false;

    Ui::MainWindow *ui;
    QMessageBox* about;
    Settings* settings;
    Dialog_Settings* gui_settings;

    Reservation* current_resP1 = new Reservation();
    Reservation* current_resP2 = new Reservation();
    Reservation* current_resP3 = new Reservation();
    Reservation* current_resP4 = new Reservation();

    Vehicle* current_vehicleP1 = new Vehicle();
    Vehicle* current_vehicleP4 = new Vehicle();
    Vehicle* current_vehicleP5 = new Vehicle();

    Search_vehicle search_vehicleP1S_Car;
    Search_vehicle search_vehicleP1M_Car;
    Search_vehicle search_vehicleP1L_Car;
    Search_vehicle search_vehicleP1S_Truck;
    Search_vehicle search_vehicleP1L_Truck;

    Search_reservation search_resP2bok_nr;
    Search_reservation search_resP2reg_nr;
    Search_reservation search_resP2name;
    Search_reservation search_resP2per_nr;
    Search_reservation search_resP2phone_nr;
    Search_reservation search_resP2date;


    Search_reservation search_resP3;
    Search_reservation search_resP4;
    Search_vehicle search_vehicleP4;
    Search_vehicle search_vehicleP5;

    void generate_vehicle_list(std::vector<Vehicle*>, QTableWidget*);
    void generate_reservation_list(std::vector<Reservation*>, QTableWidget*);

    void custom_setup();

    void setup_tableWidgetP1S_Car() const;
    void setup_tableWidgetP1M_Car() const;
    void setup_tableWidgetP1L_Car() const;
    void setup_tableWidgetP1S_Truck() const;
    void setup_tableWidgetP1L_Truck() const;

    void setup_tableWidgetP2bok_nr() const;
    void setup_tableWidgetP2reg_nr() const;
    void setup_tableWidgetP2name() const;
    void setup_tableWidgetP2per_nr() const;
    void setup_tableWidgetP2phone_nr() const;
    void setup_tableWidgetP2date() const;

    void setup_tableWidgetP3() const;
    void setup_tableWidgetP4() const;
    void setup_tableWidgetP5() const;


    // StyleSheet
    void set_stylesheet(const QString&, QPushButton*&) const;
    const QString SS_SIDEMENU_ENABLE = "QPushButton {font: bold;color: white;}";
    const QString SS_SIDEMENU_DISABLE = "QPushButton {font: bold;color: grey;}";
};

// GUI error class
class GUI_error : public std::logic_error
{
public:
    explicit GUI_error(const std::string& what_arg) noexcept
        : logic_error(what_arg) {}

    explicit GUI_error(const char* what_arg) noexcept
        : logic_error(what_arg) {}
};


#endif // MAINWINDOW_H
