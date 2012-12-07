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
    int i = 0;
    QString given_reg_nr = ui->lineEditP5search->text();
    string check_reg = given_reg_nr.toStdString();

    if(check_reg.length() == 6)
    {
        while(i < 3)
        {
            if(isalpha(check_reg[i]))
                ++i;
            else
                break;
        }

        if(i == 3)
        {
            while(i < 6)
            {
                if(isdigit(check_reg[i]))
                    ++i;
                else
                    break;
            }
        }
    }
    else if(check_reg.length() > 0)
        ++i;

    if (i != 6 && i != 0)
    {
        QMessageBox::information(this,
                                 QString::fromUtf8("Felaktig inmatning"),
                                 QString::fromUtf8("Felaktig inmatning utav registreringsnummer."),
                                 QMessageBox::Ok);
    }

    if (given_reg_nr.isEmpty())
        generate_vehicle_list(search_vehicleP5.all(), ui->tableWidgetP5);

    else
        generate_vehicle_list(search_vehicleP5.reg_nr(given_reg_nr), ui->tableWidgetP5);

    on_tableWidgetP5_cellClicked(-1, -1);
}


void MainWindow::on_tableWidgetP5_cellClicked(int row, int column)
{
    (void)column;

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
    }

    else if(index == 1) // spara klickat
    {
        delete current_vehicleP5;
        current_vehicleP5 = new Vehicle();

        QString reg_nr = ui->lineEditP5add_regnr_var->text();
        QString brand = ui->lineEditP5add_fabric_var->text();
        QString model = ui->lineEditP5add_model_var->text();
        QString type = ui->comboBoxP5add_type->currentText();
        int mileage = ui->lineEditP5add_mileage_var->text().toInt();
        QString damage = ui->plainTextEditP5add_damages_var->toPlainText();
        QString ledig = QString::fromUtf8("ledig");

        current_vehicleP5->set_reg_nr(reg_nr);
        current_vehicleP5->set_brand(brand);
        current_vehicleP5->set_model(model);
        current_vehicleP5->set_type(type);
        current_vehicleP5->set_mileage(mileage);
        current_vehicleP5->set_damage(damage);
        current_vehicleP5->set_status(ledig);
        current_vehicleP5->save();

        delete current_vehicleP5;
        current_vehicleP5 = new Vehicle();

        ui->stackedWidgetP5->setCurrentIndex(0);
        ui->pushButtonP5back->setDisabled(true);
        ui->pushButtonP5add->setText(QString::fromUtf8("Lägg till >"));

        if(ui->tableWidgetP5->currentRow() != -1)
        {
            ui->pushButtonP5change_and_save->setEnabled(true);
            ui->pushButtonP5remove_and_undo->setEnabled(true);
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
    ui->lineEditP5add_fabric_var->clear();
    ui->lineEditP5add_model_var->clear();
    ui->lineEditP5add_regnr_var->clear();
    ui->lineEditP5add_mileage_var->clear();
    ui->plainTextEditP5add_damages_var->clear();
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

        current_vehicleP5->set_mileage(mileage);
        current_vehicleP5->set_damage(damage);
        current_vehicleP5->save();              //Sparar ner förändrad mätarställning samt skador.

        pushbuttonP5change_clicked = false;
        P5_change_appearance(pushbuttonP5change_clicked);
    }
}


void MainWindow::on_pushButtonP5remove_and_undo_clicked()
{
    if(! pushbuttonP5change_clicked) //remove pressed
    {
        int button_index =
                QMessageBox::question(this,
                                      QString::fromUtf8("Radera fordon"),
                                      QString::fromUtf8("Är du säker på att du vill ta bort ")
                                      + ui->tableWidgetP5->item(ui->tableWidgetP5->currentRow(), 0)->text()
                                      + QString::fromUtf8("?\n"),
                                      QString::fromUtf8("Ja"),
                                      QString::fromUtf8("Nej"),
                                      QString::null,
                                      1,1);

        if(button_index == 0) //yes pressed
        {
            on_tableWidgetP5_cellClicked(-1, -1);

            cerr << "Fordon är inte borttaget, detta ska inplementeras" << endl;            //REMOVE
            //Här ska ett fordon tas bort och infon ska nollställas
        }
    }

    else if(pushbuttonP5change_clicked) //undo pressed
    {
        //Här ska ändringar ångras, dvs mätarställning och skador läsas in pånytt,
        //alternativt köra on_tableWidgetP5_cellClicked(ui->tableWidgetP5->currentRow(), 0)
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
