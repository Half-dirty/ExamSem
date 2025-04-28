#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

signals:
    void registrationRequested();
    void loginRequested();

private slots:
    void on_registerButton_clicked();
    void on_loginButton_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif
