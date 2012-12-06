/*
* FILENAMN:    MainWindowP2.cpp
* PROJECT:     A3B
* PROGRAMMER:  Conny Andersson  Y3a conan414@student.liu.se
*              Andreas Bolin    Y3a andbo467@student.liu.se
*              Martin Andersson Y3a maran703@student.liu.se
*              Adam Andersson   Y3a adaan690@student.liu.se
* DATE:        2012-12-05
*
* DESCRIPTION
*
* Here are the functions for Tab2 "sök" defined.
*
* Created by:
* Conny:
*  on_pushButtonP2delete_clicked
*  on_pushButtonP2show_clicked
*  on_pushButtonP2change_clicked
*  remove_function
*  show_function
*  change_function
*
*
* Martin:
*  on_pushButtonP2search_clicked
*
*/

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
{
    int search_index = ui->stackedWidgetP2->currentIndex();

    if(search_index == 0) // bok nr
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2bok_nr);
        remove_function(search_resP2bok_nr, currentRow);
    }

    else if(search_index == 1) // reg nr
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2reg_nr);
        remove_function(search_resP2reg_nr, currentRow);
    }

    else if(search_index == 2) //namn
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2name);
        remove_function(search_resP2name, currentRow);
    }

    else if(search_index == 4) //tel
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2phone_nr);
        remove_function(search_resP2phone_nr, currentRow);
    }

    else if(search_index == 5) //datum
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2date);
        remove_function(search_resP2date, currentRow);
    }

    else
        throw GUI_error("Ogiltligt index för Ta bort widget!");
}

void MainWindow::on_pushButtonP2change_clicked()
{
    int search_index = ui->stackedWidgetP2->currentIndex();

    if(search_index == 0) // bok nr
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2bok_nr);
        change_function(search_resP2bok_nr, currentRow);
    }

    else if(search_index == 1) // reg nr
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2reg_nr);
        change_function(search_resP2reg_nr, currentRow);
    }

    else if(search_index == 2) //namn
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2name);
        change_function(search_resP2name, currentRow);
    }

    else if(search_index == 4) //tel
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2phone_nr);
        change_function(search_resP2phone_nr, currentRow);
    }

    else if(search_index == 5) //datum
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2date);
        change_function(search_resP2date, currentRow);
    }

    else
        throw GUI_error("Ogiltligt index för ändra widget!");
}

void MainWindow::on_pushButtonP2show_clicked()
{
    int search_index = ui->stackedWidgetP2->currentIndex();

    if(search_index == 0) // bok nr
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2bok_nr);
        show_function(search_resP2bok_nr, currentRow);
    }

    else if(search_index == 1) // reg nr
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2reg_nr);
        show_function(search_resP2reg_nr, currentRow);
    }

    else if(search_index == 2) //namn
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2name);
        show_function(search_resP2name, currentRow);
    }

    else if(search_index == 4) //tel
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2phone_nr);
        show_function(search_resP2phone_nr, currentRow);
    }

    else if(search_index == 5) //datum
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2date);
        show_function(search_resP2date, currentRow);
    }

    else
        throw GUI_error("Ogiltligt index för visa widget!");
}


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
    ui->tableWidgetP2bok_nr->sortItems(0); // sortera på re_ nr
    setup_tableWidget_reservation(ui->tableWidgetP2bok_nr);
}

void MainWindow::setup_tableWidgetP2date() const
{
    ui->tableWidgetP2date->sortItems(4); //sort starttid
    setup_tableWidget_reservation(ui->tableWidgetP2date);
}

void MainWindow::setup_tableWidgetP2name() const
{
    ui->tableWidgetP2name->sortItems(2);  //sort name
    setup_tableWidget_reservation(ui->tableWidgetP2name);
}

void MainWindow::setup_tableWidgetP2per_nr() const
{

    ui->tableWidgetP2per_nr->sortItems(2); // sort name
    setup_tableWidget_reservation(ui->tableWidgetP2per_nr);
}

void MainWindow::setup_tableWidgetP2phone_nr() const
{
    setup_tableWidget_reservation(ui->tableWidgetP2phone_nr);
}

void MainWindow::setup_tableWidgetP2reg_nr() const
{
    ui->tableWidgetP2reg_nr->sortItems(1); //sort reg nr
    setup_tableWidget_reservation(ui->tableWidgetP2reg_nr);
}


void MainWindow::remove_function(Search_reservation& search_current_res, int current_row)
{
    if (current_row >= 0)
    {
        QString confirm_removal = QString::fromUtf8(
                    "Är du säker på att du vill radera nedanstående bokning?\n\n"
                    "Reservations nummer: %1\n"
                    "Namn: %2\n"
                    "Telefon: %3\n"
                    "Från: %4\n"
                    "Till: %5\n"
                    "Registreringsnummer: %6\n").arg(QString::number(current_resP2->get_res_nr()),
                                                     current_resP2->get_name(),
                                                     current_resP2->get_tel(),
                                                     current_resP2->get_start(),
                                                     current_resP2->get_end(),
                                                     current_resP2->get_reg_nr());

        switch(QMessageBox::warning(this,
                                    QString::fromUtf8("Bekräfta borttagning"),
                                    confirm_removal,
                                    QMessageBox::Cancel,
                                    QMessageBox::Yes))
        {
        case QMessageBox::Yes:
        {
            current_resP2 = search_current_res.get_current_result()[current_row];
            current_resP2->remove();
            on_pushButtonP2search_clicked();
            break;
        }

        default:
            break;
        }
    }
    else
    {
        please_select_entry();
    }
}

void MainWindow::show_function(Search_reservation& search_current_res, int current_row)
{
    if (current_row >= 0)
    {
        current_resP2 = search_current_res.get_current_result()[current_row];
        QString show_context = QString::fromUtf8(
                    "Information\n\n"
                    "Reservations nummer: %1\n"
                    "Namn: %2\n"
                    "Telefon: %3\n"
                    "Från: %4\n"
                    "Till: %5\n"
                    "Registreringsnummer: %6\n"
                    "Adress: %7\n"
                    "Post nummer: %8\n"
                    "Stad: %9\n").arg(QString::number(current_resP2->get_res_nr()),
                                      current_resP2->get_name(),
                                      current_resP2->get_tel(),
                                      current_resP2->get_start(),
                                      current_resP2->get_end(),
                                      current_resP2->get_reg_nr(),
                                      current_resP2->get_adress(),
                                      current_resP2->get_postal_nr(),
                                      current_resP2->get_city());

        QMessageBox::information(this,
                                 QString::fromUtf8("Bekräfta borttagning"),
                                 show_context,
                                 QMessageBox::Ok);
    }
    else
    {
        please_select_entry();
    }
}

void MainWindow::change_function(Search_reservation& search_current_res, int current_row)
{
    if (current_row >= 0)
    {
        QString change_context = QString::fromUtf8(
                    "Du är påväg att lämna söksidan för att gå till bokningsidan.\n"
                    "Det är på bokningssidan du kan ändra dina personliga uppgifter.\n\n"
                    "Vill du göra detta?\n");

        switch(QMessageBox::warning(this,
                                    QString::fromUtf8("Bekräfta sidbyte"),
                                    change_context,
                                    QMessageBox::Cancel,
                                    QMessageBox::Yes))
        {
        case QMessageBox::Yes:
        {
            current_resP1 = search_current_res.get_current_result()[current_row];
            change_reservation = true;
            change_customer_info();
            break;
        }

        default:
            break;
        }
    }
    else
    {
        please_select_entry();
    }
}

