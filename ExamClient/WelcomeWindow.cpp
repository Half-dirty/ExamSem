#include "WelcomeWindow.h"
#include "ui_WelcomeWindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_startExamButton_clicked()
{
    emit startExamRequested();
}

void WelcomeWindow::on_viewStatisticsButton_clicked()
{
    emit viewStatisticsRequested();
}

void WelcomeWindow::on_exitButton_clicked()
{
    emit exitRequested();
}

void WelcomeWindow::on_profileButton_clicked()
{
    emit profileRequested();
}
