#include "MainWindow.h"
#include "ui_MainWindow.h"


////// Tab 2 - Search
void MainWindow::on_pushButtonP2search_clicked()
{
    int search_index = ui->stackedWidgetP2->currentIndex();

    if(search_index == 0) // bok nr
    {
        QString res_nr = ui->lineEditSearch->text();
        if (res_nr.isEmpty())
            generate_reservation_list(search_resP2bok_nr.all(), ui->tableWidgetP2bok_nr);
        else
            generate_reservation_list(search_resP2bok_nr.res_nr(res_nr.toInt()), ui->tableWidgetP2bok_nr);
    }

    else if(search_index == 1) // reg nr
    {
        QString reg_nr = ui->lineEditSearch->text();
        if (reg_nr.isEmpty())
            generate_reservation_list(search_resP2reg_nr.all(), ui->tableWidgetP2reg_nr);
        else
            generate_reservation_list(search_resP2reg_nr.reg_nr(reg_nr), ui->tableWidgetP2reg_nr);
    }

    else if(search_index == 2) //namn
    {
        QString name = ui->lineEditSearch->text();
        if (name.isEmpty())
            generate_reservation_list(search_resP2name.all(), ui->tableWidgetP2name);
        else
            generate_reservation_list(search_resP2name.name(name), ui->tableWidgetP2name);
    }

    else if(search_index == 4) //tel
    {
        QString phone_nr = ui->lineEditSearch->text();
        if (phone_nr.isEmpty())
            generate_reservation_list(search_resP2phone_nr.all(), ui->tableWidgetP2phone_nr);
        else
            generate_reservation_list(search_resP2phone_nr.tel(phone_nr), ui->tableWidgetP2phone_nr);
    }

    else if(search_index == 5) //datum
    {
        QString start = ui->dateEditP2from->date().toString(date_format);
        QString end = ui->dateEditP2to->date().toString(date_format);
        start.append(" 00:01");
        end.append(" 23:59");
        QMessageBox::information(this,
                                 QString::fromUtf8("Återlämning genomförd!"),
                                 QString::fromUtf8("söker mellan %1 och %2").arg(start, end),
                                 QMessageBox::Ok);

        generate_reservation_list(search_resP2date.start_end(start, end), ui->tableWidgetP2date);
    }

    else
        throw GUI_error("Ogiltligt index för sök widget!");

}

void MainWindow::on_pushButtonP2delete_clicked()
{}

void MainWindow::on_pushButtonP2change_clicked()
{}

void MainWindow::on_pushButtonP2show_clicked()
{}


void MainWindow::on_dateEditP2from_dateChanged(const QDate &date)
{
    ui->dateEditP2to->setMinimumDate(date);
}


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

    //search_index = "res_nr";
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

    //search_index = "reg_nr";
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

    //search_index = "name";
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

    //search_index = "per_nr";
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

    //search_index = "phone_nr";
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

    //search_index = "date";
}

void MainWindow::setup_tableWidgetP2bok_nr() const
{
    ui->tableWidgetP2bok_nr->setColumnCount(6);
    ui->tableWidgetP2bok_nr->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Res. nr")
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Namn")
                                                 << QString::fromUtf8("Status")
                                                 << QString::fromUtf8("Starttid")
                                                 << QString::fromUtf8("Slutttid"));
    ui->tableWidgetP2bok_nr->setShowGrid(false);
    ui->tableWidgetP2bok_nr->verticalHeader()->hide();
    ui->tableWidgetP2bok_nr->setAlternatingRowColors(true);
    ui->tableWidgetP2bok_nr->setEditTriggers(0);
    ui->tableWidgetP2bok_nr->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP2bok_nr->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP2bok_nr->sortItems(0); // sortera på res nr
    ui->tableWidgetP2bok_nr->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidgetP2bok_nr->setSortingEnabled(true);
}

