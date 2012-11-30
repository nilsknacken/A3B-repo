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

void MainWindow::setup_tableWidgetP2bok_nr() const
{
    ui->tableWidgetP5->setColumnCount(6);
    ui->tableWidgetP5->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Res. nr")
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Namn")
                                                 << QString::fromUtf8("Status")
                                                 << QString::fromUtf8("Starttid")
                                                 << QString::fromUtf8("Slutttid"));
    ui->tableWidgetP5->setShowGrid(false);
    ui->tableWidgetP5->verticalHeader()->hide();
    ui->tableWidgetP5->setAlternatingRowColors(true);
    ui->tableWidgetP5->setEditTriggers(0);
    ui->tableWidgetP5->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP5->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP5->setSortingEnabled(true);
}

void MainWindow::setup_tableWidgetP2date() const
{
    ui->tableWidgetP5->setColumnCount(6);
    ui->tableWidgetP5->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Res. nr")
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Namn")
                                                 << QString::fromUtf8("Status")
                                                 << QString::fromUtf8("Starttid")
                                                 << QString::fromUtf8("Slutttid"));  ui->tableWidgetP5->setShowGrid(false);
    ui->tableWidgetP5->verticalHeader()->hide();
    ui->tableWidgetP5->setAlternatingRowColors(true);
    ui->tableWidgetP5->setEditTriggers(0);
    ui->tableWidgetP5->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP5->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP5->setSortingEnabled(true);
}

void MainWindow::setup_tableWidgetP2name() const
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

void MainWindow::setup_tableWidgetP2per_nr() const
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

void MainWindow::setup_tableWidgetP2phone_nr() const
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

void MainWindow::setup_tableWidgetP2reg_nr() const
{
    ui->tableWidgetP5->setColumnCount(6);
    ui->tableWidgetP5->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Res. nr")
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Namn")
                                                 << QString::fromUtf8("Status")
                                                 << QString::fromUtf8("Starttid")
                                                 << QString::fromUtf8("Slutttid"));ui->tableWidgetP5->setShowGrid(false);
    ui->tableWidgetP5->verticalHeader()->hide();
    ui->tableWidgetP5->setAlternatingRowColors(true);
    ui->tableWidgetP5->setEditTriggers(0);
    ui->tableWidgetP5->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP5->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP5->setSortingEnabled(true);
}


