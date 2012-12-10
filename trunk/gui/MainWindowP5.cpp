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
* Implementation of tab nr 5 = Fordon.
* Hanterar fordonsdatabasen.
*
*Created by:
*Adam:      on_pushButtonP5search_clicked
*
*/

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <iostream>                                                              //REMOVE
#include <QTableWidgetItem>
#include <QTableWidget>


using namespace std;


////// Tab 5 - Search car
void MainWindow::on_pushButtonP5search_clicked()
{
    QString given_reg_nr = ui->lineEditP5search->text();

    if (given_reg_nr.isEmpty())
        generate_vehicle_list(search_vehicleP5.all(), ui->tableWidgetP5);

    else
    {
        try
        {
            generate_vehicle_list(search_vehicleP5.reg_nr(given_reg_nr), ui->tableWidgetP5);
        }
        catch (search_vehicle_error& e)
        {
            QMessageBox::information(this,
                                     QString::fromUtf8("Felaktig inmatning"),
                                     QString::fromUtf8("Felaktig inmatning:\n%1").arg(QString::fromUtf8(e.what())),
                                     QMessageBox::Ok);
            return;
        }
    }

    on_tableWidgetP5_cellClicked(-1, -1);
}


void MainWindow::on_tableWidgetP5_cellClicked(int row, int column)
{
    (void)column;
    row = get_row_vehicle(ui->tableWidgetP5);

    if (row >= 0) // visa info om bilen
    {
        ui->pushButtonP5change_and_save->setEnabled(true);
        ui->pushButtonP5remove_and_undo->setEnabled(true);

        current_vehicleP5 = search_vehicleP5.get_current_result()[row];
        ui->labelP5regnr_var->setText(current_vehicleP5->get_reg_nr());
        ui->labelP5fabric_var->setText(current_vehicleP5->get_brand());
        ui->labelP5model_var->setText(current_vehicleP5->get_model());
        ui->labelP5type_var->setText(current_vehicleP5->get_type());
        ui->labelP5status_var->setText(current_vehicleP5->get_status());
        ui->lineEditP5mileage_var->setText(QString::number (current_vehicleP5->get_mileage()));
        ui->plainTextEditP5damages_var->setPlainText(current_vehicleP5->get_damage());
    }
    else // cleara info om bilen och disabla knappar
    {
        ui->pushButtonP5change_and_save->setDisabled(true);
        ui->pushButtonP5remove_and_undo->setDisabled(true);
        ui->labelP5regnr_var->clear();
        ui->labelP5fabric_var->clear();
        ui->labelP5model_var->clear();
        ui->labelP5type_var->clear();
        ui->labelP5status_var->clear();
        ui->lineEditP5mileage_var->clear();
        ui->plainTextEditP5damages_var->clear();
    }
}


