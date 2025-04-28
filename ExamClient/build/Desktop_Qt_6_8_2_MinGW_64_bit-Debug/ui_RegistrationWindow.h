/********************************************************************************
** Form generated from reading UI file 'RegistrationWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONWINDOW_H
#define UI_REGISTRATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistrationWindow
{
public:
    QPushButton *backButton;
    QPushButton *registerButton;
    QLabel *label;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *RegistrationWindow)
    {
        if (RegistrationWindow->objectName().isEmpty())
            RegistrationWindow->setObjectName("RegistrationWindow");
        RegistrationWindow->resize(800, 600);
        backButton = new QPushButton(RegistrationWindow);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(50, 500, 130, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(14);
        backButton->setFont(font);
        registerButton = new QPushButton(RegistrationWindow);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(620, 500, 130, 40));
        registerButton->setFont(font);
        label = new QLabel(RegistrationWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(245, 20, 310, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(48);
        label->setFont(font1);
        usernameEdit = new QLineEdit(RegistrationWindow);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setGeometry(QRect(370, 380, 280, 30));
        passwordEdit = new QLineEdit(RegistrationWindow);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(370, 430, 280, 30));
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);
        label_2 = new QLabel(RegistrationWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 430, 211, 31));
        label_2->setFont(font);
        label_3 = new QLabel(RegistrationWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(180, 380, 211, 31));
        label_3->setFont(font);
        label_4 = new QLabel(RegistrationWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(295, 100, 210, 31));
        label_4->setFont(font);
        label_5 = new QLabel(RegistrationWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(240, 130, 271, 251));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/IMG_2646 2.png")));

        retranslateUi(RegistrationWindow);

        QMetaObject::connectSlotsByName(RegistrationWindow);
    } // setupUi

    void retranslateUi(QWidget *RegistrationWindow)
    {
        RegistrationWindow->setWindowTitle(QCoreApplication::translate("RegistrationWindow", "Form", nullptr));
        backButton->setText(QCoreApplication::translate("RegistrationWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        registerButton->setText(QCoreApplication::translate("RegistrationWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("RegistrationWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\320\260\321\206\320\270\321\217", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("RegistrationWindow", "\320\222\320\260\321\210\320\265 \320\270\320\274\321\217", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("RegistrationWindow", "\320\237\321\200\320\270\320\264\321\203\320\274\320\260\320\271\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("RegistrationWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("RegistrationWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\262\320\276\320\265 \320\270\320\274\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("RegistrationWindow", "\320\224\320\273\321\217 \320\275\320\276\320\262\321\213\321\205 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265\320\271", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegistrationWindow: public Ui_RegistrationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONWINDOW_H
