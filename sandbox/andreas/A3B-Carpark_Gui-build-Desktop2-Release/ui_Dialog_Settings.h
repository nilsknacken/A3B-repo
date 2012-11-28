/********************************************************************************
** Form generated from reading UI file 'Dialog_Settings.ui'
**
** Created: Wed Nov 28 16:19:55 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SETTINGS_H
#define UI_DIALOG_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Settings
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *labelOpen;
    QTimeEdit *timeEditOpen;
    QLabel *labelClose;
    QTimeEdit *timeEditClose;
    QLabel *labelMinRentTime;
    QSpinBox *spinBoxMinRentTime;
    QGroupBox *groupBoxDb;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog_Settings)
    {
        if (Dialog_Settings->objectName().isEmpty())
            Dialog_Settings->setObjectName(QString::fromUtf8("Dialog_Settings"));
        Dialog_Settings->resize(320, 269);
        Dialog_Settings->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Dialog_Settings);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        buttonBox = new QDialogButtonBox(Dialog_Settings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);

        frame = new QFrame(Dialog_Settings);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        labelOpen = new QLabel(groupBox);
        labelOpen->setObjectName(QString::fromUtf8("labelOpen"));

        gridLayout_3->addWidget(labelOpen, 0, 0, 1, 1);

        timeEditOpen = new QTimeEdit(groupBox);
        timeEditOpen->setObjectName(QString::fromUtf8("timeEditOpen"));

        gridLayout_3->addWidget(timeEditOpen, 0, 1, 1, 1);

        labelClose = new QLabel(groupBox);
        labelClose->setObjectName(QString::fromUtf8("labelClose"));

        gridLayout_3->addWidget(labelClose, 1, 0, 1, 1);

        timeEditClose = new QTimeEdit(groupBox);
        timeEditClose->setObjectName(QString::fromUtf8("timeEditClose"));

        gridLayout_3->addWidget(timeEditClose, 1, 1, 1, 1);

        labelMinRentTime = new QLabel(groupBox);
        labelMinRentTime->setObjectName(QString::fromUtf8("labelMinRentTime"));

        gridLayout_3->addWidget(labelMinRentTime, 2, 0, 1, 1);

        spinBoxMinRentTime = new QSpinBox(groupBox);
        spinBoxMinRentTime->setObjectName(QString::fromUtf8("spinBoxMinRentTime"));

        gridLayout_3->addWidget(spinBoxMinRentTime, 2, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        groupBoxDb = new QGroupBox(frame);
        groupBoxDb->setObjectName(QString::fromUtf8("groupBoxDb"));
        gridLayout_4 = new QGridLayout(groupBoxDb);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton = new QPushButton(groupBoxDb);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_4->addWidget(pushButton, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBoxDb, 1, 0, 1, 1);


        gridLayout->addWidget(frame, 0, 1, 1, 1);

        QWidget::setTabOrder(buttonBox, timeEditOpen);
        QWidget::setTabOrder(timeEditOpen, timeEditClose);
        QWidget::setTabOrder(timeEditClose, spinBoxMinRentTime);
        QWidget::setTabOrder(spinBoxMinRentTime, pushButton);

        retranslateUi(Dialog_Settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_Settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_Settings, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_Settings);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Settings)
    {
        Dialog_Settings->setWindowTitle(QApplication::translate("Dialog_Settings", "Inst\303\244llningar", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Dialog_Settings", "Allm\303\244nt", 0, QApplication::UnicodeUTF8));
        labelOpen->setText(QApplication::translate("Dialog_Settings", "\303\226ppnar", 0, QApplication::UnicodeUTF8));
        labelClose->setText(QApplication::translate("Dialog_Settings", "St\303\244nger", 0, QApplication::UnicodeUTF8));
        labelMinRentTime->setText(QApplication::translate("Dialog_Settings", "Minsta uthyrningstid (min)", 0, QApplication::UnicodeUTF8));
        groupBoxDb->setTitle(QApplication::translate("Dialog_Settings", "Databas", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Dialog_Settings", "Rensa databas", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Settings: public Ui_Dialog_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SETTINGS_H
