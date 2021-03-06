/*
* Filename:    MainWindowP1.cc
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-12-12
*
* DESCRIPTION:
*
* Implementation av tab nr 1 = Bokning.
* Hanterar vad som händer när man gör något under bokningsfliken.
*
* Created by:
* Andreas:  code structure / code skeleton / signal & slots
*           on_pushButtonP1next_clicked
*           on_pushButtonP1back_clicked
*           on_pushButtonP1S_Car_clicked
*           on_pushButtonP1M_Car_clicked
*           on_pushButtonP1L_Car_clicked
*           on_pushButtonP1S_Truck_clicked
*           on_pushButtonP1L_Truck_clicked
*           on_pushButtonP1search_clicked
*           on_tableWidgetP1S_Car_itemSelectionChanged
*           on_tableWidgetP1M_Car_itemSelectionChanged
*           on_tableWidgetP1L_Car_itemSelectionChanged
*           on_tableWidgetP1S_Truck_itemSelectionChanged
*           on_tableWidgetP1L_Truck_itemSelectionChanged
*
*
* Martin:   on_pushButtonP1next_clicked
*           on_pushButtonP1search_clicked
*           when_next_clicked
*           new_reservation
*           change_customer_info
*           set_date_now
*           correct_date_time
*           please_press_search
*           please_press_search_helpfunc
*           on_dateEditFrom_dateChanged
*           on_dateEditTo_dateChanged
*           on_timeEditFrom_timeChanged
*           on_timeEditTo_timeChanged
*           setup_tableWidgetP1S_Car
*           setup_tableWidgetP1M_Car
*           setup_tableWidgetP1L_Car
*           setup_tableWidgetP1S_Truck
*           setup_tableWidgetP1L_Truck
*
*/

#include "MainWindow.h"
#include "ui_MainWindow.h"



/////////////////////////////////////////////////////////////////////
//  MainWindow Tab 1 / Bokning Tab
/////////////////////////////////////////////////////////////////////
void MainWindow::when_next_clicked(Search_vehicle& search_vehicle,
                                   QTableWidget* tableWidget,
                                   int tab_index)
{
    int row = get_row_vehicle(tableWidget);

    QString reg_nr = search_vehicle.get_current_result()[row]->get_reg_nr();
    ui->labelP1selected_regnr_var->setText(reg_nr);
    current_vehicleP1 = search_vehicle.get_current_result()[row];

    ui->stackedWidgetP1Main->setCurrentIndex(++tab_index);
    ui->pushButtonP1back->setDisabled(false);
}

void MainWindow::new_reservation()
{
    QString reg_nr = current_vehicleP1->get_reg_nr();
    QString start = ui->labelP1selected_from_var->text();
    QString end = ui->labelP1selected_to_var->text();
    QString name = ui->lineEditP1name_var->text();
    QString tel = ui->lineEditP1phone_nr_var->text();
    QString address = ui->lineEditP1address_var->text();
    QString postal_nr = ui->lineEditP1postal_nr_var->text();
    QString city = ui->lineEditP1city_var->text();

    if(tel.isEmpty())
        throw GUI_error("Du måste ange telefonnummer.");

    else if(address.isEmpty())
        throw GUI_error("Du måste ange adress.");

    else if(city.isEmpty())
        throw GUI_error("Du måste ange stad.");

    else
        new_reservationP1 = make_reservation(reg_nr,
                                         start,
                                         end,
                                         name,
                                         tel,
                                         address,
                                         postal_nr,
                                         city);
}

