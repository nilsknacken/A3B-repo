#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Dialog_About.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbout_triggered()
{
    about = new Dialog_About;
    about->show();
}

void MainWindow::on_actionSettings_triggered()
{
    settings = new Dialog_Settings;
    settings->show();
}

void MainWindow::on_actionQuit_triggered()
{
    exit(0);
}
