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

    // Передача указателя на Client, который осуществляет связь с сервером
    void setClient(Client *client);

signals:
    // Сигнал, испускаемый при успешном входе – MainWindow переключается на окно приветствия
    void authenticationSucceeded();
    // Сигнал для возврата (если, например, нажата кнопка «Назад»)
    void backRequested();

private slots:
    // Нажатие кнопки «Далее» – отправка логина/пароля
    void on_nextButton_clicked();
    // Нажатие кнопки «Назад»
    void on_backButton_clicked();

    // Обработка ответа от сервера (через Client)
    void handleLoginError(const QString &errorMessage);
    void handleLoginSuccess();

private:
    Ui::AuthenticationWindow *ui;
    Client *m_client;
};

#endif // AUTHENTICATIONWINDOW_H
