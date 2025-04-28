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
    void startExamRequested();
    void viewStatisticsRequested();
    void exitRequested();
    void profileRequested();

private slots:
    void on_startExamButton_clicked();
    void on_viewStatisticsButton_clicked();
    void on_exitButton_clicked();
    void on_profileButton_clicked();

private:
    Ui::WelcomeWindow *ui;
};

#endif
