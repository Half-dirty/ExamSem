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
    // Заголовок с общим результатом
    ui->scoreLabel->setText(
        QString("Ваш результат: %1 из %2")
            .arg(score)
            .arg(questions.size())
        );

    // Формируем подробный текст с деталями
    QString details;
    for (int i = 0; i < questions.size(); ++i) {
        const ExamQuestion &q = questions[i];

        // Выводим текст вопроса
        details += QString("Вопрос %1: %2\n")
                       .arg(i + 1)
                       .arg(q.questionText);

        // Получаем строку ответа пользователя (а не индекс!)
        QString userAnswerStr;
        if (i < userAnswers.size()) {
            userAnswerStr = userAnswers[i];
        } else {
            userAnswerStr = "не выбран";
        }
        details += QString("Мой ответ: %1\n").arg(userAnswerStr);

        // Предположим, в ExamQuestion есть поле correctAnswerText
        QString correctAnswerStr = q.correctAnswerText;
        details += QString("Правильный ответ: %1\n\n").arg(correctAnswerStr);
    }

    // Показываем всё в detailsTextEdit
    ui->detailsTextEdit->setPlainText(details);
}


void ExamCompletionWindow::on_exitButton_clicked()
{
    emit exitToMenuRequested();
}
