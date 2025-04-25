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
    // Очищаем список при инициализации
    ui->examListWidget->clear();
}

ExamSelectionWindow::~ExamSelectionWindow()
{
    delete ui;
}

void ExamSelectionWindow::loadExamList(const QJsonArray &examList)
{
    // Очищаем список, чтобы не было старых данных
    ui->examListWidget->clear();

    // Обходим каждый объект в JSON-массиве
    for (int i = 0; i < examList.size(); ++i) {
        QJsonObject obj = examList.at(i).toObject();
        int examId = obj["id"].toInt();
        QString examName = obj["name"].toString();

        // Создаем элемент списка и сохраняем id экзамена через UserRole
        QListWidgetItem *item = new QListWidgetItem(examName);
        item->setData(Qt::UserRole, examId);
        ui->examListWidget->addItem(item);
    }
}

void ExamSelectionWindow::on_selectExamButton_clicked()
{
    // Получаем текущий выбранный элемент
    QListWidgetItem *item = ui->examListWidget->currentItem();
    if (item) {
        // Извлекаем examId, сохраненный в данных элемента
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
