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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
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
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QDateEdit *dateFromEdit;
    QDateEdit *dateToEdit;
    QComboBox *subjectComboBox;
    QPushButton *applyFilterButton;

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
        statsTextEdit->setGeometry(QRect(50, 170, 700, 291));
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
        horizontalLayoutWidget = new QWidget(StatisticsWindow);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(49, 119, 701, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        horizontalLayout->addWidget(label_3);

        dateFromEdit = new QDateEdit(horizontalLayoutWidget);
        dateFromEdit->setObjectName("dateFromEdit");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Times New Roman")});
        font4.setPointSize(11);
        dateFromEdit->setFont(font4);

        horizontalLayout->addWidget(dateFromEdit);

        dateToEdit = new QDateEdit(horizontalLayoutWidget);
        dateToEdit->setObjectName("dateToEdit");
        dateToEdit->setFont(font4);

        horizontalLayout->addWidget(dateToEdit);

        subjectComboBox = new QComboBox(horizontalLayoutWidget);
        subjectComboBox->setObjectName("subjectComboBox");
        subjectComboBox->setFont(font4);
        subjectComboBox->setMinimumContentsLength(11);

        horizontalLayout->addWidget(subjectComboBox);

        applyFilterButton = new QPushButton(horizontalLayoutWidget);
        applyFilterButton->setObjectName("applyFilterButton");
        applyFilterButton->setFont(font4);

        horizontalLayout->addWidget(applyFilterButton);


        retranslateUi(StatisticsWindow);

        subjectComboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(StatisticsWindow);
    } // setupUi

    void retranslateUi(QWidget *StatisticsWindow)
    {
        StatisticsWindow->setWindowTitle(QCoreApplication::translate("StatisticsWindow", "Form", nullptr));
        backButton->setText(QCoreApplication::translate("StatisticsWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label->setText(QCoreApplication::translate("StatisticsWindow", "\320\240\320\225\320\227\320\243\320\233\320\254\320\242\320\220\320\242\320\253", nullptr));
        label_2->setText(QCoreApplication::translate("StatisticsWindow", "\320\262\320\260\321\210\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("StatisticsWindow", "\320\244\320\270\320\273\321\214\321\202\321\200\321\213", nullptr));
        subjectComboBox->setPlaceholderText(QCoreApplication::translate("StatisticsWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\321\200\320\265\320\264\320\274\320\265\321\202", nullptr));
        applyFilterButton->setText(QCoreApplication::translate("StatisticsWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisticsWindow: public Ui_StatisticsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSWINDOW_H
