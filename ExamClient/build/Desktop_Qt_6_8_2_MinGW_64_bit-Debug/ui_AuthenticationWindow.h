/********************************************************************************
** Form generated from reading UI file 'AuthenticationWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHENTICATIONWINDOW_H
#define UI_AUTHENTICATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthenticationWindow
{
public:
    QPushButton *backButton;
    QPushButton *nextButton;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *AuthenticationWindow)
    {
        if (AuthenticationWindow->objectName().isEmpty())
            AuthenticationWindow->setObjectName("AuthenticationWindow");
        AuthenticationWindow->setEnabled(true);
        AuthenticationWindow->resize(800, 600);
        backButton = new QPushButton(AuthenticationWindow);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(50, 500, 130, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(14);
        backButton->setFont(font);
        nextButton = new QPushButton(AuthenticationWindow);
        nextButton->setObjectName("nextButton");
        nextButton->setGeometry(QRect(620, 500, 130, 40));
        nextButton->setFont(font);
        usernameEdit = new QLineEdit(AuthenticationWindow);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setEnabled(true);
        usernameEdit->setGeometry(QRect(370, 380, 280, 30));
        passwordEdit = new QLineEdit(AuthenticationWindow);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(370, 430, 280, 30));
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);
        label = new QLabel(AuthenticationWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 380, 211, 31));
        label->setFont(font);
        label_2 = new QLabel(AuthenticationWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 430, 211, 31));
        label_2->setFont(font);
        label_3 = new QLabel(AuthenticationWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(225, 20, 350, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(48);
        font1.setBold(false);
        label_3->setFont(font1);
        label_4 = new QLabel(AuthenticationWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(255, 100, 290, 20));
        label_4->setFont(font);
        label_5 = new QLabel(AuthenticationWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(250, 130, 281, 251));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/images/IMG_2646.png")));
        label_5->raise();
        backButton->raise();
        nextButton->raise();
        usernameEdit->raise();
        passwordEdit->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();

        retranslateUi(AuthenticationWindow);

        QMetaObject::connectSlotsByName(AuthenticationWindow);
    } // setupUi

    void retranslateUi(QWidget *AuthenticationWindow)
    {
        AuthenticationWindow->setWindowTitle(QCoreApplication::translate("AuthenticationWindow", "Form", nullptr));
        backButton->setText(QCoreApplication::translate("AuthenticationWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        nextButton->setText(QCoreApplication::translate("AuthenticationWindow", "\320\222\321\205\320\276\320\264", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("AuthenticationWindow", "\320\222\320\260\321\210\320\265 \320\270\320\274\321\217", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("AuthenticationWindow", "\320\222\320\260\321\210 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label->setText(QCoreApplication::translate("AuthenticationWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\262\320\276\320\265 \320\270\320\274\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("AuthenticationWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("AuthenticationWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("AuthenticationWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\276\320\263\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AuthenticationWindow: public Ui_AuthenticationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHENTICATIONWINDOW_H
