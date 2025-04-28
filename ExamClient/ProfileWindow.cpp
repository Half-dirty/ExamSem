#include "ProfileWindow.h"
#include "ui_ProfileWindow.h"
#include "Client.h"

ProfileWindow::ProfileWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileWindow),
    m_client(nullptr)
{
    ui->setupUi(this);
}

ProfileWindow::~ProfileWindow()
{
    delete ui;
}

void ProfileWindow::setClient(Client *client)
{
    m_client = client;
}

void ProfileWindow::loadProfile(const QJsonObject &profile)
{
    ui->fullNameEdit->setText(profile["full_name"].toString());
    ui->birthDateEdit->setDate(QDate::fromString(profile["birth_date"].toString(), "yyyy-MM-dd"));
    ui->emailEdit->setText(profile["email"].toString());
}

void ProfileWindow::on_saveButton_clicked()
{

    if (!m_client)
        return;

    QJsonObject obj;
    obj["full_name"] = ui->fullNameEdit->text();
    obj["birth_date"] = ui->birthDateEdit->date().toString("dd-MM-yyyy");
    obj["email"] = ui->emailEdit->text();

    m_client->updateProfile(obj);
}

void ProfileWindow::on_backButton_clicked()
{
    emit backRequested();
}

void ProfileWindow::on_changePasswordButton_clicked()
{
    emit changePasswordRequested();
}
