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

void MainWindow::on_pushButtonP5add_clicked()
{}

void MainWindow::on_pushButtonP5change_clicked()
{
    // Detta ska bara vara möjligt om någonting är iklickat, att fixa
    if(! pushbuttonP5change_clicked)
    {
        ui->tabWidgetMainTab->setTabEnabled(0, false);
        ui->tabWidgetMainTab->setTabEnabled(1, false);
        ui->tabWidgetMainTab->setTabEnabled(2, false);
        ui->tabWidgetMainTab->setTabEnabled(3, false);
        ui->pushButtonP5add->setDisabled(true);
        ui->pushButtonP5remove->setDisabled(true);
        ui->pushButtonP5search->setDisabled(true);
        ui->tableWidgetP5->setDisabled(true);
        ui->lineEditP5search->setDisabled(true);
        ui->lineEditP5mileage->setReadOnly(false);
        ui->plainTextEditP5damages->setReadOnly(false);
        ui->pushButtonP5change->setText(QString::fromUtf8("Spara"));
        pushbuttonP5change_clicked = true;
    }

    else if(pushbuttonP5change_clicked)
    {
        ui->tabWidgetMainTab->setTabEnabled(0, true);
        ui->tabWidgetMainTab->setTabEnabled(1, true);
        ui->tabWidgetMainTab->setTabEnabled(2, true);
        ui->tabWidgetMainTab->setTabEnabled(3, true);
        ui->pushButtonP5add->setEnabled(true);
        ui->pushButtonP5remove->setEnabled(true);
        ui->pushButtonP5search->setEnabled(true);
        ui->tableWidgetP5->setEnabled(true);
        ui->lineEditP5search->setEnabled(true);
        ui->lineEditP5mileage->setReadOnly(true);
        ui->plainTextEditP5damages->setReadOnly(true);
        ui->pushButtonP5change->setText(QString::fromUtf8("Ändra"));
        pushbuttonP5change_clicked = false;

        // här ska de nya bärderna sparas i databasen
    }
}

void MainWindow::on_pushButtonP5remove_clicked()
{}

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
