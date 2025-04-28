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
}

AuthenticationWindow::~AuthenticationWindow()
{
    delete ui;
}

void AuthenticationWindow::setClient(Client *client)
{
    m_client = client;
    connect(m_client, &Client::loginError, this, &AuthenticationWindow::handleLoginError);
    connect(m_client, &Client::loginSuccess, this, &AuthenticationWindow::handleLoginSuccess);
}

void AuthenticationWindow::on_nextButton_clicked()
{
    if (!m_client)
        return;
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    m_client->loginUser(username, password);
}

void AuthenticationWindow::on_backButton_clicked()
{
    emit backRequested();
}

void AuthenticationWindow::handleLoginError(const QString &errorMessage)
{
    QMessageBox::critical(this, "Ошибка входа", errorMessage);
}

void AuthenticationWindow::handleLoginSuccess()
{
    emit authenticationSucceeded();
}
