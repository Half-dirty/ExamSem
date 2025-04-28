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
    originalStats = stats;

    ui->subjectComboBox->clear();
    ui->subjectComboBox->addItem("Все");

    QSet<QString> subjects;

    for (const QJsonValue &val : stats) {
        QJsonObject obj = val.toObject();
        QString examName = obj["exam_name"].toString();
        subjects.insert(examName);
    }

    for (const QString &subject : subjects) {
        ui->subjectComboBox->addItem(subject);
    }

    applyFilters();
}



void StatisticsWindow::on_backButton_clicked()
{
    emit backRequested();
}

void StatisticsWindow::applyFilters()
{
    ui->statsTextEdit->clear();

    QString selectedSubject = ui->subjectComboBox->currentText();
    QDate fromDate = ui->dateFromEdit->date();
    QDate toDate = ui->dateToEdit->date();

    QString resultText;

    for (const QJsonValue &val : originalStats) {
        QJsonObject obj = val.toObject();
        QString examName = obj["exam_name"].toString();
        int score = obj["score"].toInt();
        QString passedAtRaw = obj["passed_at"].toString();
        QDateTime passedAt = QDateTime::fromString(passedAtRaw, Qt::ISODate).toLocalTime();


        if (selectedSubject != "Все" && examName != selectedSubject) {
            continue;
        }

        if (passedAt.date() < fromDate || passedAt.date() > toDate) {
            continue;
        }

        QString dateStr = passedAt.date().toString("dd.MM.yyyy");
        QString timeStr = passedAt.time().toString("HH:mm");

        resultText += QString("Экзамен: %1 | Баллы: %2 | Сдан: %3 в %4\n\n")
                          .arg(examName)
                          .arg(score)
                          .arg(dateStr)
                          .arg(timeStr);
    }

    if (resultText.isEmpty()) {
        resultText = "Нет результатов по выбранным фильтрам.";
    }

    ui->statsTextEdit->setPlainText(resultText);
}

void StatisticsWindow::on_applyFilterButton_clicked()
{
    applyFilters();
}
