#include "StatisticsWindow.h"
#include "ui_StatisticsWindow.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

StatisticsWindow::StatisticsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatisticsWindow)
{
    ui->setupUi(this);
}

StatisticsWindow::~StatisticsWindow()
{
    delete ui;
}

void StatisticsWindow::setStatisticsData(const QJsonArray &stats)
{
    // Очищаем поле
    ui->statsTextEdit->clear();

    // Формируем человекочитаемый текст
    QString resultText;
    for (int i = 0; i < stats.size(); ++i) {
        QJsonObject obj = stats.at(i).toObject();
        int examId = obj["exam_id"].toInt();
        QString examName = obj["exam_name"].toString();
        int score = obj["score"].toInt();

        resultText += QString("Экзамен: %1 (ID=%2)\n").arg(examName).arg(examId);
        resultText += QString("Результат: %1\n").arg(score);

        // Выведем user_answers и correct_answers, если есть
        QJsonArray userAns = obj["user_answers"].toArray();
        QJsonArray correctAns = obj["correct_answers"].toArray();

        resultText += "Ответы пользователя: [ ";
        for (auto val : userAns) {
            resultText += val.toString() + " ";
        }
        resultText += "]\n";

        resultText += "Правильные ответы: [ ";
        for (auto val : correctAns) {
            resultText += val.toString() + " ";
        }
        resultText += "]\n\n";
    }

    ui->statsTextEdit->setPlainText(resultText);
}

void StatisticsWindow::on_backButton_clicked()
{
    emit backRequested();
}
