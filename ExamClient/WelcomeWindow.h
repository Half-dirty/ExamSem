#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QWidget>

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget *parent = nullptr);
    ~WelcomeWindow();

signals:
    // Сигналы для перехода на соответствующие экраны
    void startExamRequested();
    void viewStatisticsRequested();
    void exitRequested();

private slots:
    // Слоты, которые автоматически вызываются при клике на кнопки
    void on_startExamButton_clicked();
    void on_viewStatisticsButton_clicked();
    void on_exitButton_clicked();

private:
    Ui::WelcomeWindow *ui;
};

#endif // WELCOMEWINDOW_H
