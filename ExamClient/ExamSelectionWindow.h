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

    // Метод для загрузки списка экзаменов, полученного с сервера
    void loadExamList(const QJsonArray &examList);

signals:
    // Сигнал, отправляющий выбранный идентификатор экзамена
    void examSelected(int examId);
    // Сигнал для возврата к предыдущему окну (например, в главное меню)
    void backRequested();

private slots:
    // Слот, вызываемый при нажатии на кнопку выбора экзамена
    void on_selectExamButton_clicked();
    // Слот для обработки нажатия кнопки "Назад"
    void on_backButton_clicked();

private:
    Ui::ExamSelectionWindow *ui;
};

#endif // EXAMSELECTIONWINDOW_H
