/********************************************************************************
** Form generated from reading UI file 'Dialog_Settings.ui'
**
** Created: Fri Nov 23 22:51:53 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Settings
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTimeEdit *timeEdit;
    QTimeEdit *timeEdit_2;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_Settings)
    {
        if (Dialog_Settings->objectName().isEmpty())
            Dialog_Settings->setObjectName(QString::fromUtf8("Dialog_Settings"));
        Dialog_Settings->resize(400, 300);
        verticalLayout = new QVBoxLayout(Dialog_Settings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(Dialog_Settings);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setProperty("min_rent_time", QVariant(0));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 180, 27));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 180, 27));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 180, 27));
        timeEdit = new QTimeEdit(frame);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(200, 30, 118, 27));
        timeEdit_2 = new QTimeEdit(frame);
        timeEdit_2->setObjectName(QString::fromUtf8("timeEdit_2"));
        timeEdit_2->setGeometry(QRect(200, 70, 118, 27));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(200, 110, 113, 27));

        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(Dialog_Settings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog_Settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_Settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_Settings, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_Settings);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Settings)
    {
        Dialog_Settings->setWindowTitle(QApplication::translate("Dialog_Settings", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog_Settings", "\303\226ppnar", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog_Settings", "St\303\244nger", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog_Settings", "Minsta uthyrningstid (min)", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog_Settings: public Ui_Dialog_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SETTINGS_H
