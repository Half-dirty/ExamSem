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

    void setStatisticsData(const QJsonArray &stats);
    void applyFilters();

signals:
    void backRequested();

private slots:
    void on_backButton_clicked();
    void on_applyFilterButton_clicked();

private:
    QJsonArray originalStats;
    Ui::StatisticsWindow *ui;
};

#endif
