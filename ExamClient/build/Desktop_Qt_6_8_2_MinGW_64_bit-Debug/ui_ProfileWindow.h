/********************************************************************************
** Form generated from reading UI file 'ProfileWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEWINDOW_H
#define UI_PROFILEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelFullName;
    QLineEdit *fullNameEdit;
    QLabel *labelBirthDate;
    QDateEdit *birthDateEdit;
    QLabel *labelEmail;
    QLineEdit *emailEdit;
    QPushButton *saveButton;
    QPushButton *backButton;
    QLabel *label_3;
    QPushButton *changePasswordButton;

    void setupUi(QWidget *ProfileWindow)
    {
        if (ProfileWindow->objectName().isEmpty())
            ProfileWindow->setObjectName("ProfileWindow");
        ProfileWindow->resize(800, 600);
        verticalLayoutWidget = new QWidget(ProfileWindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 140, 731, 331));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelFullName = new QLabel(verticalLayoutWidget);
        labelFullName->setObjectName("labelFullName");
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(18);
        labelFullName->setFont(font);

        verticalLayout_2->addWidget(labelFullName);

        fullNameEdit = new QLineEdit(verticalLayoutWidget);
        fullNameEdit->setObjectName("fullNameEdit");
        fullNameEdit->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fullNameEdit->sizePolicy().hasHeightForWidth());
        fullNameEdit->setSizePolicy(sizePolicy);
        fullNameEdit->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(12);
        fullNameEdit->setFont(font1);
        fullNameEdit->setPlaceholderText(QString::fromUtf8("\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\244\320\230\320\236"));

        verticalLayout_2->addWidget(fullNameEdit);

        labelBirthDate = new QLabel(verticalLayoutWidget);
        labelBirthDate->setObjectName("labelBirthDate");
        labelBirthDate->setFont(font);

        verticalLayout_2->addWidget(labelBirthDate);

        birthDateEdit = new QDateEdit(verticalLayoutWidget);
        birthDateEdit->setObjectName("birthDateEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(birthDateEdit->sizePolicy().hasHeightForWidth());
        birthDateEdit->setSizePolicy(sizePolicy1);
        birthDateEdit->setFont(font1);

        verticalLayout_2->addWidget(birthDateEdit);

        labelEmail = new QLabel(verticalLayoutWidget);
        labelEmail->setObjectName("labelEmail");
        labelEmail->setFont(font);

        verticalLayout_2->addWidget(labelEmail);

        emailEdit = new QLineEdit(verticalLayoutWidget);
        emailEdit->setObjectName("emailEdit");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(emailEdit->sizePolicy().hasHeightForWidth());
        emailEdit->setSizePolicy(sizePolicy2);
        emailEdit->setFont(font1);

        verticalLayout_2->addWidget(emailEdit);

        saveButton = new QPushButton(ProfileWindow);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(610, 530, 130, 40));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(14);
        saveButton->setFont(font2);
        backButton = new QPushButton(ProfileWindow);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(40, 530, 130, 40));
        backButton->setFont(font2);
        label_3 = new QLabel(ProfileWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 25, 460, 100));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Times New Roman")});
        font3.setPointSize(48);
        font3.setBold(false);
        label_3->setFont(font3);
        changePasswordButton = new QPushButton(ProfileWindow);
        changePasswordButton->setObjectName("changePasswordButton");
        changePasswordButton->setGeometry(QRect(310, 530, 180, 40));
        changePasswordButton->setFont(font2);

        retranslateUi(ProfileWindow);

        QMetaObject::connectSlotsByName(ProfileWindow);
    } // setupUi

    void retranslateUi(QWidget *ProfileWindow)
    {
        ProfileWindow->setWindowTitle(QCoreApplication::translate("ProfileWindow", "Form", nullptr));
        labelFullName->setText(QCoreApplication::translate("ProfileWindow", "\320\244\320\230\320\236", nullptr));
        fullNameEdit->setText(QString());
        labelBirthDate->setText(QCoreApplication::translate("ProfileWindow", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        labelEmail->setText(QCoreApplication::translate("ProfileWindow", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        emailEdit->setPlaceholderText(QCoreApplication::translate("ProfileWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 email", nullptr));
        saveButton->setText(QCoreApplication::translate("ProfileWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        backButton->setText(QCoreApplication::translate("ProfileWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label_3->setText(QCoreApplication::translate("ProfileWindow", "\320\233\320\270\321\207\320\275\321\213\320\271 \320\272\320\260\320\261\320\270\320\275\320\265\321\202", nullptr));
        changePasswordButton->setText(QCoreApplication::translate("ProfileWindow", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfileWindow: public Ui_ProfileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEWINDOW_H
