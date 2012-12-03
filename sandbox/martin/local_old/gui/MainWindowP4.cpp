#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDialog>
#include <vector>

#include <iostream>

#include "../backend/ReservationQ.h"
#include "../backend/Search_reservationQ.h"

using namespace std;

////// Tab 4 - Återlämna
void MainWindow::on_pushButtonP4next_clicked()
{
    int index = ui->stackedWidgetP4->currentIndex();

    // Första sidan -> sida2
    if(index == 0)
    {

  /*      int currentRow = ui->tableWidget_2->currentRow();
        if (currentRow >= 0)
        {
            ui->labelP4reg_nr_var->setText(search_resP4.get_current_result()[currentRow]->get_reg_nr());
            ui->labelP4checkout_var->setText(search_resP4.get_current_result()[currentRow]->get_start());
            ui->labelP4checkin_var->setText(search_resP4.get_current_result()[currentRow]->get_end());
            ui->lineEditP4mileage->setText(search_resP4.get_current_result()[currentRow]->get_mileage());
            ui->plainTextEditP4damages->setPlainText(search_resP4.get_current_result()[currentRow]->get_damages());
*/
            ui->stackedWidgetP4->setCurrentIndex(++index);
            ui->pushButtonP4back->setDisabled(false);
  /*      }
        else
        {
            QMessageBox::information(this,
                                     QString::fromUtf8("Välj post"),
                                     QString::fromUtf8("Vänligen välj en post innan du klickar på nästa."),
                                     QMessageBox::Ok);
        }
*/

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
        ui->pushButtonP4next->setText(QString::fromUtf8("Nästa >"));
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


// Initiate tableWidget
void MainWindow::setup_tableWidgetP4() const
{
    ui->tableWidget_2->setColumnCount(6);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Res. nr")
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Namn")
                                                 << QString::fromUtf8("Status")
                                                 << QString::fromUtf8("Starttid")
                                                 << QString::fromUtf8("Slutttid")); ui->tableWidget_2->setShowGrid(false);
    ui->tableWidget_2->verticalHeader()->hide();
    ui->tableWidget_2->setAlternatingRowColors(true);
    ui->tableWidget_2->setEditTriggers(0);
    ui->tableWidget_2->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setSortingEnabled(true);
}
