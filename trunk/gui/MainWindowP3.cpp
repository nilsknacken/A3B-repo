#include "MainWindow.h"
#include "ui_MainWindow.h"

void MainWindow::on_pushButtonP3remove_reservation_clicked()
{
    int currentRow = ui->tableWidgetP3->currentRow();
    if (currentRow >= 0)
    {
        current_resP3 = search_resP3.get_current_result()[currentRow];
        QString confirm_removal = QString::fromUtf8(
                    "Är du säker på att du vill radera nedanstående bokning?\n\n"
                    "Reservations nummer: %1\n"
                    "Namn: %2\n"
                    "Telefon: %3\n"
                    "Från: %4\n"
                    "Till: %5\n"
                    "Registreringsnummer: %6\n").arg(QString::number(current_resP3->get_res_nr()),
                                                    current_resP3->get_name(),
                                                    current_resP3->get_tel(),
                                                    current_resP3->get_start(),
                                                    current_resP3->get_end(),
                                                    current_resP3->get_reg_nr());

        QMessageBox::warning(this,
                             QString::fromUtf8("Bekräfta borttagning"),
                             confirm_removal,
                             QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this,
                                 QString::fromUtf8("Välj post"),
                                 QString::fromUtf8("Vänligen välj en post innan du klickar på nästa."),
                                 QMessageBox::Ok);
    }

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

    ui->tableWidgetP3->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);

    ui->tableWidgetP3->sortItems(4); //sortera på starttid

}
