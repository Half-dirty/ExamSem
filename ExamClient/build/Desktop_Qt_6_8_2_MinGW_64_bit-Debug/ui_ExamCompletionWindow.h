/********************************************************************************
** Form generated from reading UI file 'ExamCompletionWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMCOMPLETIONWINDOW_H
#define UI_EXAMCOMPLETIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamCompletionWindow
{
public:
    QTextEdit *detailsTextEdit;
    QLabel *scoreLabel;
    QPushButton *exitButton;
    QLabel *label;

    void setupUi(QWidget *ExamCompletionWindow)
    {
        if (ExamCompletionWindow->objectName().isEmpty())
            ExamCompletionWindow->setObjectName("ExamCompletionWindow");
        ExamCompletionWindow->resize(800, 600);
        detailsTextEdit = new QTextEdit(ExamCompletionWindow);
        detailsTextEdit->setObjectName("detailsTextEdit");
        detailsTextEdit->setGeometry(QRect(69, 205, 661, 261));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(14);
        detailsTextEdit->setFont(font);
        scoreLabel = new QLabel(ExamCompletionWindow);
        scoreLabel->setObjectName("scoreLabel");
        scoreLabel->setGeometry(QRect(69, 140, 271, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setItalic(true);
        scoreLabel->setFont(font1);
        scoreLabel->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        exitButton = new QPushButton(ExamCompletionWindow);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(620, 500, 130, 40));
        exitButton->setFont(font);
        label = new QLabel(ExamCompletionWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(69, 50, 662, 60));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(32);
        font2.setBold(true);
        label->setFont(font2);

        retranslateUi(ExamCompletionWindow);

        QMetaObject::connectSlotsByName(ExamCompletionWindow);
    } // setupUi

    void retranslateUi(QWidget *ExamCompletionWindow)
    {
        ExamCompletionWindow->setWindowTitle(QCoreApplication::translate("ExamCompletionWindow", "Form", nullptr));
        scoreLabel->setText(QCoreApplication::translate("ExamCompletionWindow", "TextLabel", nullptr));
        exitButton->setText(QCoreApplication::translate("ExamCompletionWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        label->setText(QCoreApplication::translate("ExamCompletionWindow", "\320\237\320\276\320\267\320\264\321\200\320\260\320\262\320\273\321\217\320\265\320\274! \320\255\320\272\320\267\320\260\320\274\320\265\320\275 \320\267\320\260\320\262\320\265\321\200\321\210\320\265\320\275.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamCompletionWindow: public Ui_ExamCompletionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMCOMPLETIONWINDOW_H
