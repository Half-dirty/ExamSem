#ifndef EXAMWINDOW_H
#define EXAMWINDOW_H

#include <QWidget>
#include <QVector>
#include <QJsonArray>
#include "ExamQuestion.h" // Структура ExamQuestion { QString questionText; QStringList options; int correctAnswerIndex; ... }

namespace Ui {
class ExamWindow;
}

class ExamWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ExamWindow(QWidget *parent = nullptr);
    ~ExamWindow();

    // Устанавливаем список вопросов
    void setExamQuestions(int examId, const QVector<ExamQuestion> &questions);

signals:
    void examFinished(int examId,
                      int score,
                      const QVector<ExamQuestion> &questions,
                      const QVector<QString> &userAnswers);

private slots:
    // Слот, вызываемый при нажатии кнопки (PushButton)
    void on_pushButton_clicked();

private:
    Ui::ExamWindow *ui;

    // Список вопросов
    QVector<ExamQuestion> m_questions;

    // Индекс текущего вопроса
    int m_currentIndex;

    // Набранные баллы
    int m_score;

    // Ответы пользователя (индексы выбранных вариантов)
    QVector<int> m_userAnswers;

    // Отображаем текущий вопрос
    void displayCurrentQuestion();

    int m_examId = -1;

};

#endif // EXAMWINDOW_H
