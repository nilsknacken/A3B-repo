#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDialog>




////// Tab 4 - Checkin
void MainWindow::on_pushButtonP4next_clicked()
{
    int index = ui->stackedWidgetP4->currentIndex();

    if(index == 0)
    {
        ui->stackedWidgetP4->setCurrentIndex(++index);
        ui->pushButtonP4back->setDisabled(false);
    }

    else if(index == 1)
    {
        ui->stackedWidgetP4->setCurrentIndex(++index);
        ui->pushButtonP4next->setText(QString::fromUtf8("Bekräfta"));
    }

    else if(index == 2)
    {
        // Poppupp eller ny sida med bekräftelse
        about->about(this, QString::fromUtf8("Bekräftelse"), QString::fromUtf8("Poppupp eller ny sida med en bekräftelse"));

        ui->pushButtonP4next->setText(QString::fromUtf8("Nästa >"));
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
    ui->tableWidgetP5->setColumnCount(6);
    ui->tableWidgetP5->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Res. nr")
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Namn")
                                                 << QString::fromUtf8("Status")
                                                 << QString::fromUtf8("Starttid")
                                                 << QString::fromUtf8("Slutttid")); ui->tableWidgetP5->setShowGrid(false);
    ui->tableWidgetP5->verticalHeader()->hide();
    ui->tableWidgetP5->setAlternatingRowColors(true);
    ui->tableWidgetP5->setEditTriggers(0);
    ui->tableWidgetP5->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP5->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP5->setSortingEnabled(true);
}
