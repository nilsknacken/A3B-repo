/*
* Filename:    MainWindowP1.cpp
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-10-12
*
* DESCRIPTION:
*
* Implementation of tab nr 1 = Bokning.
* Hanterar vad som händer när man gör något under bokningsfliken.
*
* Created by:
* Andreas:  code structure
*           on_pushButtonP1back_clicked
*           on_pushButtonP1******_clicked
*
* Martin:   on_pushButtonP1next_clicked
*           on_pushButtonP1search_clicked
*           when_next_clicked
*           new_reservation
*/

#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <iostream>

void MainWindow::when_next_clicked(Search_vehicle& search_vehicle,
                                   QTableWidget* tableWidget,
                                   int tab_index)
{
    int row = get_row_vehicle(tableWidget);

    if(row >= 0)
    {
        QString reg_nr = search_vehicle.get_current_result()[row]->get_reg_nr();
        ui->labelP1selected_regnr_var->setText(reg_nr);
        current_vehicleP1 = search_vehicle.get_current_result()[row];

        ui->stackedWidgetP1Main->setCurrentIndex(++tab_index);
        ui->pushButtonP1back->setDisabled(false);

    }
    else
    {
        please_select_entry();
        return;
    }
}

void MainWindow::new_reservation()
{
    QString reg_nr = current_vehicleP1->get_reg_nr();
    QString start = ui->labelP1selected_from_var->text();
    QString end = ui->labelP1selected_to_var->text();
    QString name = ui->lineEditName_2->text();
    QString tel = ui->lineEdit_2->text();
    QString address = ui->lineEditAddress_2->text();
    QString postal_nr = ui->lineEditPostalnr_2->text();
    QString city = ui->lineEditCity_2->text();


    current_resP1 = make_reservation(reg_nr,
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
    ui->lineEditName_2->setText(current_resP1->get_name());
    ui->lineEdit_2->setText(current_resP1->get_tel()); // tel
    ui->lineEditAddress_2->setText(current_resP1->get_adress());
    ui->lineEditPostalnr_2->setText(current_resP1->get_postal_nr());
    ui->lineEditCity_2->setText(current_resP1->get_city());
    ui->stackedWidgetP1Main->setCurrentIndex(1);
    ui->pushButtonP1back->setDisabled(false);

}

void MainWindow::on_dateEditFrom_dateChanged(const QDate &date)
{
    QDateTime now;
    now.setDate(date);
    now.setTime(ui->timeEditFrom->time());
    int min_rental = settings->get_min_rental();
    int from_hour = now.time().hour();

    if (min_rental + from_hour >= 24)
    {
        ui->dateEditTo->setMinimumDate(now.date().addDays(1));
        ui->timeEditTo->setMinimumTime(now.time().addSecs(-3600 * (23 - min_rental)));
    }
    else
    {
        ui->dateEditTo->setMinimumDate(now.date());
        ui->timeEditTo->setMinimumTime(now.time().addSecs(3600 * min_rental));
    }
}

void MainWindow::on_timeEditFrom_timeChanged(const QTime &time)
{
    QDateTime now;
    now.setDate(ui->dateEditFrom->date());
    now.setTime(time);
    int min_rental = settings->get_min_rental();
    int from_hour = now.time().hour();

    if (min_rental + from_hour >= 24)
    {
        ui->dateEditTo->setMinimumDate(now.date().addDays(1));
        ui->timeEditTo->setMinimumTime(now.time().addSecs(-3600 * (24 - min_rental)));
    }
    else
    {
        ui->dateEditTo->setMinimumDate(now.date());
        ui->timeEditTo->setMinimumTime(now.time().addSecs(3600 * min_rental));
    }

}


void MainWindow::on_pushButtonP1next_clicked()
{
    int tab_index = ui->stackedWidgetP1Main->currentIndex();
    int stacked_index = ui->stackedWidgetP1->currentIndex();

    if(tab_index == 0) // från sök till kundupgifter
    {
        if(stacked_index == 0)
        {
           when_next_clicked(search_vehicleP1S_Car, ui->tableWidgetP1S_Car, tab_index);
         }
        else if(stacked_index == 1)
        {
            when_next_clicked(search_vehicleP1M_Car, ui->tableWidgetP1M_Car, tab_index);
        }
        else if(stacked_index == 2)
        {
            when_next_clicked(search_vehicleP1L_Car, ui->tableWidgetP1L_Car, tab_index);
        }
        else if(stacked_index == 3)
        {
            when_next_clicked(search_vehicleP1S_Truck, ui->tableWidgetP1S_Truck, tab_index);
        }
        else if(stacked_index == 4)
        {
            when_next_clicked(search_vehicleP1L_Truck, ui->tableWidgetP1L_Truck, tab_index);
        }
        else
        {
            throw GUI_error("Ogiltligt stack_index i P1");
        }

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
        ui->lineEditName_2->clear();
        ui->lineEdit_2->clear(); // tel
        ui->lineEditAddress_2->clear();
        ui->lineEditPostalnr_2->clear();
        ui->lineEditCity_2->clear();

        delete from;
        delete to;
}

    else if(tab_index == 1) // från kund till bekräftelse
    {
        if (change_reservation)
        {
            try
            {
                // Reg nr, start, end ändras ej
                current_resP1->set_name(ui->lineEditName_2->text());
                current_resP1->set_tel(ui->lineEdit_2->text());
                current_resP1->set_adress(ui->lineEditAddress_2->text());
                current_resP1->set_postal_nr(ui->lineEditPostalnr_2->text());
                current_resP1->set_city(ui->lineEditCity_2->text());

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

        QString confirm_reservation = QString::fromUtf8(
                    "Vänligen bekfräfta att du vill genomföra nedanstående bokning\n\n"
                    "Reservationsnummer: %1\n\n"
                    "Namn: %2\n"
                    "Telefonnummer: %3\n"
                    "Adress: %4\n"
                    "Postnummer: %5\n"
                    "Stad: %6\n\n"
                    "Från: %7\n"
                    "Till: %8\n"
                    "Registreringsnummer: %9\n").arg(QString::number(current_resP1->get_res_nr()),
                                                     current_resP1->get_name(),
                                                     current_resP1->get_tel(),
                                                     current_resP1->get_adress(),
                                                     current_resP1->get_postal_nr(),
                                                     current_resP1->get_city(),
                                                     current_resP1->get_start(),
                                                     current_resP1->get_end(),
                                                     current_resP1->get_reg_nr());
        ui->label_7->setText(confirm_reservation); // label_7 är texten på konf sidan
        ui->stackedWidgetP1Main->setCurrentIndex(++tab_index);
        ui->pushButtonP1next->setText(QString::fromUtf8("Bekräfta"));
    }

    else if(tab_index == 2) // bekfräfta
    {
        current_resP1->save();
        QMessageBox::information(this,
                                 QString::fromUtf8("Bokning genomförd"),
                                 QString::fromUtf8("Din bokning är nu genomförd."),
                                 QMessageBox::Ok);
        ui->stackedWidgetP1Main->setCurrentIndex(0);
        ui->pushButtonP1next->setText(QString::fromUtf8("Nästa >"));
        ui->pushButtonP1back->setDisabled(true);
    }
}

void MainWindow::on_pushButtonP1back_clicked()
{
    int index = ui->stackedWidgetP1Main->currentIndex();

    if(index == 1)
    {
        if (change_reservation)
        {
            ui->tabWidgetMainTab->setCurrentIndex(1);
        }
        else
        {
            ui->stackedWidgetP1Main->setCurrentIndex(--index);
            ui->pushButtonP1back->setDisabled(true);
        }
    }

    else if(index == 2)
    {
        ui->stackedWidgetP1Main->setCurrentIndex(--index);
        ui->pushButtonP1next->setText(QString::fromUtf8("Nästa >"));
    }
}



///// Tab 1 - Reservate
void MainWindow::on_pushButtonP1S_Car_clicked()
{
    ui->stackedWidgetP1->setCurrentIndex(0);
    ui->pushButtonP1next->setEnabled(P1_table_is_clicked[0]);
  //  ui->label setText(S_Car_info)
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
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1M_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Truck);
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP1L_Truck);
}

void MainWindow::on_pushButtonP1search_clicked()
{
    ui->pushButtonP1next->setDisabled(true);
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

    delete from;
    delete to;
}


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
