#include "RegistrationWindow.h"
#include "ui_RegistrationWindow.h"
#include "Client.h"
#include <QMessageBox>

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistrationWindow),
    m_client(nullptr)
{
    ui->setupUi(this);
    // В .ui файле должны быть:
    // QLineEdit "usernameEdit", QLineEdit "passwordEdit"
    // QPushButton "registerButton" для регистрации
    // QPushButton "backButton" для возврата
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::setClient(Client *client)
{
    m_client = client;
    // Предположим, что Client генерирует следующие сигналы для регистрации:
    // registrationError(const QString&) и registrationSuccess()
    connect(m_client, &Client::registrationError, this, &RegistrationWindow::handleRegistrationError);
    connect(m_client, &Client::registrationSuccess, this, &RegistrationWindow::handleRegistrationSuccess);
}

void RegistrationWindow::on_registerButton_clicked()
{
    if (!m_client)
        return;
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    m_client->registerUser(username, password);
    // Ждём ответа от сервера – обработчики handleRegistrationSuccess или handleRegistrationError
}

void RegistrationWindow::on_backButton_clicked()
{
    emit backRequested();
}

void RegistrationWindow::handleRegistrationError(const QString &errorMessage)
{
    QMessageBox::critical(this, "Ошибка регистрации", errorMessage);
}

void RegistrationWindow::handleRegistrationSuccess()
{
    QMessageBox::information(this, "Успех", "Регистрация прошла успешно.");
    emit registrationSucceeded();
}
