/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Fri Nov 23 22:51:53 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDateEdit>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSettings;
    QAction *actionQuit;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tabBoking;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayoutTop;
    QTimeEdit *timeEditTo;
    QTimeEdit *timeEditFrom;
    QDateEdit *dateEditFrom;
    QLabel *labelFrom;
    QDateEdit *dateEditTo;
    QPushButton *pushButtonSearch;
    QLabel *labelTo;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_7;
    QGridLayout *gridLayoutMiddle;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFrame *frameInfo;
    QFrame *frameSideMenu;
    QGridLayout *gridLayoutBottom;
    QCommandLinkButton *commandLinkButtonToBooking;
    QSpacerItem *horizontalSpacer;
    QWidget *tabSearch;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayoutTop_2;
    QCheckBox *checkBoxClosed;
    QPushButton *pushButtonSearch_2;
    QLineEdit *lineEditSearch;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *checkBoxActive;
    QCheckBox *checkBoxComing;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_9;
    QGridLayout *gridLayoutMiddle_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QFrame *frameSideMenu_2;
    QGridLayout *gridLayoutBottom_2;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonChange;
    QPushButton *pushButtonShow;
    QSpacerItem *horizontalSpacer_5;
    QWidget *tabCheckout;
    QWidget *tabCheckin;
    QWidget *tabVihicle;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setAutoFillBackground(false);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        QFont font;
        actionSettings->setFont(font);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setAutoFillBackground(false);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setContentsMargins(0, 15, 0, 0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabBoking = new QWidget();
        tabBoking->setObjectName(QString::fromUtf8("tabBoking"));
        verticalLayout = new QVBoxLayout(tabBoking);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayoutTop = new QGridLayout();
        gridLayoutTop->setSpacing(6);
        gridLayoutTop->setObjectName(QString::fromUtf8("gridLayoutTop"));
        timeEditTo = new QTimeEdit(tabBoking);
        timeEditTo->setObjectName(QString::fromUtf8("timeEditTo"));

        gridLayoutTop->addWidget(timeEditTo, 2, 4, 1, 1);

        timeEditFrom = new QTimeEdit(tabBoking);
        timeEditFrom->setObjectName(QString::fromUtf8("timeEditFrom"));

        gridLayoutTop->addWidget(timeEditFrom, 1, 4, 1, 1);

        dateEditFrom = new QDateEdit(tabBoking);
        dateEditFrom->setObjectName(QString::fromUtf8("dateEditFrom"));
        dateEditFrom->setCalendarPopup(true);

        gridLayoutTop->addWidget(dateEditFrom, 1, 3, 1, 1);

        labelFrom = new QLabel(tabBoking);
        labelFrom->setObjectName(QString::fromUtf8("labelFrom"));
        labelFrom->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayoutTop->addWidget(labelFrom, 1, 1, 1, 1);

        dateEditTo = new QDateEdit(tabBoking);
        dateEditTo->setObjectName(QString::fromUtf8("dateEditTo"));
        dateEditTo->setCalendarPopup(true);

        gridLayoutTop->addWidget(dateEditTo, 2, 3, 1, 1);

        pushButtonSearch = new QPushButton(tabBoking);
        pushButtonSearch->setObjectName(QString::fromUtf8("pushButtonSearch"));

        gridLayoutTop->addWidget(pushButtonSearch, 2, 6, 1, 1);

        labelTo = new QLabel(tabBoking);
        labelTo->setObjectName(QString::fromUtf8("labelTo"));
        labelTo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelTo->setMargin(0);
        labelTo->setIndent(-1);

        gridLayoutTop->addWidget(labelTo, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(0, 80, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayoutTop->addItem(verticalSpacer_2, 1, 9, 2, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayoutTop->addItem(horizontalSpacer_2, 1, 7, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayoutTop->addItem(horizontalSpacer_8, 1, 5, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayoutTop->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayoutTop->addItem(horizontalSpacer_7, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayoutTop);

        gridLayoutMiddle = new QGridLayout();
        gridLayoutMiddle->setSpacing(6);
        gridLayoutMiddle->setObjectName(QString::fromUtf8("gridLayoutMiddle"));
        scrollArea = new QScrollArea(tabBoking);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 412, 345));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayoutMiddle->addWidget(scrollArea, 0, 1, 1, 1);

        frameInfo = new QFrame(tabBoking);
        frameInfo->setObjectName(QString::fromUtf8("frameInfo"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameInfo->sizePolicy().hasHeightForWidth());
        frameInfo->setSizePolicy(sizePolicy);
        frameInfo->setMinimumSize(QSize(200, 0));
        frameInfo->setBaseSize(QSize(0, 0));
        frameInfo->setFrameShape(QFrame::StyledPanel);
        frameInfo->setFrameShadow(QFrame::Raised);

        gridLayoutMiddle->addWidget(frameInfo, 0, 2, 1, 1);

        frameSideMenu = new QFrame(tabBoking);
        frameSideMenu->setObjectName(QString::fromUtf8("frameSideMenu"));
        sizePolicy.setHeightForWidth(frameSideMenu->sizePolicy().hasHeightForWidth());
        frameSideMenu->setSizePolicy(sizePolicy);
        frameSideMenu->setMinimumSize(QSize(150, 0));
        frameSideMenu->setFrameShape(QFrame::StyledPanel);
        frameSideMenu->setFrameShadow(QFrame::Raised);

        gridLayoutMiddle->addWidget(frameSideMenu, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayoutMiddle);

        gridLayoutBottom = new QGridLayout();
        gridLayoutBottom->setSpacing(6);
        gridLayoutBottom->setObjectName(QString::fromUtf8("gridLayoutBottom"));
        commandLinkButtonToBooking = new QCommandLinkButton(tabBoking);
        commandLinkButtonToBooking->setObjectName(QString::fromUtf8("commandLinkButtonToBooking"));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        commandLinkButtonToBooking->setFont(font1);

        gridLayoutBottom->addWidget(commandLinkButtonToBooking, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayoutBottom->addItem(horizontalSpacer, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayoutBottom);

        tabWidget->addTab(tabBoking, QString());
        tabSearch = new QWidget();
        tabSearch->setObjectName(QString::fromUtf8("tabSearch"));
        verticalLayout_2 = new QVBoxLayout(tabSearch);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayoutTop_2 = new QGridLayout();
        gridLayoutTop_2->setSpacing(6);
        gridLayoutTop_2->setObjectName(QString::fromUtf8("gridLayoutTop_2"));
        checkBoxClosed = new QCheckBox(tabSearch);
        checkBoxClosed->setObjectName(QString::fromUtf8("checkBoxClosed"));

        gridLayoutTop_2->addWidget(checkBoxClosed, 1, 3, 1, 1);

        pushButtonSearch_2 = new QPushButton(tabSearch);
        pushButtonSearch_2->setObjectName(QString::fromUtf8("pushButtonSearch_2"));

        gridLayoutTop_2->addWidget(pushButtonSearch_2, 0, 6, 1, 1);

        lineEditSearch = new QLineEdit(tabSearch);
        lineEditSearch->setObjectName(QString::fromUtf8("lineEditSearch"));

        gridLayoutTop_2->addWidget(lineEditSearch, 0, 3, 1, 2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayoutTop_2->addItem(horizontalSpacer_6, 0, 7, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayoutTop_2->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        checkBoxActive = new QCheckBox(tabSearch);
        checkBoxActive->setObjectName(QString::fromUtf8("checkBoxActive"));

        gridLayoutTop_2->addWidget(checkBoxActive, 1, 4, 1, 1);

        checkBoxComing = new QCheckBox(tabSearch);
        checkBoxComing->setObjectName(QString::fromUtf8("checkBoxComing"));

        gridLayoutTop_2->addWidget(checkBoxComing, 1, 6, 1, 1);

        verticalSpacer = new QSpacerItem(0, 80, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayoutTop_2->addItem(verticalSpacer, 0, 8, 2, 1);

        horizontalSpacer_9 = new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayoutTop_2->addItem(horizontalSpacer_9, 0, 5, 1, 1);


        verticalLayout_2->addLayout(gridLayoutTop_2);

        gridLayoutMiddle_2 = new QGridLayout();
        gridLayoutMiddle_2->setSpacing(6);
        gridLayoutMiddle_2->setObjectName(QString::fromUtf8("gridLayoutMiddle_2"));
        scrollArea_2 = new QScrollArea(tabSearch);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 618, 342));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayoutMiddle_2->addWidget(scrollArea_2, 0, 1, 1, 1);

        frameSideMenu_2 = new QFrame(tabSearch);
        frameSideMenu_2->setObjectName(QString::fromUtf8("frameSideMenu_2"));
        frameSideMenu_2->setMinimumSize(QSize(150, 0));
        frameSideMenu_2->setFrameShape(QFrame::StyledPanel);
        frameSideMenu_2->setFrameShadow(QFrame::Raised);

        gridLayoutMiddle_2->addWidget(frameSideMenu_2, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayoutMiddle_2);

        gridLayoutBottom_2 = new QGridLayout();
        gridLayoutBottom_2->setSpacing(20);
        gridLayoutBottom_2->setContentsMargins(10, 10, 10, 10);
        gridLayoutBottom_2->setObjectName(QString::fromUtf8("gridLayoutBottom_2"));
        pushButtonDelete = new QPushButton(tabSearch);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));

        gridLayoutBottom_2->addWidget(pushButtonDelete, 0, 1, 1, 1);

        pushButtonChange = new QPushButton(tabSearch);
        pushButtonChange->setObjectName(QString::fromUtf8("pushButtonChange"));

        gridLayoutBottom_2->addWidget(pushButtonChange, 0, 2, 1, 1);

        pushButtonShow = new QPushButton(tabSearch);
        pushButtonShow->setObjectName(QString::fromUtf8("pushButtonShow"));

        gridLayoutBottom_2->addWidget(pushButtonShow, 0, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayoutBottom_2->addItem(horizontalSpacer_5, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayoutBottom_2);

        tabWidget->addTab(tabSearch, QString());
        tabCheckout = new QWidget();
        tabCheckout->setObjectName(QString::fromUtf8("tabCheckout"));
        tabWidget->addTab(tabCheckout, QString());
        tabCheckin = new QWidget();
        tabCheckin->setObjectName(QString::fromUtf8("tabCheckin"));
        tabWidget->addTab(tabCheckin, QString());
        tabVihicle = new QWidget();
        tabVihicle->setObjectName(QString::fromUtf8("tabVihicle"));
        tabWidget->addTab(tabVihicle, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionSettings);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "A3B Bilpark", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("MainWindow", "Inst\303\244llningar...", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Avsluta", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "Om...", 0, QApplication::UnicodeUTF8));
        labelFrom->setText(QApplication::translate("MainWindow", "Fr\303\245n", 0, QApplication::UnicodeUTF8));
        pushButtonSearch->setText(QApplication::translate("MainWindow", "S\303\266k", 0, QApplication::UnicodeUTF8));
        labelTo->setText(QApplication::translate("MainWindow", "Till", 0, QApplication::UnicodeUTF8));
        commandLinkButtonToBooking->setText(QApplication::translate("MainWindow", "Boka", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabBoking), QApplication::translate("MainWindow", "Bokning", 0, QApplication::UnicodeUTF8));
        checkBoxClosed->setText(QApplication::translate("MainWindow", "Avslutade", 0, QApplication::UnicodeUTF8));
        pushButtonSearch_2->setText(QApplication::translate("MainWindow", "S\303\266k", 0, QApplication::UnicodeUTF8));
        checkBoxActive->setText(QApplication::translate("MainWindow", "Aktiva", 0, QApplication::UnicodeUTF8));
        checkBoxComing->setText(QApplication::translate("MainWindow", "Kommande", 0, QApplication::UnicodeUTF8));
        pushButtonDelete->setText(QApplication::translate("MainWindow", "Ta Bort", 0, QApplication::UnicodeUTF8));
        pushButtonChange->setText(QApplication::translate("MainWindow", "\303\204ndra", 0, QApplication::UnicodeUTF8));
        pushButtonShow->setText(QApplication::translate("MainWindow", "Visa", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabSearch), QApplication::translate("MainWindow", "S\303\266k", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabCheckout), QApplication::translate("MainWindow", "L\303\244mna ut", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabCheckin), QApplication::translate("MainWindow", "\303\205terl\303\244mna", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabVihicle), QApplication::translate("MainWindow", "Fordon", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "Arkiv", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Hj\303\244lp", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
