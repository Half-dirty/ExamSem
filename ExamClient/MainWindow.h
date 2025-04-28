#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "ExamQuestion.h"
class LoginWindow;
class AuthenticationWindow;
class RegistrationWindow;
class WelcomeWindow;
class ExamSelectionWindow;
class ExamWindow;
class ExamCompletionWindow;
class StatisticsWindow;
class Client;
class ChangePasswordWindow;
class ProfileWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showLogin();
    void showAuthentication();
    void showRegistration();
    void showWelcome();
    void showExamSelection();
    void showExamWindow(int examId);
    void showExamCompletion();
    void showStatistics();
    void showProfile();
    void showChangePasswordWindow();

    void onExamFinished(int examId,
                        int score,
                        const QVector<ExamQuestion> &questions,
                        const QVector<QString> &userAnswers);

private:
    Ui::MainWindow *ui;

    // Указатели на окна
    LoginWindow          *loginWindow;
    AuthenticationWindow *authenticationWindow;
    RegistrationWindow   *registrationWindow;
    WelcomeWindow        *welcomeWindow;
    ExamSelectionWindow  *examSelectionWindow;
    ExamWindow           *examWindow;
    ExamCompletionWindow *examCompletionWindow;
    StatisticsWindow     *statisticsWindow;
    ProfileWindow        *profileWindow;
    ChangePasswordWindow *changePasswordWindow;


    Client *client;

    int currentExamId = -1;
};

#endif