void MainWindow::on_pushButtonP5add_clicked()
{
    int index = ui->stackedWidgetP5->currentIndex();

    if(index == 0)
    {
        ui->stackedWidgetP5->setCurrentIndex(1);
        ui->pushButtonP5back->setEnabled(true);
        ui->pushButtonP5change_and_save->setDisabled(true);
        ui->pushButtonP5remove_and_undo->setDisabled(true);
        ui->pushButtonP5add->setText(QString::fromUtf8("Spara"));

        ui->lineEditP5add_fabric_var->clear();
        ui->lineEditP5add_model_var->clear();
        ui->lineEditP5add_regnr_var->clear();
        ui->lineEditP5add_mileage_var->clear();
        ui->plainTextEditP5add_damages_var->clear();
    }

    else if(index == 1) // spara klickat
    {
        QString reg_nr = ui->lineEditP5add_regnr_var->text();
        try
        {
            new_vehicleP5->set_reg_nr(reg_nr);

            if(new_vehicleP5->exists())
            {
                QMessageBox::information(this,
                                         QString::fromUtf8("Fordon existerar redan"),
                                         QString::fromUtf8("Fordon med registreringsnummer %1"
                                                           "\nexisterar redan").arg(reg_nr),
                                         QMessageBox::Ok);
            }
            else
            {
                QString brand = ui->lineEditP5add_fabric_var->text();
                QString model = ui->lineEditP5add_model_var->text();
                QString type = ui->comboBoxP5add_type->currentText();
                int mileage = ui->lineEditP5add_mileage_var->text().toInt();
                QString damage = ui->plainTextEditP5add_damages_var->toPlainText();
                QString ledig = QString::fromUtf8("ledig");

                if (model == "" || brand == "")
                {
                    QMessageBox::information(this,
                                             QString::fromUtf8("Ange fabrikat och modell"),
                                             QString::fromUtf8("Fabrikat samt modell måste anges!"),
                                             QMessageBox::Ok);
                }
                else
                {


                    new_vehicleP5->set_brand(brand);
                    new_vehicleP5->set_model(model);
                    new_vehicleP5->set_type(type);
                    new_vehicleP5->set_mileage(mileage);
                    new_vehicleP5->set_damage(damage);
                    new_vehicleP5->set_status(ledig);
                    new_vehicleP5->save();

                    ui->stackedWidgetP5->setCurrentIndex(0);
                    ui->pushButtonP5back->setDisabled(true);
                    ui->pushButtonP5add->setText(QString::fromUtf8("Lägg till >"));

                    /*            if(ui->tableWidgetP5->currentRow() != -1)
                {
                    ui->pushButtonP5change_and_save->setEnabled(true);
                    ui->pushButtonP5remove_and_undo->setEnabled(true);
                }
    */
                    on_pushButtonP5search_clicked();
                }
            }
        }
        catch (const vehicle_error& e)
        {
            QMessageBox::information(this,
                                     QString::fromUtf8("Felaktigt reg nr"),
                                     QString::fromUtf8(e.what()),
                                     QMessageBox::Ok);
            return;
        }
    }
}



void MainWindow::on_pushButtonP5back_clicked()
{
    if(ui->tableWidgetP5->currentRow() != -1)
    {
        ui->pushButtonP5change_and_save->setEnabled(true);
        ui->pushButtonP5remove_and_undo->setEnabled(true);
    }

    ui->stackedWidgetP5->setCurrentIndex(0);
    ui->pushButtonP5add->setText(QString::fromUtf8("Lägg till >"));
    ui->pushButtonP5back->setDisabled(true);
}


void MainWindow::on_pushButtonP5change_and_save_clicked()
{
    if(! pushbuttonP5change_clicked) // change clicked
    {
        pushbuttonP5change_clicked = true;
        P5_change_appearance(pushbuttonP5change_clicked);
    }

    else if(pushbuttonP5change_clicked) // save clicked
    {
        int mileage = ui->lineEditP5mileage_var->text().toInt();
        QString damage = ui->plainTextEditP5damages_var->toPlainText();

        if (mileage >= current_vehicleP5->get_mileage())
        {
            current_vehicleP5->set_mileage(mileage);
            current_vehicleP5->set_damage(damage);
            current_vehicleP5->save();              //Sparar ner förändrad mätarställning samt skador.

            pushbuttonP5change_clicked = false;
            P5_change_appearance(pushbuttonP5change_clicked);
        }
        else
        {
            ui->lineEditP5mileage_var->setText(QString::number(current_vehicleP5->get_mileage()));
            QMessageBox::information(this,
                                     QString::fromUtf8("Felaktig mätarställning"),
                                     QString::fromUtf8("Vänligen mata in en mätarställning\n"
                                                       "större eller lika med %1").arg(current_vehicleP5->get_mileage()),
                                     QMessageBox::Ok);
        }
    }
}


