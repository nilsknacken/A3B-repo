#include "MainWindow.h"
#include "ui_MainWindow.h"


////// Tab 5 - Search car
void MainWindow::on_pushButtonP5search_clicked()
{
    QString given_reg_nr = ui->lineEditP5search->text();
    if (given_reg_nr.isEmpty())
        generate_vehicle_list(search_vehicleP5.all(), ui->tableWidgetP5);
    else
        generate_vehicle_list(search_vehicleP5.reg_nr(given_reg_nr), ui->tableWidgetP5);

}


void MainWindow::on_tableWidgetP5_cellClicked(int row, int column)
{

}

void MainWindow::setup_tableWidgetP5() const
{
    ui->tableWidgetP5->setColumnCount(4);
    ui->tableWidgetP5->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Typ")
                                                 << QString::fromUtf8("Fabrikat")
                                                 << QString::fromUtf8("Modell"));
    ui->tableWidgetP5->setShowGrid(false);
    ui->tableWidgetP5->verticalHeader()->hide();
    ui->tableWidgetP5->setAlternatingRowColors(true);
    ui->tableWidgetP5->setEditTriggers(0);
    ui->tableWidgetP5->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP5->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP5->setSortingEnabled(true);
}
