#ifndef EXAMCOMPLETIONWINDOW_H
#define EXAMCOMPLETIONWINDOW_H

#include <QWidget>
#include <QVector>
#include "ExamQuestion.h"

namespace Ui {
class ExamCompletionWindow;
}

class ExamCompletionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ExamCompletionWindow(QWidget *parent = nullptr);
    ~ExamCompletionWindow();

    // Метод для приёма данных об экзамене
    void setResultData(int score,
                       const QVector<ExamQuestion> &questions,
                       const QVector<QString> &userAnswers);

signals:
    // Сигнал, если нужно вернуться в меню
    void exitToMenuRequested();

private slots:
    void on_exitButton_clicked(); // например, если есть кнопка "В меню"

private:
    Ui::ExamCompletionWindow *ui;
};

#endif // EXAMCOMPLETIONWINDOW_H
