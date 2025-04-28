/********************************************************************************
** Form generated from reading UI file 'ChangePasswordWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORDWINDOW_H
#define UI_CHANGEPASSWORDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangePasswordWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *oldPasswordEdit;
    QLabel *label_4;
    QLineEdit *newPasswordEdit;
    QLabel *label;
    QLineEdit *confirmPasswordEdit;
    QLabel *label_3;
    QPushButton *applyPasswordButton;
    QPushButton *backButton;

    void setupUi(QWidget *ChangePasswordWindow)
    {
        if (ChangePasswordWindow->objectName().isEmpty())
            ChangePasswordWindow->setObjectName("ChangePasswordWindow");
        ChangePasswordWindow->resize(800, 600);
        verticalLayoutWidget = new QWidget(ChangePasswordWindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(9, 119, 781, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(18);
        label_2->setFont(font);
        label_2->setTabletTracking(false);
        label_2->setFocusPolicy(Qt::FocusPolicy::StrongFocus);

        verticalLayout->addWidget(label_2);

        oldPasswordEdit = new QLineEdit(verticalLayoutWidget);
        oldPasswordEdit->setObjectName("oldPasswordEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(oldPasswordEdit->sizePolicy().hasHeightForWidth());
        oldPasswordEdit->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(14);
        oldPasswordEdit->setFont(font1);
        oldPasswordEdit->setTabletTracking(false);
        oldPasswordEdit->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        oldPasswordEdit->setEchoMode(QLineEdit::EchoMode::PasswordEchoOnEdit);

        verticalLayout->addWidget(oldPasswordEdit);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setTabletTracking(false);
        label_4->setFocusPolicy(Qt::FocusPolicy::StrongFocus);

        verticalLayout->addWidget(label_4);

        newPasswordEdit = new QLineEdit(verticalLayoutWidget);
        newPasswordEdit->setObjectName("newPasswordEdit");
        sizePolicy.setHeightForWidth(newPasswordEdit->sizePolicy().hasHeightForWidth());
        newPasswordEdit->setSizePolicy(sizePolicy);
        newPasswordEdit->setFont(font1);
        newPasswordEdit->setTabletTracking(false);
        newPasswordEdit->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        newPasswordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(newPasswordEdit);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setFont(font);
        label->setTabletTracking(false);
        label->setFocusPolicy(Qt::FocusPolicy::StrongFocus);

        verticalLayout->addWidget(label);

        confirmPasswordEdit = new QLineEdit(verticalLayoutWidget);
        confirmPasswordEdit->setObjectName("confirmPasswordEdit");
        sizePolicy.setHeightForWidth(confirmPasswordEdit->sizePolicy().hasHeightForWidth());
        confirmPasswordEdit->setSizePolicy(sizePolicy);
        confirmPasswordEdit->setFont(font1);
        confirmPasswordEdit->setTabletTracking(false);
        confirmPasswordEdit->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        confirmPasswordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(confirmPasswordEdit);

        label_3 = new QLabel(ChangePasswordWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(205, 10, 390, 100));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(48);
        font2.setBold(false);
        label_3->setFont(font2);
        applyPasswordButton = new QPushButton(ChangePasswordWindow);
        applyPasswordButton->setObjectName("applyPasswordButton");
        applyPasswordButton->setGeometry(QRect(258, 450, 284, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Times New Roman")});
        font3.setPointSize(18);
        font3.setBold(false);
        applyPasswordButton->setFont(font3);
        backButton = new QPushButton(ChangePasswordWindow);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(40, 530, 130, 40));
        backButton->setFont(font1);

        retranslateUi(ChangePasswordWindow);

        QMetaObject::connectSlotsByName(ChangePasswordWindow);
    } // setupUi

    void retranslateUi(QWidget *ChangePasswordWindow)
    {
        ChangePasswordWindow->setWindowTitle(QCoreApplication::translate("ChangePasswordWindow", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("ChangePasswordWindow", "\320\241\321\202\320\260\321\200\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        oldPasswordEdit->setPlaceholderText(QCoreApplication::translate("ChangePasswordWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\321\202\320\260\321\200\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("ChangePasswordWindow", "\320\235\320\276\320\262\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        newPasswordEdit->setPlaceholderText(QCoreApplication::translate("ChangePasswordWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\262\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label->setText(QCoreApplication::translate("ChangePasswordWindow", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\275\320\276\320\262\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        confirmPasswordEdit->setPlaceholderText(QCoreApplication::translate("ChangePasswordWindow", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\275\320\276\320\262\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("ChangePasswordWindow", "\320\241\320\274\320\265\320\275\320\260 \320\277\320\260\321\200\320\276\320\273\321\217", nullptr));
        applyPasswordButton->setText(QCoreApplication::translate("ChangePasswordWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        backButton->setText(QCoreApplication::translate("ChangePasswordWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePasswordWindow: public Ui_ChangePasswordWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORDWINDOW_H