void MainWindow::change_customer_info()
{
    ui->tabWidgetMainTab->setCurrentIndex(0);
    ui->tabWidgetMainTab->setTabText(0, QString::fromUtf8("Ändring"));
    ui->labelP1selected_regnr_var->setText(current_resP1->get_reg_nr());
    ui->labelP1selected_from_var->setText(current_resP1->get_start());
    ui->labelP1selected_to_var->setText(current_resP1->get_end());
    ui->lineEditP1name_var->setText(current_resP1->get_name());
    ui->lineEditP1phone_nr_var->setText(current_resP1->get_tel());
    ui->lineEditP1address_var->setText(current_resP1->get_adress());
    ui->lineEditP1postal_nr_var->setText(current_resP1->get_postal_nr());
    ui->lineEditP1city_var->setText(current_resP1->get_city());
    ui->stackedWidgetP1Main->setCurrentIndex(1);
    ui->pushButtonP1back->setEnabled(true);
    ui->pushButtonP1next->setEnabled(true);
    ui->tabWidgetMainTab->setTabEnabled(1, false);
    ui->tabWidgetMainTab->setTabEnabled(2, false);
    ui->tabWidgetMainTab->setTabEnabled(3, false);
    ui->tabWidgetMainTab->setTabEnabled(4, false);
    change_reservation = true;
}

void MainWindow::set_date_now()
{
    QDateTime now = QDateTime::currentDateTime();
    QTime time = QTime::currentTime();
    time.setHMS(time.hour(), 0,0);
    now.setTime(time);

    ui->dateEditFrom->setMinimumDate(now.date());
    ui->dateEditFrom->setDate(now.date());
    ui->timeEditFrom->setTime(now.time());

    correct_date_time();

    ui->dateEditTo->setDate(ui->dateEditTo->minimumDate());
    ui->timeEditTo->setTime(ui->timeEditTo->minimumTime());
}

void MainWindow::correct_date_time()
{
    // Set minumin from to now
    QDateTime now = QDateTime::currentDateTime();
    QTime time = QTime::currentTime();
    time.setHMS(time.hour(), 0,0);
    now.setTime(time);

    QTime open = settings->get_open_QTime();
    QTime close = settings->get_close_QTime();
    QDate to_date = ui->dateEditTo->date();
    QDate from_date = ui->dateEditFrom->date();

    ui->dateEditFrom->setMinimumDate(now.date());
    ui->timeEditFrom->setMinimumTime(open);

    // Set max time to closing time
    ui->timeEditFrom->setMaximumTime(close);
    ui->timeEditTo->setMaximumTime(close);
    ui->dateEditTo->setMaximumDate(now.date().addMonths(12));

    // Check other conditions such as minimum rental times
    int min_rental = settings->get_min_rental();
    QTime min_to = ui->timeEditFrom->time().addSecs(3600 * min_rental);

    if(from_date == to_date)
    {
        if(open <= min_to && min_to <= close)
        {
            ui->timeEditTo->setMinimumTime(min_to);
        }

        else
        {
            ui->timeEditTo->setMinimumTime(open);
            ui->dateEditTo->setMinimumDate(from_date.addDays(1));
        }
    }

    else
    {
        ui->timeEditTo->setMinimumTime(open);

        if(open <= min_to && min_to <= close)
        {
            ui->dateEditTo->setMinimumDate(from_date);
        }

        else
        {
            ui->dateEditTo->setMinimumDate(from_date.addDays(1));
        }
    }
}

void MainWindow::please_press_search()
{
    please_press_search_helpfunc(ui->tableWidgetP1S_Car);
    please_press_search_helpfunc(ui->tableWidgetP1M_Car);
    please_press_search_helpfunc(ui->tableWidgetP1L_Car);
    please_press_search_helpfunc(ui->tableWidgetP1S_Truck);
    please_press_search_helpfunc(ui->tableWidgetP1L_Truck);

    ui->pushButtonP1next->setDisabled(true);
}

void MainWindow::please_press_search_helpfunc(QTableWidget* tableWidget)
{
    tableWidget->setRowCount(1);

    QTableWidgetItem* reg = new QTableWidgetItem();
    QTableWidgetItem* type = new QTableWidgetItem();
    QTableWidgetItem* brand = new QTableWidgetItem();
    QTableWidgetItem* model = new QTableWidgetItem();

    reg->setText(QString::fromUtf8("Välj datum och"));
    type->setText(QString::fromUtf8(" tryck  sök  för"));
    brand->setText(QString::fromUtf8("att lista lediga"));
    model->setText(QString::fromUtf8("fordon"));

    tableWidget->setItem(0, 0, reg);
    tableWidget->setItem(0, 1, type);
    tableWidget->setItem(0, 2, brand);
    tableWidget->setItem(0, 3, model);

    tableWidget->setDisabled(true);
}



