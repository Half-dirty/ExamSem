#include "AuthenticationWindow.h"
#include "ui_AuthenticationWindow.h"
#include "Client.h"
#include <QMessageBox>

AuthenticationWindow::AuthenticationWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthenticationWindow),
    m_client(nullptr)
{
    ui->setupUi(this);
    // Например, в .ui файле должны быть:
    // QLineEdit с objectName "usernameEdit"
    // QLineEdit с objectName "passwordEdit"
    // QPushButton с objectName "nextButton" (для отправки данных)
    // QPushButton с objectName "backButton" (для возврата)
}

AuthenticationWindow::~AuthenticationWindow()
{
    delete ui;
}

void AuthenticationWindow::setClient(Client *client)
{
    m_client = client;
    // Подключаем сигналы от клиента для обработки ответа сервера при логине
    connect(m_client, &Client::loginError, this, &AuthenticationWindow::handleLoginError);
    connect(m_client, &Client::loginSuccess, this, &AuthenticationWindow::handleLoginSuccess);
}

void AuthenticationWindow::on_nextButton_clicked()
{
    if (!m_client)
        return;
    // Считываем данные из полей
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    // Отправляем данные на сервер для проверки
    m_client->loginUser(username, password);
    // Не переключаем окно сразу – ждём ответ (обработчик handleLoginSuccess/handleLoginError)
}

void AuthenticationWindow::on_backButton_clicked()
{
    emit backRequested();
}

void AuthenticationWindow::handleLoginError(const QString &errorMessage)
{
    // Выводим сообщение об ошибке через модальное окно
    QMessageBox::critical(this, "Ошибка входа", errorMessage);
}

void AuthenticationWindow::handleLoginSuccess()
{
    // Если сервер подтвердил логин, испускаем сигнал успешной аутентификации
    emit authenticationSucceeded();
}
