#include "ExamSelectionWindow.h"
#include "ui_ExamSelectionWindow.h"
#include <QListWidgetItem>
#include <QDebug>
#include <QJsonObject>

ExamSelectionWindow::ExamSelectionWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExamSelectionWindow)
{
    ui->setupUi(this);
    ui->examListWidget->clear();
}

ExamSelectionWindow::~ExamSelectionWindow()
{
    delete ui;
}

void ExamSelectionWindow::loadExamList(const QJsonArray &examList)
{
    ui->examListWidget->clear();
    for (int i = 0; i < examList.size(); ++i) {
        QJsonObject obj = examList.at(i).toObject();
        int examId = obj["id"].toInt();
        QString examName = obj["name"].toString();

        QListWidgetItem *item = new QListWidgetItem(examName);
        item->setData(Qt::UserRole, examId);
        ui->examListWidget->addItem(item);
    }
}

void ExamSelectionWindow::on_selectExamButton_clicked()
{
    QListWidgetItem *item = ui->examListWidget->currentItem();
    if (item) {
        int examId = item->data(Qt::UserRole).toInt();
        emit examSelected(examId);
    } else {
        qDebug() << "Экзамен не выбран!";
    }
}

void ExamSelectionWindow::on_backButton_clicked()
{
    emit backRequested();
}
