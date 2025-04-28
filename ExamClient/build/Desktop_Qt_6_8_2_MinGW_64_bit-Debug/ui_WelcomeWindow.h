/********************************************************************************
** Form generated from reading UI file 'WelcomeWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEWINDOW_H
#define UI_WELCOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeWindow
{
public:
    QPushButton *startExamButton;
    QPushButton *viewStatisticsButton;
    QPushButton *profileButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *exitButton;

    void setupUi(QWidget *WelcomeWindow)
    {
        if (WelcomeWindow->objectName().isEmpty())
            WelcomeWindow->setObjectName("WelcomeWindow");
        WelcomeWindow->resize(800, 600);
        startExamButton = new QPushButton(WelcomeWindow);
        startExamButton->setObjectName("startExamButton");
        startExamButton->setGeometry(QRect(295, 270, 210, 50));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(14);
        startExamButton->setFont(font);
        viewStatisticsButton = new QPushButton(WelcomeWindow);
        viewStatisticsButton->setObjectName("viewStatisticsButton");
        viewStatisticsButton->setGeometry(QRect(295, 340, 210, 50));
        viewStatisticsButton->setFont(font);
        profileButton = new QPushButton(WelcomeWindow);
        profileButton->setObjectName("profileButton");
        profileButton->setGeometry(QRect(295, 410, 210, 50));
        profileButton->setFont(font);
        label = new QLabel(WelcomeWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 50, 211, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Times New Roman")});
        font1.setPointSize(18);
        label->setFont(font1);
        label_2 = new QLabel(WelcomeWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 82, 451, 101));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(82);
        label_2->setFont(font2);
        label_3 = new QLabel(WelcomeWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 190, 431, 31));
        label_3->setFont(font1);
        exitButton = new QPushButton(WelcomeWindow);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(295, 480, 210, 50));
        exitButton->setFont(font);

        retranslateUi(WelcomeWindow);

        QMetaObject::connectSlotsByName(WelcomeWindow);
    } // setupUi

    void retranslateUi(QWidget *WelcomeWindow)
    {
        WelcomeWindow->setWindowTitle(QCoreApplication::translate("WelcomeWindow", "Form", nullptr));
        startExamButton->setText(QCoreApplication::translate("WelcomeWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \321\215\320\272\320\267\320\260\320\274\320\265\320\275", nullptr));
        viewStatisticsButton->setText(QCoreApplication::translate("WelcomeWindow", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203", nullptr));
        profileButton->setText(QCoreApplication::translate("WelcomeWindow", "\320\233\320\270\321\207\320\275\321\213\320\271 \320\272\320\260\320\261\320\270\320\275\320\265\321\202", nullptr));
        label->setText(QCoreApplication::translate("WelcomeWindow", "\320\224\320\276\320\261\321\200\320\276 \320\277\320\276\320\266\320\260\320\273\320\276\320\262\320\260\321\202\321\214 \320\262", nullptr));
        label_2->setText(QCoreApplication::translate("WelcomeWindow", "ExamSem", nullptr));
        label_3->setText(QCoreApplication::translate("WelcomeWindow", "- \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203 \320\264\320\273\321\217 \320\277\321\200\320\276\321\205\320\276\320\266\320\264\320\265\320\275\320\270\321\217 \321\215\320\272\320\267\320\260\320\274\320\265\320\275\320\276\320\262", nullptr));
        exitButton->setText(QCoreApplication::translate("WelcomeWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomeWindow: public Ui_WelcomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEWINDOW_H
