#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QWidget>

namespace Ui {
class RegistrationWindow;
}

class Client;

class RegistrationWindow : public QWidget
{
    Q_OBJECT
public:
    explicit RegistrationWindow(QWidget *parent = nullptr);
    ~RegistrationWindow();

    void setClient(Client *client);

signals:
    void registrationSucceeded();
    void backRequested();

private slots:
    void on_registerButton_clicked();
    void on_backButton_clicked();
    void handleRegistrationError(const QString &errorMessage);
    void handleRegistrationSuccess();
    void handleLoginSuccess();

private:
    Ui::RegistrationWindow *ui;
    Client *m_client;
    QString m_lastUsername;
    QString m_lastPassword;
    bool m_waitingForLoginAfterRegistration = false;
};

#endif