void MainWindow::on_pushButtonP5remove_and_undo_clicked()
{
    if(! pushbuttonP5change_clicked) //remove pressed
    {
        int button_index =
                QMessageBox::question(this,
                                      QString::fromUtf8("Radera fordon"),
                                      QString::fromUtf8("Är du säker på att du vill ta bort %1 ?\n")
                                      .arg(current_vehicleP5->get_reg_nr()),
                                      QString::fromUtf8("Ja"),
                                      QString::fromUtf8("Nej"),
                                      QString::null,
                                      1,1);

        if(button_index == 0) //yes pressed
        {
            if(current_vehicleP5->remove())
            {
                QMessageBox::information(this,
                                         QString::fromUtf8("Borttagning bekräftad!"),
                                         QString::fromUtf8("Borttagning av fordon: %1 lyckades")
                                         .arg(current_vehicleP5->get_reg_nr()),
                                         QMessageBox::Ok);
            }
            else
            {
                QMessageBox::warning(this,
                                         QString::fromUtf8("Borttagning ej tillåten!"),
                                         QString::fromUtf8("Ej tillåtet att ta bort fordon: %1\n"
                                                           "ty det ingår i aktiva och/eller kommande bokningar")
                                         .arg(current_vehicleP5->get_reg_nr()),
                                         QMessageBox::Ok);
            }

      //      delete current_vehicleP5;
       //     current_vehicleP5 = new Vehicle();

            on_pushButtonP5search_clicked();
  }
    }

    else if(pushbuttonP5change_clicked) //undo pressed
    {
        ui->lineEditP5mileage_var->setText(QString::number (current_vehicleP5->get_mileage()));
        ui->plainTextEditP5damages_var->setPlainText(current_vehicleP5->get_damage());

        pushbuttonP5change_clicked = false;
        P5_change_appearance(pushbuttonP5change_clicked);
    }
}


void MainWindow::setup_tableWidgetP5() const
{
    setup_tableWidget_vehicle(ui->tableWidgetP5);
    ui->comboBoxP5add_type->addItem("Liten bil");
    ui->comboBoxP5add_type->addItem("Mellanbil");
    ui->comboBoxP5add_type->addItem("Stor bil");
    ui->comboBoxP5add_type->addItem("Liten lastbil");
    ui->comboBoxP5add_type->addItem("Stor lastbil");
}

void MainWindow::P5_change_appearance(bool state) const
{
    if(state)
    {
        ui->tabWidgetMainTab->setTabEnabled(0, false);
        ui->tabWidgetMainTab->setTabEnabled(1, false);
        ui->tabWidgetMainTab->setTabEnabled(2, false);
        ui->tabWidgetMainTab->setTabEnabled(3, false);
        ui->pushButtonP5add->setDisabled(true);
        ui->pushButtonP5search->setDisabled(true);
        ui->tableWidgetP5->setDisabled(true);
        ui->lineEditP5search->setDisabled(true);
        ui->lineEditP5mileage_var->setReadOnly(false);
        ui->plainTextEditP5damages_var->setReadOnly(false);
        ui->pushButtonP5change_and_save->setText(QString::fromUtf8("Spara"));
        ui->pushButtonP5remove_and_undo->setText(QString::fromUtf8("Ångra"));
    }

    else if(! state)
    {
        ui->tabWidgetMainTab->setTabEnabled(0, true);
        ui->tabWidgetMainTab->setTabEnabled(1, true);
        ui->tabWidgetMainTab->setTabEnabled(2, true);
        ui->tabWidgetMainTab->setTabEnabled(3, true);
        ui->pushButtonP5add->setEnabled(true);
        ui->pushButtonP5search->setEnabled(true);
        ui->tableWidgetP5->setEnabled(true);
        ui->lineEditP5search->setEnabled(true);
        ui->lineEditP5mileage_var->setReadOnly(true);
        ui->plainTextEditP5damages_var->setReadOnly(true);
        ui->pushButtonP5change_and_save->setText(QString::fromUtf8("Ändra"));
        ui->pushButtonP5remove_and_undo->setText(QString::fromUtf8("Ta Bort"));
    }
}
