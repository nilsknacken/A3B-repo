/*
* FILENAMN:    MainWindowP2.cc
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
* Conny:    on_pushButtonP2delete_clicked
*           on_pushButtonP2show_clicked
*           on_pushButtonP2change_clicked
*           remove_function
*           show_function
*           change_function
*           disable_buttons
*           on_lineEditSearch_returnPressed
*
*
* Martin:   on_pushButtonP2search_clicked
*           setup_tableWidgetP2bok_nr
*           setup_tableWidgetP2reg_nr
*           setup_tableWidgetP2name
*           setup_tableWidgetP2phone_nr
*           setup_tableWidgetP2date
*
* Andreas:  code structure / code skeleton / signal & slots
*           P2_disable_buttons
*           P2_change_button_appearance
*           on_pushButtonP2bok_nr_clicked
*           on_pushButtonP2reg_nr_clicked
*           on_pushButtonP2name_clicked
*           on_pushButtonP2phone_nr_clicked
*           on_pushButtonP2date_clicked
*           on_tableWidgetP2bok_nr_cellClicked
*           on_tableWidgetP2reg_nr_cellClicked
*           on_tableWidgetP2name_cellClicked
*           on_tableWidgetP2phone_nr_cellClicked
*           on_tableWidgetP2date_cellClicked
*
*/

#include "MainWindow.h"
#include "ui_MainWindow.h"


/////////////////////////////////////////////////////////////////////
//  MainWindow Tab 2 / Sök Tab
/////////////////////////////////////////////////////////////////////
void MainWindow::remove_function(Search_reservation& search_current_res, int current_row, int menu_index)
{
    current_resP2 = search_current_res.get_current_result()[current_row];

    if(current_resP2->get_status() != "aktiv")
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
            current_resP2->remove();
            on_pushButtonP2search_clicked();
            P2_table_is_clicked[menu_index] = false;
            P2_change_button_appearance(menu_index);
            break;
        }

        default:
            break;
        }
    }
    else
    {
        QMessageBox::information(this,
                                 QString::fromUtf8("Ogiltlig borttagning"),
                                 QString::fromUtf8("Det är ej tillåtet att radera en aktiv bokning!"),
                                 QMessageBox::Ok);
    }
}

void MainWindow::show_function(Search_reservation& search_current_res, int current_row)
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
                "Postnummer: %8\n"
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
                             QString::fromUtf8("Information"),
                             show_context,
                             QMessageBox::Ok);
}

void MainWindow::change_function(Search_reservation& search_current_res, int current_row)
{
    current_resP1 = search_current_res.get_current_result()[current_row];
    change_reservation = true;
    change_customer_info();
}

void MainWindow::P2_disable_buttons(int menu_index) const
{
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2bok_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2reg_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2name);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2phone_nr);
    set_stylesheet(SS_SIDEMENU_DISABLE, ui->pushButtonP2date);

    if(menu_index == 0)
        set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP2bok_nr);

    else if(menu_index == 1)
        set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP2reg_nr);

    else if(menu_index == 2)
        set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP2name);

    else if(menu_index == 3)
        set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP2phone_nr);

    else if(menu_index == 4)
        set_stylesheet(SS_SIDEMENU_ENABLE, ui->pushButtonP2date);

    else
        throw GUI_error("Fel index för disable_buttons!");
}

void MainWindow::P2_change_button_appearance(int menu_index) const
{
    if(P2_table_is_clicked[menu_index] && P2_change_button_enabled[menu_index])
        ui->pushButtonP2change->setEnabled(true);

    else
        ui->pushButtonP2change->setDisabled(true);

    ui->pushButtonP2show->setEnabled(P2_table_is_clicked[menu_index]);
    ui->pushButtonP2delete->setEnabled(P2_table_is_clicked[menu_index]);
}



