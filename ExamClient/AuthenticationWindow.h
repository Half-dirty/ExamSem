#ifndef AUTHENTICATIONWINDOW_H
#define AUTHENTICATIONWINDOW_H

#include <QWidget>

namespace Ui {
class AuthenticationWindow;
}

class Client;

class AuthenticationWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AuthenticationWindow(QWidget *parent = nullptr);
    ~AuthenticationWindow();
    void setClient(Client *client);

signals:
    void authenticationSucceeded();
    void backRequested();

private slots:
    void on_nextButton_clicked();
    void on_backButton_clicked();

    void handleLoginError(const QString &errorMessage);
    void handleLoginSuccess();

private:
    Ui::AuthenticationWindow *ui;
    Client *m_client;
};

#endif
