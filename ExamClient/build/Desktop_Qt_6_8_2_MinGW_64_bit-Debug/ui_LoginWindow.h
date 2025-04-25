/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLabel *label;
    QPushButton *registerButton;
    QPushButton *loginButton;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(800, 600);
        label = new QLabel(LoginWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(265, 320, 270, 100));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(48);
        font.setBold(false);
        label->setFont(font);
        registerButton = new QPushButton(LoginWindow);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(212, 460, 170, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(16);
        registerButton->setFont(font1);
        loginButton = new QPushButton(LoginWindow);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(417, 460, 170, 40));
        loginButton->setFont(font1);
        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 410, 360, 21));
        label_2->setFont(font1);
        label_3 = new QLabel(LoginWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(240, 20, 355, 311));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/IMG_2645.png")));

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "ExamSem", nullptr));
        registerButton->setText(QCoreApplication::translate("LoginWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWindow", "\320\222\321\205\320\276\320\264", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\264\320\273\321\217 \320\277\321\200\320\276\321\205\320\276\320\266\320\264\320\265\320\275\320\270\321\217 \321\215\320\272\320\267\320\260\320\274\320\265\320\275\320\276\320\262", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
