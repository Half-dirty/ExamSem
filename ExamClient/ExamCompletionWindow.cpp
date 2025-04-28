#include "ExamCompletionWindow.h"
#include "ui_ExamCompletionWindow.h"
#include <QDebug>

ExamCompletionWindow::ExamCompletionWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExamCompletionWindow)
{
    ui->setupUi(this);
}

ExamCompletionWindow::~ExamCompletionWindow()
{
    delete ui;
}

void ExamCompletionWindow::setResultData(int score,
                                         const QVector<ExamQuestion> &questions,
                                         const QVector<QString> &userAnswers)
{
    ui->scoreLabel->setText(
        QString("Ваш результат: %1 из %2")
            .arg(score)
            .arg(questions.size())
        );

    QString details;
    for (int i = 0; i < questions.size(); ++i) {
        const ExamQuestion &q = questions[i];

        details += QString("Вопрос %1: %2\n")
                       .arg(i + 1)
                       .arg(q.questionText);

        QString userAnswerStr;
        if (i < userAnswers.size()) {
            userAnswerStr = userAnswers[i];
        } else {
            userAnswerStr = "не выбран";
        }
        details += QString("Мой ответ: %1\n").arg(userAnswerStr);

        QString correctAnswerStr = q.correctAnswerText;
        details += QString("Правильный ответ: %1\n\n").arg(correctAnswerStr);
    }

    ui->detailsTextEdit->setPlainText(details);
}


void ExamCompletionWindow::on_exitButton_clicked()
{
    emit exitToMenuRequested();
}
