#include "MainWindow.h"
#include "ui_MainWindow.h"


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

        QDateTime* from = new QDateTime();
        QDateTime* to = new QDateTime();

        from->setDate(ui->dateEditFrom->date());
        from->setTime(ui->timeEditFrom->time());
        to->setDate(ui->dateEditTo->date());
        to->setTime(ui->timeEditTo->time());

        // sätt label i kunduppgifter
        //ui->  datum från ->setText(from->toString(date_time_format));
        //ui->  datum till ->setText(to->toString(date_time_format));


    }

    else if(tab_index == 1) // från kund till bekräftelse
    {
        if (stacked_index == 0)
        {
            try
            {
                new_reservation(search_vehicleP1S_Car, ui->tableWidgetP1S_Car);
            }
            catch (reservation_error& e)
            {
                QMessageBox::information(this,
                                         QString::fromUtf8("Felaktig inmatning"),
                                         QString::fromUtf8("Felaktig inmatning:\n%1").arg(e.what()),
                                         QMessageBox::Ok);
            }
        }

        ui->stackedWidgetP1Main->setCurrentIndex(++tab_index);
        ui->pushButtonP1next->setText(QString::fromUtf8("Bekräfta"));
    }

    else if(tab_index == 2) // bekfräfta
    {
        about->information(this, QString::fromUtf8("Info"), QString::fromUtf8("Nu ska någonting hända!\nTyp en bekräftelse"));
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
        ui->stackedWidgetP1Main->setCurrentIndex(--index);
        ui->pushButtonP1back->setDisabled(true);
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
    //ui-> info vid bokningsidan ->setText(S_Car_info)
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP1S_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1M_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Truck);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Truck);
}

void MainWindow::on_pushButtonP1M_Car_clicked()
{
    ui->stackedWidgetP1->setCurrentIndex(1);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Car);
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP1M_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Truck);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Truck);
}

void MainWindow::on_pushButtonP1L_Car_clicked()
{
    ui->stackedWidgetP1->setCurrentIndex(2);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1M_Car);
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP1L_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Truck);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Truck);
}

void MainWindow::on_pushButtonP1S_Truck_clicked()
{
    ui->stackedWidgetP1->setCurrentIndex(3);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1M_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Car);
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP1S_Truck);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Truck);
}

void MainWindow::on_pushButtonP1L_Truck_clicked()
{
    ui->stackedWidgetP1->setCurrentIndex(4);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1M_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1L_Car);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP1S_Truck);
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP1L_Truck);
}

void MainWindow::on_pushButtonP1search_clicked()
{
    int stacked_index = ui->stackedWidgetP1->currentIndex();

    QDateTime* from = new QDateTime();
    QDateTime* to = new QDateTime();
    from->setDate(ui->dateEditFrom->date());
    from->setTime(ui->timeEditFrom->time());
    to->setDate(ui->dateEditTo->date());
    to->setTime(ui->timeEditTo->time());
    QString start = from->toString(date_time_format);
    QString end = to->toString(date_time_format);

    if(stacked_index == 0) //S_Car
    {
        QString type = QString::fromUtf8("Liten bil");
        generate_vehicle_list(search_vehicleP1S_Car.type_date(type, start, end), ui->tableWidgetP1S_Car);
    }
    else if (stacked_index == 1) //M_Car
    {
        QString type = QString::fromUtf8("Mellanbil");
        generate_vehicle_list(search_vehicleP1M_Car.type_date(type, start, end), ui->tableWidgetP1M_Car);
    }
    else if (stacked_index == 2) //L_Car
    {
        QString type = QString::fromUtf8("Stor bil");
        generate_vehicle_list(search_vehicleP1L_Car.type_date(type, start, end), ui->tableWidgetP1L_Car);
    }
    else if (stacked_index == 3) //S_Truck
    {
        QString type = QString::fromUtf8("Liten lastbil");
        generate_vehicle_list(search_vehicleP1S_Truck.type_date(type, start, end), ui->tableWidgetP1S_Truck);
    }
    else if (stacked_index == 4) // L_Truck
    {
        QString type = QString::fromUtf8("Stor lastbil");
        generate_vehicle_list(search_vehicleP1L_Truck.type_date(type, start, end), ui->tableWidgetP1L_Truck);
    }
    else
    {
       QMessageBox::information(this,
                                QString::fromUtf8("Välj fordonstyp"),
                                QString::fromUtf8("Vänligen välj fordonstyp innan du klickar på Sök."),
                                QMessageBox::Ok);
    }
}


void MainWindow::when_next_clicked(Search_vehicle& search_vehicle,
                                   QTableWidget* tableWidget,
                                   int tab_index)
{
    int row = tableWidget->currentRow();
    if(row >= 0)
    {
        QString reg_nr = search_vehicle.get_current_result()[row]->get_reg_nr();
        ui->labelSelectedRegnr_var_2->setText(reg_nr);

        ui->stackedWidgetP1Main->setCurrentIndex(++tab_index);
        ui->pushButtonP1back->setDisabled(false);
    }
    else
    {
        please_select_entry();
        return;
    }
}

void MainWindow::new_reservation(Search_vehicle & search_vehicle, QTableWidget* tableWidget)
{
    int row = tableWidget->currentRow();

    QDateTime* from = new QDateTime();
    QDateTime* to = new QDateTime();
    from->setDate(ui->dateEditFrom->date());
    from->setTime(ui->timeEditFrom->time());
    to->setDate(ui->dateEditTo->date());
    to->setTime(ui->timeEditTo->time());

        QString reg_nr = search_vehicle.get_current_result()[row]->get_reg_nr();
        QString start = from->toString(date_time_format);
        QString end = to->toString(date_time_format);
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




