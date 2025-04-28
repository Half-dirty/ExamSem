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
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::setClient(Client *client)
{
    m_client = client;
    connect(m_client, &Client::registrationError, this, &RegistrationWindow::handleRegistrationError);
    connect(m_client, &Client::registrationSuccess, this, &RegistrationWindow::handleRegistrationSuccess);
    connect(m_client, &Client::loginSuccess, this, &RegistrationWindow::handleLoginSuccess);
}

void RegistrationWindow::on_registerButton_clicked()
{
    if (!m_client)
        return;

    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    m_lastUsername = username;
    m_lastPassword = password;

    m_client->registerUser(username, password);
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
    QMessageBox::information(this, "Успех", "Регистрация прошла успешно!");

    if (m_client) {
        m_waitingForLoginAfterRegistration = true;
        emit registrationSucceeded();
    }
}

void RegistrationWindow::handleLoginSuccess()
{
    if (m_waitingForLoginAfterRegistration) {
        m_waitingForLoginAfterRegistration = false;
        emit registrationSucceeded();
    }
}

