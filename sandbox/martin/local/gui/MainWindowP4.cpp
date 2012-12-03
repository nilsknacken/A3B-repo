#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDialog>




////// Tab 4 - Checkin
void MainWindow::on_pushButtonP4next_clicked()
{
    int index = ui->stackedWidgetP4->currentIndex();

    if(index == 0)
    {
        int currentRow = ui->tableWidgetP4->currentRow();
        if (currentRow >= 0)
        { // behöver plocka fram fordonet som ör kopplat till goven bokning
 /*           ui->labelP4reg_nr_var->setText(search_resP4.get_current_result()[currentRow]->get_reg_nr());
            ui->labelP4checkout_var->setText(search_resP4.get_current_result()[currentRow]->get_start());
            ui->labelP4checkin_var->setText(search_resP4.get_current_result()[currentRow]->get_end());
            ui->lineEditP4mileage->setText(search_resP4.get_current_result()[currentRow]->get_mileage());
            ui->plainTextEditP4damages->setPlainText(search_resP4.get_current_result()[currentRow]->get_damages());
*/
            ui->stackedWidgetP4->setCurrentIndex(++index);
            ui->pushButtonP4back->setDisabled(false);
        }
        else
        {
            QMessageBox::information(this,
                                     QString::fromUtf8("Välj post"),
                                     QString::fromUtf8("Vänligen välj en post innan du klickar på nästa."),
                                     QMessageBox::Ok);
        }


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
    ui->tableWidgetP4->setColumnCount(6);
    ui->tableWidgetP4->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Res. nr")
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Namn")
                                                 << QString::fromUtf8("Status")
                                                 << QString::fromUtf8("Starttid")
                                                 << QString::fromUtf8("Slutttid")); ui->tableWidgetP4->setShowGrid(false);
    ui->tableWidgetP4->verticalHeader()->hide();
    ui->tableWidgetP4->setAlternatingRowColors(true);
    ui->tableWidgetP4->setEditTriggers(0);
    ui->tableWidgetP4->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP4->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP4->setSortingEnabled(true);
}