/////////////////////////////////////////////////////////////////////
//  MainWindow Tab 1 - Slots - Knappar
/////////////////////////////////////////////////////////////////////
void MainWindow::on_pushButtonP1next_clicked()
{
    int tab_index = ui->stackedWidgetP1Main->currentIndex();
    int stacked_index = ui->stackedWidgetP1->currentIndex();

    if(tab_index == 0) // från sök till kundupgifter
    {
        if(stacked_index == 0)
            when_next_clicked(search_vehicleP1S_Car, ui->tableWidgetP1S_Car, tab_index);

        else if(stacked_index == 1)
            when_next_clicked(search_vehicleP1M_Car, ui->tableWidgetP1M_Car, tab_index);

        else if(stacked_index == 2)
            when_next_clicked(search_vehicleP1L_Car, ui->tableWidgetP1L_Car, tab_index);

        else if(stacked_index == 3)
            when_next_clicked(search_vehicleP1S_Truck, ui->tableWidgetP1S_Truck, tab_index);

        else if(stacked_index == 4)
            when_next_clicked(search_vehicleP1L_Truck, ui->tableWidgetP1L_Truck, tab_index);

        else
            throw GUI_error("Ogiltligt stack_index i P1");

        QDateTime* from = new QDateTime();
        QDateTime* to = new QDateTime();

        from->setDate(ui->dateEditFrom->date());
        from->setTime(ui->timeEditFrom->time());
        to->setDate(ui->dateEditTo->date());
        to->setTime(ui->timeEditTo->time());

        // sätt datumlabel i kunduppgifter
        ui->labelP1selected_from_var->setText(from->toString(date_time_format));
        ui->labelP1selected_to_var->setText(to->toString(date_time_format));

        //nollställ kunduppgifter
        ui->lineEditP1name_var->clear();
        ui->lineEditP1phone_nr_var->clear();
        ui->lineEditP1address_var->clear();
        ui->lineEditP1postal_nr_var->clear();
        ui->lineEditP1city_var->clear();

        //disabla andra tabbar
        ui->tabWidgetMainTab->setTabEnabled(1, false);
        ui->tabWidgetMainTab->setTabEnabled(2, false);
        ui->tabWidgetMainTab->setTabEnabled(3, false);
        ui->tabWidgetMainTab->setTabEnabled(4, false);

        delete from;
        from = nullptr;
        delete to;
        to = nullptr;
    }

    else if(tab_index == 1) // från kund till bekräftelse
    {
        QString confirm;
        if (change_reservation)
        {
            try
            {
                // Reg nr, start, end ändras ej
                current_resP1->set_name(ui->lineEditP1name_var->text());
                current_resP1->set_tel(ui->lineEditP1phone_nr_var->text());
                current_resP1->set_adress(ui->lineEditP1address_var->text());
                current_resP1->set_postal_nr(ui->lineEditP1postal_nr_var->text());
                current_resP1->set_city(ui->lineEditP1city_var->text());

                confirm = QString::fromUtf8(
                            "Vänligen bekfräfta att du vill ändra nedanstående bokning\n\n"
                            "Reservationsnummer: %1\n\n"
                            "Namn: %2\n"
                            "Telefonnummer: %3\n"
                            "Adress: %4\n"
                            "Postnummer: %5\n"
                            "Stad: %6\n\n"
                            "Från: %7\n"
                            "Till: %8\n"
                            "Registreringsnummer: %9\n")
                        .arg(QString::number(current_resP1->get_res_nr()),
                             current_resP1->get_name(),
                             current_resP1->get_tel(),
                             current_resP1->get_adress(),
                             current_resP1->get_postal_nr(),
                             current_resP1->get_city(),
                             current_resP1->get_start(),
                             current_resP1->get_end(),
                             current_resP1->get_reg_nr());

                current_resP1->save();
            }
            catch (reservation_error& e)
            {
                QMessageBox::information(this,
                                         QString::fromUtf8("Felaktig inmatning"),
                                         QString::fromUtf8("Felaktig inmatning:\n%1").arg(e.what()),
                                         QMessageBox::Ok);
                return;
            }
        }
        else
        {
            try
            {
                new_reservation();

                confirm = QString::fromUtf8(
                            "Vänligen bekfräfta att du vill genomföra nedanstående bokning\n\n"
                            "Reservationsnummer: %1\n\n"
                            "Namn: %2\n"
                            "Telefonnummer: %3\n"
                            "Adress: %4\n"
                            "Postnummer: %5\n"
                            "Stad: %6\n\n"
                            "Från: %7\n"
                            "Till: %8\n"
                            "Registreringsnummer: %9\n")
                        .arg(QString::number(new_reservationP1->get_res_nr()),
                             new_reservationP1->get_name(),
                             new_reservationP1->get_tel(),
                             new_reservationP1->get_adress(),
                             new_reservationP1->get_postal_nr(),
                             new_reservationP1->get_city(),
                             new_reservationP1->get_start(),
                             new_reservationP1->get_end(),
                             new_reservationP1->get_reg_nr());
            }
            catch (reservation_error& e)
            {
                QMessageBox::information(this,
                                         QString::fromUtf8("Felaktig inmatning"),
                                         QString::fromUtf8("Felaktig inmatning:\n%1").arg(e.what()),
                                         QMessageBox::Ok);
                return;
            }
            catch(GUI_error& e)
            {
                QMessageBox::information(this,
                                         QString::fromUtf8("Felaktig inmatning"),
                                         QString::fromUtf8("Felaktig inmatning:\n%1").arg(QString::fromUtf8(e.what())),
                                         QMessageBox::Ok);
                return;
            }
        }

        ui->labelP1confirm->setText(confirm);
        ui->stackedWidgetP1Main->setCurrentIndex(++tab_index);
        ui->pushButtonP1next->setText(QString::fromUtf8("Bekräfta"));
    }

    else if(tab_index == 2) // bekfräfta
    {
        QString confirm_head_msg;
        QString confirm_msg;

        if(change_reservation)
        {
            confirm_head_msg = QString::fromUtf8("Bokning ändrad");
            confirm_msg = QString::fromUtf8("Din bokning är nu ändrad.");
        }
        else
        {
            confirm_head_msg = QString::fromUtf8("Bokning genomförd");
            confirm_msg = QString::fromUtf8("Din bokning är nu genomförd.");
        }
        QMessageBox::information(this,
                                 confirm_head_msg,
                                 confirm_msg,
                                 QMessageBox::Ok);

        ui->pushButtonP1next->setText(QString::fromUtf8("Nästa >"));
        ui->pushButtonP1back->setDisabled(true);
        ui->stackedWidgetP1Main->setCurrentIndex(0);

        if(change_reservation)
        {
            int P1_current_index = ui->stackedWidgetP1->currentIndex();

            current_resP1->save();
            ui->tabWidgetMainTab->setTabEnabled(1, true);
            ui->tabWidgetMainTab->setTabEnabled(2, true);
            ui->tabWidgetMainTab->setTabEnabled(3, true);
            ui->tabWidgetMainTab->setTabEnabled(4, true);
            ui->tabWidgetMainTab->setCurrentIndex(1);
            ui->stackedWidgetP1Main->setCurrentIndex(0);
            ui->tabWidgetMainTab->setTabText(0, QString::fromUtf8("Bokning"));
            ui->pushButtonP1back->setDisabled(true);
            ui->pushButtonP1next->setEnabled(P1_table_is_clicked[P1_current_index]);
            change_reservation = false;
        }
        else
        {
            new_reservationP1->save();
            set_date_now();
            on_pushButtonP1search_clicked();
            ui->tabWidgetMainTab->setTabEnabled(1, true);
            ui->tabWidgetMainTab->setTabEnabled(2, true);
            ui->tabWidgetMainTab->setTabEnabled(3, true);
            ui->tabWidgetMainTab->setTabEnabled(4, true);
        }
    }
}

