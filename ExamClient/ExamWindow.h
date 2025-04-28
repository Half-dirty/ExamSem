#ifndef EXAMWINDOW_H
#define EXAMWINDOW_H

#include <QWidget>
#include <QVector>
#include <QJsonArray>
#include "ExamQuestion.h"

namespace Ui {
class ExamWindow;
}

class ExamWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ExamWindow(QWidget *parent = nullptr);
    ~ExamWindow();

    void setExamQuestions(int examId, const QVector<ExamQuestion> &questions);

signals:
    void examFinished(int examId,
                      int score,
                      const QVector<ExamQuestion> &questions,
                      const QVector<QString> &userAnswers);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ExamWindow *ui;
    QVector<ExamQuestion> m_questions;
    int m_currentIndex;

    int m_score;

    QVector<int> m_userAnswers;
    void displayCurrentQuestion();

    int m_examId = -1;

};

#endif