/////////////////////////////////////////////////////////////////////
//  MainWindow Tab 2 - Slots - Knappar
/////////////////////////////////////////////////////////////////////
void MainWindow::on_pushButtonP2search_clicked()
{
    int search_index = ui->stackedWidgetP2->currentIndex();

    if(search_index == 0) // bok nr
    {
        QString res_nr = ui->lineEditSearch->text();
        if (res_nr.isEmpty())
            generate_reservation_list(search_resP2bok_nr.all(), ui->tableWidgetP2bok_nr);
        else
        {
            try
            {
                generate_reservation_list(search_resP2bok_nr.res_nr(res_nr.toInt()), ui->tableWidgetP2bok_nr);
            }
            catch (search_reservation_error& e)
            {
                QMessageBox::information(this,
                                         QString::fromUtf8("Felaktig inmatning"),
                                         QString::fromUtf8("Felaktig inmatning:\n%1").arg(QString::fromUtf8(e.what())),
                                         QMessageBox::Ok);
                return;
            }
        }
    }

    else if(search_index == 1) // reg nr
    {
        QString reg_nr = ui->lineEditSearch->text();
        if (reg_nr.isEmpty())
            generate_reservation_list(search_resP2reg_nr.all(), ui->tableWidgetP2reg_nr);
        else
        {
            try
            {
                generate_reservation_list(search_resP2reg_nr.reg_nr(reg_nr), ui->tableWidgetP2reg_nr);
            }
            catch (search_reservation_error& e)
            {
                QMessageBox::information(this,
                                         QString::fromUtf8("Felaktig inmatning"),
                                         QString::fromUtf8("Felaktig inmatning:\n%1").arg(QString::fromUtf8(e.what())),
                                         QMessageBox::Ok);
                return;
            }
        }
    }

    else if(search_index == 2) //namn
    {
        QString name = ui->lineEditSearch->text();
        if (name.isEmpty())
            generate_reservation_list(search_resP2name.all(), ui->tableWidgetP2name);
        else
        {
            try
            {
                generate_reservation_list(search_resP2name.name(name), ui->tableWidgetP2name);
            }
            catch (search_reservation_error& e)
            {
                QMessageBox::information(this,
                                         QString::fromUtf8("Felaktig inmatning"),
                                         QString::fromUtf8("Felaktig inmatning:\n%1").arg(QString::fromUtf8(e.what())),
                                         QMessageBox::Ok);
                return;
            }
        }
    }

    else if(search_index == 3) //tel
    {
        QString phone_nr = ui->lineEditSearch->text();
        if (phone_nr.isEmpty())
            generate_reservation_list(search_resP2phone_nr.all(), ui->tableWidgetP2phone_nr);
        else
        {
            try
            {
                generate_reservation_list(search_resP2phone_nr.tel(phone_nr), ui->tableWidgetP2phone_nr);
            }
            catch (search_reservation_error& e)
            {
                QMessageBox::information(this,
                                         QString::fromUtf8("Felaktig inmatning"),
                                         QString::fromUtf8("Felaktig inmatning:\n%1").arg(QString::fromUtf8(e.what())),
                                         QMessageBox::Ok);
                return;
            }
        }
    }

    else if(search_index == 4) //datum
    {

        QString start = ui->dateEditP2from->date().toString(date_format);
        QString end = ui->dateEditP2to->date().toString(date_format);
        start.append(" 00:01");
        end.append(" 23:59");

        generate_reservation_list(search_resP2date.start_end(start, end), ui->tableWidgetP2date);
    }

    else
        throw GUI_error("Ogiltligt index för sök widget!");

    P2_table_is_clicked[search_index] = false;
    P2_change_button_appearance(search_index);
}

void MainWindow::on_pushButtonP2delete_clicked()
{
    int search_index = ui->stackedWidgetP2->currentIndex();

    if(search_index == 0) // bok nr
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2bok_nr);
        remove_function(search_resP2bok_nr, currentRow, search_index);
    }

    else if(search_index == 1) // reg nr
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2reg_nr);
        remove_function(search_resP2reg_nr, currentRow, search_index);
    }

    else if(search_index == 2) //namn
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2name);
        remove_function(search_resP2name, currentRow, search_index);
    }

    else if(search_index == 3) //tel
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2phone_nr);
        remove_function(search_resP2phone_nr, currentRow, search_index);
    }

    else if(search_index == 4) //datum
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2date);
        remove_function(search_resP2date, currentRow, search_index);
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

    else if(search_index == 3) //tel
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2phone_nr);
        change_function(search_resP2phone_nr, currentRow);
    }

    else if(search_index == 4) //datum
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

    else if(search_index == 3) //tel
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2phone_nr);
        show_function(search_resP2phone_nr, currentRow);
    }

    else if(search_index == 4) //datum
    {
        int currentRow = get_row_reservation(ui->tableWidgetP2date);
        show_function(search_resP2date, currentRow);
    }

    else
        throw GUI_error("Ogiltligt index för visa widget!");
}



/////////////////////////////////////////////////////////////////////
//  MainWindow Tab 2 - Slots - Sidomeny
/////////////////////////////////////////////////////////////////////
void MainWindow::on_pushButtonP2bok_nr_clicked()
{
    P2_disable_buttons(0);
    ui->stackedWidgetP2->setCurrentIndex(0);
    ui->stackedWidgetP2toggle_date_string->setCurrentIndex(0);
    P2_change_button_appearance(0);
}

void MainWindow::on_pushButtonP2reg_nr_clicked()
{
    P2_disable_buttons(1);
    ui->stackedWidgetP2->setCurrentIndex(1);
    ui->stackedWidgetP2toggle_date_string->setCurrentIndex(0);
    P2_change_button_appearance(1);
}

