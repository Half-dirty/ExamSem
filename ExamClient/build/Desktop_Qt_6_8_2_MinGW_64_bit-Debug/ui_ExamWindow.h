/********************************************************************************
** Form generated from reading UI file 'ExamWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMWINDOW_H
#define UI_EXAMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamWindow
{
public:
    QLabel *TextLabel;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QPushButton *pushButton;

    void setupUi(QWidget *ExamWindow)
    {
        if (ExamWindow->objectName().isEmpty())
            ExamWindow->setObjectName("ExamWindow");
        ExamWindow->resize(800, 600);
        TextLabel = new QLabel(ExamWindow);
        TextLabel->setObjectName("TextLabel");
        TextLabel->setGeometry(QRect(60, 60, 711, 101));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(18);
        TextLabel->setFont(font);
        radioButton = new QRadioButton(ExamWindow);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(60, 220, 240, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(14);
        radioButton->setFont(font1);
        radioButton_2 = new QRadioButton(ExamWindow);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(60, 280, 240, 40));
        radioButton_2->setFont(font1);
        radioButton_3 = new QRadioButton(ExamWindow);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(60, 340, 240, 40));
        radioButton_3->setFont(font1);
        radioButton_4 = new QRadioButton(ExamWindow);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(60, 400, 240, 40));
        radioButton_4->setFont(font1);
        pushButton = new QPushButton(ExamWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(620, 500, 130, 40));
        pushButton->setFont(font1);

        retranslateUi(ExamWindow);

        QMetaObject::connectSlotsByName(ExamWindow);
    } // setupUi

    void retranslateUi(QWidget *ExamWindow)
    {
        ExamWindow->setWindowTitle(QCoreApplication::translate("ExamWindow", "Form", nullptr));
        TextLabel->setText(QString());
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        radioButton_3->setText(QString());
        radioButton_4->setText(QString());
        pushButton->setText(QCoreApplication::translate("ExamWindow", "\320\224\320\260\320\273\320\265\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamWindow: public Ui_ExamWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMWINDOW_H
