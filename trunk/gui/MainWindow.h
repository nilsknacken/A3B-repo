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

private slots:
    void on_tabWidgetMainTab_currentChanged(int);

    // Menu-Bar
    void on_actionAbout_triggered();
    void on_actionSettings_triggered();
    void on_actionQuit_triggered();

    // Tab 1 - Reservate
    void on_dateEditFrom_dateChanged();
    void on_timeEditFrom_timeChanged();
    void on_dateEditTo_dateChanged();
    void on_timeEditTo_timeChanged();
    void on_tableWidgetP1S_Car_itemSelectionChanged();
    void on_tableWidgetP1M_Car_itemSelectionChanged();
    void on_tableWidgetP1L_Car_itemSelectionChanged();
    void on_tableWidgetP1S_Truck_itemSelectionChanged();
    void on_tableWidgetP1L_Truck_itemSelectionChanged();
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
    void on_dateEditP2from_dateChanged(const QDate&);
    void on_lineEditSearch_returnPressed();


    void on_pushButtonP2bok_nr_clicked();
    void on_pushButtonP2reg_nr_clicked();
    void on_pushButtonP2name_clicked();
    void on_pushButtonP2phone_nr_clicked();
    void on_pushButtonP2date_clicked();

    void on_tableWidgetP2bok_nr_cellClicked(int, int);
    void on_tableWidgetP2reg_nr_cellClicked(int, int);
    void on_tableWidgetP2name_cellClicked(int, int);
    void on_tableWidgetP2phone_nr_cellClicked(int, int);
    void on_tableWidgetP2date_cellClicked(int, int);

    // Tab 3 - Checkout
    void on_pushButtonP3remove_reservation_clicked();
    void on_pushButtonP3checkout_clicked();
    void on_tableWidgetP3_itemSelectionChanged();

    // Tab 4 - Checkin
    void on_pushButtonP4next_clicked();
    void on_pushButtonP4back_clicked();
    void on_checkBoxP4damages_yes_toggled(bool);
    void on_tableWidgetP4_itemSelectionChanged();

    // Tab 5 - Vehicle Search
    void on_pushButtonP5search_clicked();
    void on_tableWidgetP5_cellClicked(int, int);
    void on_pushButtonP5add_clicked();
    void on_pushButtonP5change_and_save_clicked();
    void on_pushButtonP5remove_and_undo_clicked();
    void on_pushButtonP5back_clicked();
    void on_lineEditP5search_returnPressed();


private:
    // Variabler
    bool pushbuttonP5change_clicked  = false;
    bool change_reservation          = false;
    bool P1_table_is_clicked[5]      = {false};
    bool P2_table_is_clicked[5]      = {false};
    bool P2_change_button_enabled[5] = {false};

    // Konstanter
    const QString SS_SIDEMENU_ENABLE  = "QPushButton {font: bold;color: white;}";
    const QString SS_SIDEMENU_DISABLE = "QPushButton {font: bold;color: grey;}";
    const QString date_format         = "yyyy-MM-dd";
    const QString date_time_format    = "yyyy-MM-dd hh:mm";
    const QString S_Car_info          = QString::fromUtf8(
                "Liten bil\n\nLämplig för: 2 pers\n\nLastvolym: 500 liter");
    const QString M_Car_info          = QString::fromUtf8(
                "Mellanbil\n\nLämplig för: 4 pers\n\nLastvolym: 1 kubikmeter");
    const QString L_Car_info          = QString::fromUtf8(
                "Stor bil\n\nLämplig för: 4-5 pers\n\nLastvolym: 3 kubikmeter");
    const QString S_Truck_info        = QString::fromUtf8(
                "Liten lastbil\n\nLämplig för: 2 pers\n\nLastvolym: 10 kubikmeter");
    const QString L_Truck_info        = QString::fromUtf8(
                "Stor lastbil\n\nLämplig för: 3 pers\n\nLastvolym: 22 kubikmeter");

    // Objektpekare
    Ui::MainWindow*  ui;
    QMessageBox*     about;
    Settings*        settings;
    Dialog_Settings* gui_settings;

    Reservation*     new_reservationP1 = new Reservation();
    Vehicle*         new_vehicleP5     = new Vehicle();

    Reservation*     current_resP1; //    = new Reservation(); !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    Reservation*     current_resP2;//     = new Reservation();
    Reservation*     current_resP3;//     = new Reservation();
    Reservation*     current_resP4;//     = new Reservation();

    Vehicle*         current_vehicleP1;// = new Vehicle();
    Vehicle*         current_vehicleP3;// = new Vehicle();
    Vehicle*         current_vehicleP4;// = new Vehicle();
    Vehicle*         current_vehicleP5;// = new Vehicle();

    // Objekt
    Search_vehicle     search_vehicleP1S_Car;
    Search_vehicle     search_vehicleP1M_Car;
    Search_vehicle     search_vehicleP1L_Car;
    Search_vehicle     search_vehicleP1S_Truck;
    Search_vehicle     search_vehicleP1L_Truck;

    Search_reservation search_resP2bok_nr;
    Search_reservation search_resP2reg_nr;
    Search_reservation search_resP2name;
    Search_reservation search_resP2phone_nr;
    Search_reservation search_resP2date;

    Search_reservation search_resP3;
    Search_reservation search_resP4;
    Search_vehicle     search_vehicleP3;
    Search_vehicle     search_vehicleP4;
    Search_vehicle     search_vehicleP5;

    // Funktioner - Tab1 bokning
    void when_next_clicked(Search_vehicle&, QTableWidget*, int);
    void new_reservation();
    void change_customer_info();
    void set_date_now();
    void correct_date_time();
    void please_press_search();
    void please_press_search_helpfunc(QTableWidget*);

    // Funktioner - Tab2 sök
    void P2_change_button_appearance(int)        const;
    void show_function(Search_reservation&, int);
    void remove_function(Search_reservation&, int, int);
    void change_function(Search_reservation&, int);
    void P2_disable_buttons(int)                       const;

    // Funktioner - Tab3 utlämning
    void checkout_function();

    // Funktioner - Tab5 fordon
    void P5_change_appearance(bool)                    const;

    // Funktioner - Generella
    void set_stylesheet(const QString&, QPushButton*&) const;
    void generate_vehicle_list(std::vector<Vehicle*>, QTableWidget*);
    void generate_reservation_list(std::vector<Reservation*>, QTableWidget*);
    int  get_row_reservation(QTableWidget*)            const;
    int  get_row_vehicle(QTableWidget*)                const;

    // Funktioner - Setup
    void custom_setup();
    void setup_stylesheet()                            const;
    void setup_tableWidget_vehicle(QTableWidget*)      const;
    void setup_tableWidget_reservation(QTableWidget*)  const;

    void setup_tableWidgetP1S_Car()                    const;
    void setup_tableWidgetP1M_Car()                    const;
    void setup_tableWidgetP1L_Car()                    const;
    void setup_tableWidgetP1S_Truck()                  const;
    void setup_tableWidgetP1L_Truck()                  const;

    void setup_tableWidgetP2bok_nr()                   const;
    void setup_tableWidgetP2reg_nr()                   const;
    void setup_tableWidgetP2name()                     const;
    void setup_tableWidgetP2phone_nr()                 const;
    void setup_tableWidgetP2date()                     const;

    void setup_tableWidgetP3()                         const;
    void setup_tableWidgetP4()                         const;
    void setup_tableWidgetP5()                         const;
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