void MainWindow::on_pushButtonP1back_clicked()
{
    int index = ui->stackedWidgetP1Main->currentIndex();

    if(index == 1) // Personuppgifter
    {
        if (change_reservation)
        {
            int P1_current_index = ui->stackedWidgetP1->currentIndex();

            ui->tabWidgetMainTab->setTabEnabled(1, true);
            ui->tabWidgetMainTab->setTabEnabled(2, true);
            ui->tabWidgetMainTab->setTabEnabled(3, true);
            ui->tabWidgetMainTab->setTabEnabled(4, true);
            ui->tabWidgetMainTab->setCurrentIndex(1);
            ui->stackedWidgetP1Main->setCurrentIndex(0);
            ui->tabWidgetMainTab->setTabText(0, QString::fromUtf8("Bokning"));
            ui->pushButtonP1back->setDisabled(true);
            ui->pushButtonP1next->setEnabled(P1_table_is_clicked[P1_current_index]);
            change_reservation = false;
        }
        else
        {
            ui->stackedWidgetP1Main->setCurrentIndex(--index);
            ui->pushButtonP1back->setDisabled(true);
            ui->tabWidgetMainTab->setTabEnabled(1, true);
            ui->tabWidgetMainTab->setTabEnabled(2, true);
            ui->tabWidgetMainTab->setTabEnabled(3, true);
            ui->tabWidgetMainTab->setTabEnabled(4, true);
        }
    }

    else if(index == 2) // Bekfräfta
    {
        ui->stackedWidgetP1Main->setCurrentIndex(--index);
        ui->pushButtonP1next->setText(QString::fromUtf8("Nästa >"));
    }
}

