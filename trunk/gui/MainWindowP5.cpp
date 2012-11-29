#include "MainWindow.h"
#include "ui_MainWindow.h"


////// Tab 5 - Search car
void MainWindow::on_pushButtonSearchP5search_clicked()
{
    QString given_reg_nr = ui->lineEditSearchP5search->text();
    generate_vehicle_list(search_vehicleP5.reg_nr(given_reg_nr), ui->tableWidgetP5);
}


void MainWindow::on_tableWidgetP5_cellClicked(int row, int column)
{

}

void MainWindow::setup_tableWidgetP5()
{
    ui->tableWidgetP5->setColumnCount(3);
    ui->tableWidgetP5->setHorizontalHeaderLabels(QStringList() << "Reg. nr" << "Märke" << "Modell");
    ui->tableWidgetP5->setShowGrid(false);
    ui->tableWidgetP5->verticalHeader()->hide();
    ui->tableWidgetP5->setAlternatingRowColors(true);
    ui->tableWidgetP5->setEditTriggers(0);
    ui->tableWidgetP5->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP5->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP5->setSortingEnabled(true);

}
