/********************************************************************************
** Form generated from reading UI file 'ExamSelectionWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMSELECTIONWINDOW_H
#define UI_EXAMSELECTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamSelectionWindow
{
public:
    QPushButton *backButton;
    QPushButton *selectExamButton;
    QListWidget *examListWidget;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *ExamSelectionWindow)
    {
        if (ExamSelectionWindow->objectName().isEmpty())
            ExamSelectionWindow->setObjectName("ExamSelectionWindow");
        ExamSelectionWindow->resize(800, 600);
        backButton = new QPushButton(ExamSelectionWindow);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(50, 500, 130, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(14);
        backButton->setFont(font);
        selectExamButton = new QPushButton(ExamSelectionWindow);
        selectExamButton->setObjectName("selectExamButton");
        selectExamButton->setGeometry(QRect(620, 500, 130, 40));
        selectExamButton->setFont(font);
        examListWidget = new QListWidget(ExamSelectionWindow);
        examListWidget->setObjectName("examListWidget");
        examListWidget->setGeometry(QRect(100, 200, 391, 192));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(16);
        examListWidget->setFont(font1);
        label = new QLabel(ExamSelectionWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 70, 401, 71));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(36);
        font2.setBold(true);
        label->setFont(font2);
        label_2 = new QLabel(ExamSelectionWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 140, 321, 41));
        label_2->setFont(font1);

        retranslateUi(ExamSelectionWindow);

        QMetaObject::connectSlotsByName(ExamSelectionWindow);
    } // setupUi

    void retranslateUi(QWidget *ExamSelectionWindow)
    {
        ExamSelectionWindow->setWindowTitle(QCoreApplication::translate("ExamSelectionWindow", "Form", nullptr));
        backButton->setText(QCoreApplication::translate("ExamSelectionWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        selectExamButton->setText(QCoreApplication::translate("ExamSelectionWindow", "\320\224\320\260\320\273\320\265\320\265", nullptr));
        label->setText(QCoreApplication::translate("ExamSelectionWindow", "\320\222\321\213\320\261\320\265\321\200\320\265\321\202\320\265 \320\277\321\200\320\265\320\264\320\274\320\265\321\202", nullptr));
        label_2->setText(QCoreApplication::translate("ExamSelectionWindow", "\320\277\320\276 \320\272\320\276\321\202\320\276\321\200\320\276\320\274\321\203 \321\205\320\276\321\202\320\270\321\202\320\265 \320\277\321\200\320\276\320\271\321\202\320\270 \321\215\320\272\320\267\320\260\320\274\320\265\320\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamSelectionWindow: public Ui_ExamSelectionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMSELECTIONWINDOW_H
