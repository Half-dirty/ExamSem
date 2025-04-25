#ifndef STATISTICSWINDOW_H
#define STATISTICSWINDOW_H

#include <QWidget>
#include <QJsonArray>

namespace Ui {
class StatisticsWindow;
}

class StatisticsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StatisticsWindow(QWidget *parent = nullptr);
    ~StatisticsWindow();

    // Метод для передачи JSON-массива со статистикой
    void setStatisticsData(const QJsonArray &stats);

signals:
    void backRequested(); // кнопка "Назад"

private slots:
    void on_backButton_clicked();

private:
    Ui::StatisticsWindow *ui;
};

#endif // STATISTICSWINDOW_H
