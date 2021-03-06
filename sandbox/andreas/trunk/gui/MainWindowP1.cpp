#include "MainWindow.h"
#include "ui_MainWindow.h"


void MainWindow::on_pushButtonP1next_clicked()
{
    int tab_index = ui->stackedWidgetP1Main->currentIndex();

    if(tab_index == 0)
    {
        ui->stackedWidgetP1Main->setCurrentIndex(++tab_index);
        ui->pushButtonP1back->setDisabled(false);
    }

    else if(tab_index == 1)
    {
        ui->stackedWidgetP1Main->setCurrentIndex(++tab_index);
        ui->pushButtonP1next->setText(QString::fromUtf8("Bekräfta"));
    }

    else if(tab_index == 2)
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
    //Uppdatera sökresultat
}