void MainWindow::on_pushButtonP1search_clicked()
{
    P1_table_is_clicked[0] = false;
    P1_table_is_clicked[1] = false;
    P1_table_is_clicked[2] = false;
    P1_table_is_clicked[3] = false;
    P1_table_is_clicked[4] = false;
    QString type;
    QDateTime* from = new QDateTime();
    QDateTime* to = new QDateTime();
    from->setDate(ui->dateEditFrom->date());
    from->setTime(ui->timeEditFrom->time());
    to->setDate(ui->dateEditTo->date());
    to->setTime(ui->timeEditTo->time());
    QString start = from->toString(date_time_format);
    QString end = to->toString(date_time_format);

    type = QString::fromUtf8("Liten bil");
    generate_vehicle_list(search_vehicleP1S_Car.type_date(type, start, end), ui->tableWidgetP1S_Car);

    type = QString::fromUtf8("Mellanbil");
    generate_vehicle_list(search_vehicleP1M_Car.type_date(type, start, end), ui->tableWidgetP1M_Car);

    type = QString::fromUtf8("Stor bil");
    generate_vehicle_list(search_vehicleP1L_Car.type_date(type, start, end), ui->tableWidgetP1L_Car);

    type = QString::fromUtf8("Liten lastbil");
    generate_vehicle_list(search_vehicleP1S_Truck.type_date(type, start, end), ui->tableWidgetP1S_Truck);

    type = QString::fromUtf8("Stor lastbil");
    generate_vehicle_list(search_vehicleP1L_Truck.type_date(type, start, end), ui->tableWidgetP1L_Truck);

    ui->pushButtonP1next->setDisabled(true);
    delete from;
    from = nullptr;
    delete to;
    to = nullptr;
}



/////////////////////////////////////////////////////////////////////
//  MainWindow Tab 1 - Slots - Sidomeny
/////////////////////////////////////////////////////////////////////
void MainWindow::on_pushButtonP1S_Car_clicked()
{
    ui->stackedWidgetP1->setCurrentIndex(0);
    ui->pushButtonP1next->setEnabled(P1_table_is_clicked[0]);
    ui->labelP1info->setText(S_Car_info);
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP1S_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1M_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Truck);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Truck);
}

