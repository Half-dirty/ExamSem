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

    void setResultData(int score,
                       const QVector<ExamQuestion> &questions,
                       const QVector<QString> &userAnswers);

signals:

    void exitToMenuRequested();

private slots:
    void on_exitButton_clicked();

private:
    Ui::ExamCompletionWindow *ui;
};

#endif