void MainWindow::on_pushButtonP2name_clicked()
{
    P2_disable_buttons(2);
    ui->stackedWidgetP2->setCurrentIndex(2);
    ui->stackedWidgetP2toggle_date_string->setCurrentIndex(0);
    P2_change_button_appearance(2);
}

void MainWindow::on_pushButtonP2phone_nr_clicked()
{
    P2_disable_buttons(3);
    ui->stackedWidgetP2->setCurrentIndex(3);
    ui->stackedWidgetP2toggle_date_string->setCurrentIndex(0);
    P2_change_button_appearance(3);
}

void MainWindow::on_pushButtonP2date_clicked()
{
    QDateTime now = QDateTime::currentDateTime();
    ui->dateEditP2from->setMinimumDate(now.date());

    P2_disable_buttons(4);
    ui->stackedWidgetP2->setCurrentIndex(4);
    ui->stackedWidgetP2toggle_date_string->setCurrentIndex(1);
    P2_change_button_appearance(4);
}



/////////////////////////////////////////////////////////////////////
//  MainWindow Tab 2 - Slots - tableWidget
/////////////////////////////////////////////////////////////////////
void MainWindow::on_tableWidgetP2bok_nr_cellClicked(int row, int column)
{
    (void)column;
    P2_table_is_clicked[0] = true;

    if(ui->tableWidgetP2bok_nr->item(row, 3)->text() == "kommande")
        P2_change_button_enabled[0] = true;

    else
        P2_change_button_enabled[0] = false;

    P2_change_button_appearance(0);
}

void MainWindow::on_tableWidgetP2reg_nr_cellClicked(int row, int column)
{
    (void)column;
    P2_table_is_clicked[1] = true;

    if(ui->tableWidgetP2reg_nr->item(row, 3)->text() == "kommande")
        P2_change_button_enabled[1] = true;

    else
        P2_change_button_enabled[1] = false;

        P2_change_button_appearance(1);
}

void MainWindow::on_tableWidgetP2name_cellClicked(int row, int column)
{
    (void)column;
    P2_table_is_clicked[2] = true;

    if(ui->tableWidgetP2name->item(row, 3)->text() == "kommande")
        P2_change_button_enabled[2] = true;

    else
        P2_change_button_enabled[2] = false;

    P2_change_button_appearance(2);
}

void MainWindow::on_tableWidgetP2phone_nr_cellClicked(int row, int column)
{
    (void)column;
    P2_table_is_clicked[3] = true;

    if(ui->tableWidgetP2phone_nr->item(row, 3)->text() == "kommande")
        P2_change_button_enabled[3] = true;

    else
        P2_change_button_enabled[3] = false;

    P2_change_button_appearance(3);
}

void MainWindow::on_tableWidgetP2date_cellClicked(int row, int column)
{
    (void)column;
    P2_table_is_clicked[4] = true;

    if(ui->tableWidgetP2date->item(row, 3)->text() == "kommande")
        P2_change_button_enabled[4] = true;

    else
        P2_change_button_enabled[4] = false;

    P2_change_button_appearance(4);
}



/////////////////////////////////////////////////////////////////////
//  MainWindow Tab 2 - Slots - Övriga
/////////////////////////////////////////////////////////////////////
void MainWindow::on_lineEditSearch_returnPressed()
{
    on_pushButtonP2search_clicked();
}

void MainWindow::on_dateEditP2from_dateChanged(const QDate &date)
{
    ui->dateEditP2to->setMinimumDate(date);
}



/////////////////////////////////////////////////////////////////////
//  MainWindow Tab 2 - Setup tableWidgets
/////////////////////////////////////////////////////////////////////
void MainWindow::setup_tableWidgetP2bok_nr() const
{
    setup_tableWidget_reservation(ui->tableWidgetP2bok_nr);
    ui->tableWidgetP2bok_nr->sortItems(0); // sortera på re_ nr
}

void MainWindow::setup_tableWidgetP2reg_nr() const
{
    setup_tableWidget_reservation(ui->tableWidgetP2reg_nr);
    ui->tableWidgetP2reg_nr->sortItems(1); //sort reg nr
}

void MainWindow::setup_tableWidgetP2name() const
{
    setup_tableWidget_reservation(ui->tableWidgetP2name);
    ui->tableWidgetP2name->sortItems(2);  //sort name
}

void MainWindow::setup_tableWidgetP2phone_nr() const
{
    setup_tableWidget_reservation(ui->tableWidgetP2phone_nr);
}

void MainWindow::setup_tableWidgetP2date() const
{
    setup_tableWidget_reservation(ui->tableWidgetP2date);
    ui->tableWidgetP2date->sortItems(4); //sort starttid
}
