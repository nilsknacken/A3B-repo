#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDialog>




////// Tab 4 - Checkin
void MainWindow::on_pushButtonP4next_clicked()
{
    int index = ui->stackedWidgetP4->currentIndex();

    if(index == 0)
    {
        int currentRow = ui->tableWidgetP4->currentRow();
        if (currentRow >= 0)
        {
            current_resP4 = search_resP4.get_current_result()[currentRow];
            QString reg_nr = current_resP4->get_reg_nr();
            search_vehicleP4.reg_nr(reg_nr);
            if (! search_vehicleP4.get_current_result().empty())
                current_vehicleP4 = search_vehicleP4.get_current_result()[0];
            else
                throw GUI_error("Problem att hämta fordon från reservationen!");

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
            QMessageBox::information(this,
                                     QString::fromUtf8("Välj post"),
                                     QString::fromUtf8("Vänligen välj en post innan du klickar på nästa."),
                                     QMessageBox::Ok);
        }


    }

    else if(index == 1)
    {
        // kolla mätarställning
        int new_mileage = ui->lineEditP4mileage->text().toInt();
        if (new_mileage >= current_vehicleP4->get_mileage())
        {
            current_vehicleP4->set_mileage(new_mileage);
            if (ui->checkBoxP4damages_yes)
                current_vehicleP4->set_damage(ui->plainTextEditP4damages->toPlainText());

            // Setup confirmation page
            ui->stackedWidgetP4->setCurrentIndex(++index);
            ui->pushButtonP4next->setText(QString::fromUtf8("Bekräfta"));
            QString confirmation = QString::fromUtf8("Vänligen bekräfta inlämning av nedanstående bokning data\n\n"
                                           "Reservations nummer: %1\n"
                                           "Namn: %2\n"
                                           "Från: %3\n"
                                           "Till: %4\n"
                                           "Registreringsnummer: %5\n"
                                           "Fabrikat: %6\n"
                                           "Modell: %7\n"
                                           "Mätarställning: %8 km\n"
                                           "Skador: %9\n").arg(QString::number(current_resP4->get_res_nr()),
                                                               current_resP4->get_name(),
                                                               current_resP4->get_start(),
                                                               current_resP4->get_end(),
                                                               current_vehicleP4->get_reg_nr(),
                                                               current_vehicleP4->get_brand(),
                                                               current_vehicleP4->get_model(),
                                                               QString::number(current_vehicleP4->get_mileage()),
                                                               current_vehicleP4->get_damage());
            ui->textEditP4_conf->setText(confirmation);

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
        QString avslutad = "avslutad";
        QString ledig = "ledig";
        current_resP4->set_status(avslutad);
        current_vehicleP4->set_status(ledig);
        current_resP4->save();
        current_vehicleP4->save();
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
    ui->tableWidgetP4->setColumnCount(6);
    ui->tableWidgetP4->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Res. nr")
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Namn")
                                                 << QString::fromUtf8("Status")
                                                 << QString::fromUtf8("Starttid")
                                                 << QString::fromUtf8("Slutttid")); ui->tableWidgetP4->setShowGrid(false);
    ui->tableWidgetP4->verticalHeader()->hide();
    ui->tableWidgetP4->setAlternatingRowColors(true);
    ui->tableWidgetP4->setEditTriggers(0);
    ui->tableWidgetP4->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP4->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP4->setSortingEnabled(true);
    ui->tableWidgetP4->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidgetP4->sortItems(5); //sortera på sluttid

    ui->textEditP4_conf->setDisabled(true); // tillåt ej edit av bekräftnings rutan
}
