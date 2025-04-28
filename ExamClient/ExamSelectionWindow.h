#ifndef EXAMSELECTIONWINDOW_H
#define EXAMSELECTIONWINDOW_H

#include <QWidget>
#include <QJsonArray>

namespace Ui {
class ExamSelectionWindow;
}

class ExamSelectionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ExamSelectionWindow(QWidget *parent = nullptr);
    ~ExamSelectionWindow();
    void loadExamList(const QJsonArray &examList);

signals:
    void examSelected(int examId);
    void backRequested();

private slots:
    void on_selectExamButton_clicked();
    void on_backButton_clicked();

private:
    Ui::ExamSelectionWindow *ui;
};

#endif

