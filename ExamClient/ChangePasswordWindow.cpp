#include "ChangePasswordWindow.h"
#include "ui_ChangePasswordWindow.h"
#include "Client.h"
#include <QMessageBox>

ChangePasswordWindow::ChangePasswordWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePasswordWindow),
    m_client(nullptr)
{
    ui->setupUi(this);

    ui->oldPasswordEdit->setEchoMode(QLineEdit::Password);
    ui->newPasswordEdit->setEchoMode(QLineEdit::Password);
    ui->confirmPasswordEdit->setEchoMode(QLineEdit::Password);
}

ChangePasswordWindow::~ChangePasswordWindow()
{
    delete ui;
}

void ChangePasswordWindow::setClient(Client *client)
{
    m_client = client;
}

void ChangePasswordWindow::on_applyPasswordButton_clicked()
{
    if (!m_client)
        return;

    QString oldPassword = ui->oldPasswordEdit->text();
    QString newPassword = ui->newPasswordEdit->text();
    QString confirmPassword = ui->confirmPasswordEdit->text();

    if (newPassword != confirmPassword) {
        QMessageBox::warning(this, "Ошибка", "Новый пароль и подтверждение не совпадают!");
        return;
    }
    if (newPassword.isEmpty() || oldPassword.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Заполните все поля!");
        return;
    }

    m_client->changePassword(oldPassword, newPassword);
}

void ChangePasswordWindow::on_backButton_clicked()
{
    emit backRequested();
}
