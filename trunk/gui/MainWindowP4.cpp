/*
* Filename:    MainWindowP4.cpp
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-10-12
*
* DESCRIPTION:
* Implementation of tab nr 4 = Återlämna.
* Hanterar vad som händer när man gör något under återlämningsfliken.
*
*Created by:
* Andreas:  code structure
*           on_pushButtonP4back_clicked
*           on_checkBoxP4damages_yes_toggled
* Martin:   on_pushButtonP4next_clicked
*           setup_tableWidgetP4
* Adam:     on_pushButtonP4next_clicked
*
*/


#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDialog>




////// Tab 4 - Checkin
void MainWindow::on_pushButtonP4next_clicked()
{
    int index = ui->stackedWidgetP4->currentIndex();

    if(index == 0)
    {
        QString id = ui->tableWidgetP4->item(ui->tableWidgetP4->currentRow(),4)->text();
            int currentRow = id.toInt();
        //int currentRow = ui->tableWidgetP4->currentRow();
        if (currentRow >= 0)
        {
            current_resP4 = search_resP4.get_current_result()[currentRow];
            QString reg_nr = current_resP4->get_reg_nr();
            search_vehicleP4.reg_nr(reg_nr);
            if (! search_vehicleP4.get_current_result().empty())
                current_vehicleP4 = search_vehicleP4.get_current_result()[0];
            else
                throw GUI_error("Problem att hämta fordon från reservationen!");

            QDateTime* date_time = new QDateTime();
            QString now = date_time->currentDateTime().toString(date_time_format);
            current_resP4->set_end(now);
            current_resP4->save();

            ui->labelP4reg_nr_var->setText(reg_nr);
            ui->labelP4checkout_var->setText(current_resP4->get_start());
            ui->labelP4checkin_var->setText(current_resP4->get_end());
            ui->lineEditP4mileage->setText(QString::number(current_vehicleP4->get_mileage()));
            ui->plainTextEditP4damages->setPlainText(current_vehicleP4->get_damage());

            ui->stackedWidgetP4->setCurrentIndex(++index);
            ui->pushButtonP4back->setDisabled(false);
        }
        else
        {
          please_select_entry();
        }


    }

    else if(index == 1)
    {
        // kolla mätarställning
        int difference = ui->lineEditP4mileage->text().toInt() - current_vehicleP4->get_mileage();
        int new_mileage = ui->lineEditP4mileage->text().toInt();
        if (new_mileage >= current_vehicleP4->get_mileage())
        {
            current_vehicleP4->set_mileage(new_mileage);
            if (ui->checkBoxP4damages_yes)
                current_vehicleP4->set_damage(ui->plainTextEditP4damages->toPlainText());


            // Setup confirmation page
            ui->stackedWidgetP4->setCurrentIndex(++index);
            ui->pushButtonP4next->setText(QString::fromUtf8("Bekräfta"));
            QString confirmation1 = QString::fromUtf8("Vänligen bekräfta inlämning av nedanstående bokning data\n\n"
                                           "Reservations nummer: %1\n"
                                           "Namn: %2\n"
                                           "Från: %3\n"
                                           "Till: %4\n"
                                           "Registreringsnummer: %5\n").arg(QString::number(current_resP4->get_res_nr()),
                                                               current_resP4->get_name(),
                                                               current_resP4->get_start(),
                                                               current_resP4->get_end(),
                                                               current_vehicleP4->get_reg_nr());
            QString confirmation2 = QString::fromUtf8(
                                           "Fabrikat: %1\n"
                                           "Modell: %2\n"
                                           "Mätarställning: %3 km\n"
                                           "Körd sträcka: %4 km\n"
                                           "Skador: %5\n").arg(current_vehicleP4->get_brand(),
                                                               current_vehicleP4->get_model(),
                                                               QString::number(current_vehicleP4->get_mileage()),
                                                               QString::number(difference),
                                                               current_vehicleP4->get_damage());
            ui->textEditP4_conf->setText(confirmation1.append(confirmation2));

        }
        else
        {
            QMessageBox::information(this,
                                     QString::fromUtf8("Felaktig mätarställning"),
                                     QString::fromUtf8("Vänligen mata in en mätarställning\n"
                                                       "större eller lika med %1").arg(current_vehicleP4->get_mileage()),
                                     QMessageBox::Ok);
        }
    }

    else if(index == 2)
    {
        //Bekräftelse

        QString avslutad = "avslutad";
        QString ledig = "ledig";
        current_resP4->set_status(avslutad);
        current_vehicleP4->set_status(ledig);
        current_resP4->save();
        current_vehicleP4->save();

        QString check_in_done = QString::fromUtf8("Följande bokning har återlämnats\n\n"
                                       "Reservations nummer: %1\n"
                                       "Namn: %2\n"
                                       "Från: %3\n"
                                       "Till: %4\n"
                                       "Registreringsnummer: %5\n"
                                       "Fabrikat: %6\n"
                                       "Modell: %7\n").arg(QString::number(current_resP4->get_res_nr()),
                                                           current_resP4->get_name(),
                                                           current_resP4->get_start(),
                                                           current_resP4->get_end(),
                                                           current_vehicleP4->get_reg_nr(),
                                                           current_vehicleP4->get_brand(),
                                                           current_vehicleP4->get_model());
        QMessageBox::information(this,
                                 QString::fromUtf8("Återlämning genomförd!"),
                                 check_in_done,
                                 QMessageBox::Ok);


        ui->pushButtonP4next->setText(QString::fromUtf8("Nästa >"));
        QString aktiv = "aktiv";
        generate_reservation_list(search_resP4.status(aktiv), ui->tableWidgetP4);
        ui->stackedWidgetP4->setCurrentIndex(0);
        ui->pushButtonP4back->setDisabled(true);
    }
}

void MainWindow::on_pushButtonP4back_clicked()
{
    int index = ui->stackedWidgetP4->currentIndex();


    if(index == 1)
    {
        ui->stackedWidgetP4->setCurrentIndex(--index);
        ui->pushButtonP4back->setDisabled(true);
    }

    if(index == 2)
    {
        ui->stackedWidgetP4->setCurrentIndex(--index);
        ui->pushButtonP4next->setText(QString::fromUtf8("Nästa >"));
    }
}

void MainWindow::on_checkBoxP4damages_yes_toggled(bool checked)
{
    ui->plainTextEditP4damages->setDisabled(! checked);
}

void MainWindow::setup_tableWidgetP4() const
{
    setup_tableWidget_reservation(ui->tableWidgetP4);
    ui->tableWidgetP4->sortItems(5); //sortera på sluttid

    ui->textEditP4_conf->setReadOnly(true);//  setDisabled(true); // tillåt ej edit av bekräftnings rutan
}

void MainWindow::on_tableWidgetP4_itemSelectionChanged()
{
    ui->pushButtonP4next->setEnabled(true);
}
