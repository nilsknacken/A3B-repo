#include "MainWindow.h"
#include "ui_MainWindow.h"

void MainWindow::on_pushButtonP3remove_reservation_clicked()
{

}

void MainWindow::on_pushButtonP3checkout_clicked()
{

}

void MainWindow::setup_tableWidgetP3() const
{
    ui->tableWidgetP3->setColumnCount(6);
    ui->tableWidgetP3->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Res. nr")
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Namn")
                                                 << QString::fromUtf8("Status")
                                                 << QString::fromUtf8("Starttid")
                                                 << QString::fromUtf8("Slutttid")); ui->tableWidgetP3->setShowGrid(false);
    ui->tableWidgetP3->verticalHeader()->hide();
    ui->tableWidgetP3->setAlternatingRowColors(true);
    ui->tableWidgetP3->setEditTriggers(0);
    ui->tableWidgetP3->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP3->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP3->setSortingEnabled(true);
}
