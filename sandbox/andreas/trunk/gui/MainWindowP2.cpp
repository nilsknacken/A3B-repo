#include "MainWindow.h"
#include "ui_MainWindow.h"




////// Tab 2 - Search
void MainWindow::on_pushButtonP2search_clicked()
{}

void MainWindow::on_pushButtonP2delete_clicked()
{}

void MainWindow::on_pushButtonP2change_clicked()
{}

void MainWindow::on_pushButtonP2show_clicked()
{}

void MainWindow::on_pushButtonP2bok_nr_clicked()
{
    ui->stackedWidgetP2->setCurrentIndex(0);
    ui->stackedWidgetP2toggle_date_string->setCurrentIndex(0);
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP2bok_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2reg_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2name);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2per_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2phone_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2date);

}

void MainWindow::on_pushButtonP2reg_nr_clicked()
{
    ui->stackedWidgetP2->setCurrentIndex(1);
    ui->stackedWidgetP2toggle_date_string->setCurrentIndex(0);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2bok_nr);
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP2reg_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2name);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2per_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2phone_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2date);
}

void MainWindow::on_pushButtonP2name_clicked()
{
    ui->stackedWidgetP2->setCurrentIndex(2);
    ui->stackedWidgetP2toggle_date_string->setCurrentIndex(0);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2bok_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2reg_nr);
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP2name);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2per_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2phone_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2date);
}

void MainWindow::on_pushButtonP2per_nr_clicked()
{
    ui->stackedWidgetP2->setCurrentIndex(3);
    ui->stackedWidgetP2toggle_date_string->setCurrentIndex(0);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2bok_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2reg_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2name);
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP2per_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2phone_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2date);
}

void MainWindow::on_pushButtonP2phone_nr_clicked()
{
    ui->stackedWidgetP2->setCurrentIndex(4);
    ui->stackedWidgetP2toggle_date_string->setCurrentIndex(0);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2bok_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2reg_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2name);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2per_nr);
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP2phone_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2date);
}


void MainWindow::on_pushButtonP2date_clicked()
{
    ui->stackedWidgetP2->setCurrentIndex(5);
    ui->stackedWidgetP2toggle_date_string->setCurrentIndex(1);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2bok_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2reg_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2name);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2per_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2phone_nr);
    set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP2date);
}