void MainWindow::on_pushButtonP1M_Car_clicked()
{
    ui->stackedWidgetP1->setCurrentIndex(1);
    ui->pushButtonP1next->setEnabled(P1_table_is_clicked[1]);
    ui->labelP1info->setText(M_Car_info);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Car);
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP1M_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Truck);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Truck);
}

void MainWindow::on_pushButtonP1L_Car_clicked()
{
    ui->stackedWidgetP1->setCurrentIndex(2);
    ui->pushButtonP1next->setEnabled(P1_table_is_clicked[2]);
    ui->labelP1info->setText(L_Car_info);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1M_Car);
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP1L_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Truck);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Truck);
}

void MainWindow::on_pushButtonP1S_Truck_clicked()
{
    ui->stackedWidgetP1->setCurrentIndex(3);
    ui->pushButtonP1next->setEnabled(P1_table_is_clicked[3]);
    ui->labelP1info->setText(S_Truck_info);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1M_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Car);
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP1S_Truck);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Truck);
}

void MainWindow::on_pushButtonP1L_Truck_clicked()
{
    ui->stackedWidgetP1->setCurrentIndex(4);
    ui->pushButtonP1next->setEnabled(P1_table_is_clicked[4]);
    ui->labelP1info->setText(L_Truck_info);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1M_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Truck);
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP1L_Truck);
}



/////////////////////////////////////////////////////////////////////
//  MainWindow Tab 1 - Slots - tableWidget
/////////////////////////////////////////////////////////////////////
void MainWindow::on_tableWidgetP1S_Car_itemSelectionChanged()
{
    P1_table_is_clicked[0] = true;
    ui->pushButtonP1next->setEnabled(true);
}

void MainWindow::on_tableWidgetP1M_Car_itemSelectionChanged()
{
    P1_table_is_clicked[1] = true;
    ui->pushButtonP1next->setEnabled(true);
}

void MainWindow::on_tableWidgetP1L_Car_itemSelectionChanged()
{
    P1_table_is_clicked[2] = true;
    ui->pushButtonP1next->setEnabled(true);
}

void MainWindow::on_tableWidgetP1S_Truck_itemSelectionChanged()
{
    P1_table_is_clicked[3] = true;
    ui->pushButtonP1next->setEnabled(true);
}

void MainWindow::on_tableWidgetP1L_Truck_itemSelectionChanged()
{
    P1_table_is_clicked[4] = true;
    ui->pushButtonP1next->setEnabled(true);
}



/////////////////////////////////////////////////////////////////////
//  MainWindow Tab 1 - Slots - Övriga
/////////////////////////////////////////////////////////////////////
void MainWindow::on_dateEditFrom_dateChanged()
{
    correct_date_time();
    please_press_search();
}

void MainWindow::on_timeEditFrom_timeChanged()
{
    correct_date_time();
    please_press_search();
}


void MainWindow::on_dateEditTo_dateChanged()
{
    correct_date_time();
    please_press_search();
}

void MainWindow::on_timeEditTo_timeChanged()
{
    correct_date_time();
    please_press_search();
}



/////////////////////////////////////////////////////////////////////
//  MainWindow Tab 1 - Setup tableWidgets
/////////////////////////////////////////////////////////////////////
void MainWindow::setup_tableWidgetP1S_Car() const
{
    setup_tableWidget_vehicle(ui->tableWidgetP1S_Car);
}

void MainWindow::setup_tableWidgetP1M_Car() const
{
    setup_tableWidget_vehicle(ui->tableWidgetP1M_Car);
}

void MainWindow::setup_tableWidgetP1L_Car() const
{
    setup_tableWidget_vehicle(ui->tableWidgetP1L_Car);
}

void MainWindow::setup_tableWidgetP1S_Truck() const
{
    setup_tableWidget_vehicle(ui->tableWidgetP1S_Truck);
}

void MainWindow::setup_tableWidgetP1L_Truck() const
{
    setup_tableWidget_vehicle(ui->tableWidgetP1L_Truck);
}
