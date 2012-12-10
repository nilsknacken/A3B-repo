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

void MainWindow::setup_tableWidgetP1S_Car() const
{
    ui->tableWidgetP5->setColumnCount(4);
    ui->tableWidgetP5->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Typ")
                                                 << QString::fromUtf8("Fabrikat")
                                                 << QString::fromUtf8("Modell")); ui->tableWidgetP5->setShowGrid(false);
    ui->tableWidgetP5->verticalHeader()->hide();
    ui->tableWidgetP5->setAlternatingRowColors(true);
    ui->tableWidgetP5->setEditTriggers(0);
    ui->tableWidgetP5->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP5->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP5->setSortingEnabled(true);
}

void MainWindow::setup_tableWidgetP1M_Car() const
{
    ui->tableWidgetP5->setColumnCount(4);
    ui->tableWidgetP5->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Typ")
                                                 << QString::fromUtf8("Fabrikat")
                                                 << QString::fromUtf8("Modell"));  ui->tableWidgetP5->setShowGrid(false);
    ui->tableWidgetP5->verticalHeader()->hide();
    ui->tableWidgetP5->setAlternatingRowColors(true);
    ui->tableWidgetP5->setEditTriggers(0);
    ui->tableWidgetP5->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP5->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP5->setSortingEnabled(true);
}

void MainWindow::setup_tableWidgetP1L_Car() const
{
    ui->tableWidgetP5->setColumnCount(4);
    ui->tableWidgetP5->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Typ")
                                                 << QString::fromUtf8("Fabrikat")
                                                 << QString::fromUtf8("Modell")); ui->tableWidgetP5->setShowGrid(false);
    ui->tableWidgetP5->verticalHeader()->hide();
    ui->tableWidgetP5->setAlternatingRowColors(true);
    ui->tableWidgetP5->setEditTriggers(0);
    ui->tableWidgetP5->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP5->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP5->setSortingEnabled(true);
}

void MainWindow::setup_tableWidgetP1S_Truck() const
{
    ui->tableWidgetP5->setColumnCount(4);
    ui->tableWidgetP5->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Typ")
                                                 << QString::fromUtf8("Fabrikat")
                                                 << QString::fromUtf8("Modell")); ui->tableWidgetP5->setShowGrid(false);
    ui->tableWidgetP5->verticalHeader()->hide();
    ui->tableWidgetP5->setAlternatingRowColors(true);
    ui->tableWidgetP5->setEditTriggers(0);
    ui->tableWidgetP5->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP5->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP5->setSortingEnabled(true);
}

void MainWindow::setup_tableWidgetP1L_Truck() const
{
    ui->tableWidgetP5->setColumnCount(4);
    ui->tableWidgetP5->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Typ")
                                                 << QString::fromUtf8("Fabrikat")
                                                 << QString::fromUtf8("Modell")); ui->tableWidgetP5->setShowGrid(false);
    ui->tableWidgetP5->verticalHeader()->hide();
    ui->tableWidgetP5->setAlternatingRowColors(true);
    ui->tableWidgetP5->setEditTriggers(0);
    ui->tableWidgetP5->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP5->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP5->setSortingEnabled(true);
}