void MainWindow::setup_tableWidgetP2date() const
{
    ui->tableWidgetP2date->setColumnCount(6);
    ui->tableWidgetP2date->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Res. nr")
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Namn")
                                                 << QString::fromUtf8("Status")
                                                 << QString::fromUtf8("Starttid")
                                                 << QString::fromUtf8("Slutttid"));
    ui->tableWidgetP2date->setShowGrid(false);
    ui->tableWidgetP2date->verticalHeader()->hide();
    ui->tableWidgetP2date->setAlternatingRowColors(true);
    ui->tableWidgetP2date->setEditTriggers(0);
    ui->tableWidgetP2date->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP2date->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP2date->sortItems(4); //sort starttid
    ui->tableWidgetP2date->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidgetP2date->setSortingEnabled(true);
}

void MainWindow::setup_tableWidgetP2name() const
{
    ui->tableWidgetP2name->setColumnCount(6);
    ui->tableWidgetP2name->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Res. nr")
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Namn")
                                                 << QString::fromUtf8("Status")
                                                 << QString::fromUtf8("Starttid")
                                                 << QString::fromUtf8("Slutttid"));
    ui->tableWidgetP2name->setShowGrid(false);
    ui->tableWidgetP2name->verticalHeader()->hide();
    ui->tableWidgetP2name->setAlternatingRowColors(true);
    ui->tableWidgetP2name->setEditTriggers(0);
    ui->tableWidgetP2name->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP2name->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP2name->sortItems(2);  //sort name
    ui->tableWidgetP2name->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidgetP2name->setSortingEnabled(true);
}

void MainWindow::setup_tableWidgetP2per_nr() const
{
    ui->tableWidgetP2per_nr->setColumnCount(6);
    ui->tableWidgetP2per_nr->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Res. nr")
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Namn")
                                                 << QString::fromUtf8("Status")
                                                 << QString::fromUtf8("Starttid")
                                                 << QString::fromUtf8("Slutttid"));
    ui->tableWidgetP2per_nr->setShowGrid(false);
    ui->tableWidgetP2per_nr->verticalHeader()->hide();
    ui->tableWidgetP2per_nr->setAlternatingRowColors(true);
    ui->tableWidgetP2per_nr->setEditTriggers(0);
    ui->tableWidgetP2per_nr->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP2per_nr->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP2per_nr->sortItems(2); // sort name
    ui->tableWidgetP2per_nr->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidgetP2per_nr->setSortingEnabled(true);
}

void MainWindow::setup_tableWidgetP2phone_nr() const
{
    ui->tableWidgetP2phone_nr->setColumnCount(6);
    ui->tableWidgetP2phone_nr->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Res. nr")
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Namn")
                                                 << QString::fromUtf8("Status")
                                                 << QString::fromUtf8("Starttid")
                                                 << QString::fromUtf8("Slutttid"));
    ui->tableWidgetP2phone_nr->setShowGrid(false);
    ui->tableWidgetP2phone_nr->verticalHeader()->hide();
    ui->tableWidgetP2phone_nr->setAlternatingRowColors(true);
    ui->tableWidgetP2phone_nr->setEditTriggers(0);
    ui->tableWidgetP2phone_nr->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP2phone_nr->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP2phone_nr->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidgetP2phone_nr->setSortingEnabled(true);
}

void MainWindow::setup_tableWidgetP2reg_nr() const
{
    ui->tableWidgetP2reg_nr->setColumnCount(6);
    ui->tableWidgetP2reg_nr->setHorizontalHeaderLabels(QStringList()
                                                 << QString::fromUtf8("Res. nr")
                                                 << QString::fromUtf8("Reg. nr")
                                                 << QString::fromUtf8("Namn")
                                                 << QString::fromUtf8("Status")
                                                 << QString::fromUtf8("Starttid")
                                                 << QString::fromUtf8("Slutttid"));
    ui->tableWidgetP2reg_nr->setShowGrid(false);
    ui->tableWidgetP2reg_nr->verticalHeader()->hide();
    ui->tableWidgetP2reg_nr->setAlternatingRowColors(true);
    ui->tableWidgetP2reg_nr->setEditTriggers(0);
    ui->tableWidgetP2reg_nr->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidgetP2reg_nr->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetP2reg_nr->sortItems(1); //sort reg nr
    ui->tableWidgetP2reg_nr->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidgetP2reg_nr->setSortingEnabled(true);
}


