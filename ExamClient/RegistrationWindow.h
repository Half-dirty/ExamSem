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

    // Устанавливаем клиент для работы с сервером
    void setClient(Client *client);

signals:
    // Сигнал, когда регистрация прошла успешно (можно использовать для перехода к окну аутентификации)
    void registrationSucceeded();
    // Сигнал для возврата на предыдущее окно
    void backRequested();

private slots:
    // Нажатие кнопки «Зарегистрироваться»
    void on_registerButton_clicked();
    // Нажатие кнопки «Назад»
    void on_backButton_clicked();

    // Обработка ответа сервера для регистрации
    void handleRegistrationError(const QString &errorMessage);
    void handleRegistrationSuccess();

private:
    Ui::RegistrationWindow *ui;
    Client *m_client;
};

#endif // REGISTRATIONWINDOW_H
