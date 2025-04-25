/********************************************************************************
** Form generated from reading UI file 'StatisticsWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSWINDOW_H
#define UI_STATISTICSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticsWindow
{
public:
    QPushButton *backButton;
    QTextEdit *statsTextEdit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *StatisticsWindow)
    {
        if (StatisticsWindow->objectName().isEmpty())
            StatisticsWindow->setObjectName("StatisticsWindow");
        StatisticsWindow->resize(800, 600);
        backButton = new QPushButton(StatisticsWindow);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(620, 500, 130, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(14);
        backButton->setFont(font);
        statsTextEdit = new QTextEdit(StatisticsWindow);
        statsTextEdit->setObjectName("statsTextEdit");
        statsTextEdit->setGeometry(QRect(50, 130, 700, 331));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(16);
        statsTextEdit->setFont(font1);
        label = new QLabel(StatisticsWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 60, 300, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(36);
        label->setFont(font2);
        label_2 = new QLabel(StatisticsWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(374, 30, 52, 30));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Times New Roman")});
        font3.setPointSize(18);
        label_2->setFont(font3);

        retranslateUi(StatisticsWindow);

        QMetaObject::connectSlotsByName(StatisticsWindow);
    } // setupUi

    void retranslateUi(QWidget *StatisticsWindow)
    {
        StatisticsWindow->setWindowTitle(QCoreApplication::translate("StatisticsWindow", "Form", nullptr));
        backButton->setText(QCoreApplication::translate("StatisticsWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label->setText(QCoreApplication::translate("StatisticsWindow", "\320\240\320\225\320\227\320\243\320\233\320\254\320\242\320\220\320\242\320\253", nullptr));
        label_2->setText(QCoreApplication::translate("StatisticsWindow", "\320\262\320\260\321\210\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisticsWindow: public Ui_StatisticsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSWINDOW_H
