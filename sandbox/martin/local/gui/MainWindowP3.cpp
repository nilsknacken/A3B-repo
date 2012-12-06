/*
* FILENAMN:    MainWindowP3.cpp
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-12-05
*
* DESCRIPTION
*
* Here are the functions for Tab3 "Lämna ut" defined.
*
* Created by:
* Conny:
*  on_pushButtonP3checkout_clicked
*  checkout_function
*
* Martin:
*  on_pushButtonP3remove_reservation_clicked
*
*/

#include "MainWindow.h"
#include "ui_MainWindow.h"

void MainWindow::on_pushButtonP3remove_reservation_clicked()
{
    int currentRow = get_row_reservation(ui->tableWidgetP3);

    if (currentRow >= 0)
    {
        QString confirm_removal = QString::fromUtf8(
                    "Är du säker på att du vill radera nedanstående bokning?\n\n"
                    "Reservations nummer: %1\n"
                    "Namn: %2\n"
                    "Telefon: %3\n"
                    "Från: %4\n"
                    "Till: %5\n"
                    "Registreringsnummer: %6\n").arg(QString::number(current_resP3->get_res_nr()),
                                                    current_resP3->get_name(),
                                                    current_resP3->get_tel(),
                                                    current_resP3->get_start(),
                                                    current_resP3->get_end(),
                                                    current_resP3->get_reg_nr());

        switch(QMessageBox::warning(this,
                                    QString::fromUtf8("Bekräfta borttagning"),
                                    confirm_removal,
                                    QMessageBox::Cancel,
                                    QMessageBox::Yes))
        {
        case QMessageBox::Yes:
        {
            current_resP3 = search_resP3.get_current_result()[currentRow];
            current_resP3->remove();
            QString kommande = "kommande";
            generate_reservation_list(search_resP3.status(kommande), ui->tableWidgetP3);
            break;
        }

        default:
            break;
        }
    }

    else
    {
        please_select_entry();
    }

}

void MainWindow::on_pushButtonP3checkout_clicked()
{
    int currentRow = get_row_reservation(ui->tableWidgetP3);
    if (currentRow >= 0)
    {
        current_resP3 = search_resP3.get_current_result()[currentRow];
        QString reg_nr = current_resP3->get_reg_nr();
        search_vehicleP3.reg_nr(reg_nr);
        if (! search_vehicleP3.get_current_result().empty())
            current_vehicleP3 = search_vehicleP3.get_current_result()[0];
        else
            throw GUI_error("Problem att hämta fordon från reservationen!");

        QString confirm_checkout = QString::fromUtf8(
                    "Är du säker på att du vill lämna ut nedanstående bokning?\n\n"
                    "Reservations nummer: %1\n"
                    "Namn: %2\n"
                    "Telefon: %3\n"
                    "Från: %4\n"
                    "Till: %5\n"
                    "Registreringsnummer: %6\n").arg(QString::number(current_resP3->get_res_nr()),
                                                    current_resP3->get_name(),
                                                    current_resP3->get_tel(),
                                                    current_resP3->get_start(),
                                                    current_resP3->get_end(),
                                                    current_resP3->get_reg_nr());

        switch(QMessageBox::warning(this,
                                    QString::fromUtf8("Bekräfta utlämning"),
                                    confirm_checkout,
                                    QMessageBox::Cancel,
                                    QMessageBox::Yes))
        {
        case QMessageBox::Yes:
        {
            checkout_function();
            QString kommande = "kommande";
            generate_reservation_list(search_resP3.status(kommande), ui->tableWidgetP3);
            break;
        }

        default:
            break;
        }
    }

    else
    {
        please_select_entry();
    }
}

void MainWindow::setup_tableWidgetP3() const
{
    ui->tableWidgetP3->sortItems(4); //sortera på starttid
    setup_tableWidget_reservation(ui->tableWidgetP3);
}

void MainWindow::checkout_function()
{
    //Bekräftelse

    QString aktiv = "aktiv";
    QString uthyrd = "uthyrd";
    current_resP3->set_status(aktiv);
    current_vehicleP3->set_status(uthyrd);

    QDateTime* date_time = new QDateTime();
    QString now = date_time->currentDateTime().toString(date_time_format);
    current_resP3->set_start(now);
    current_resP3->save();
    current_vehicleP3->save();

    QString check_out_done = QString::fromUtf8("Följande bokning har lämnats ut\n\n"
                                   "Reservations nummer: %1\n"
                                   "Namn: %2\n"
                                   "Från: %3\n"
                                   "Till: %4\n"
                                   "Registreringsnummer: %5\n"
                                   "Fabrikat: %6\n"
                                   "Modell: %7\n").arg(QString::number(current_resP3->get_res_nr()),
                                                       current_resP3->get_name(),
                                                       current_resP3->get_start(),
                                                       current_resP3->get_end(),
                                                       current_vehicleP3->get_reg_nr(),
                                                       current_vehicleP3->get_brand(),
                                                       current_vehicleP3->get_model());
    QMessageBox::information(this,
                             QString::fromUtf8("Utlämning genomförd!"),
                             check_out_done,
                             QMessageBox::Ok);
}



