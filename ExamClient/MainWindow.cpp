#include "MainWindow.h"
#include "ui_MainWindow.h"

// Все окна
#include "LoginWindow.h"
#include "AuthenticationWindow.h"
#include "RegistrationWindow.h"
#include "WelcomeWindow.h"
#include "ExamSelectionWindow.h"
#include "ExamWindow.h"
#include "ExamCompletionWindow.h"
#include "StatisticsWindow.h"
#include "Client.h"
#include "ProfileWindow.h"
#include "ChangePasswordWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    client = Client::getInstance();

    loginWindow          = new LoginWindow(this);
    authenticationWindow = new AuthenticationWindow(this);
    registrationWindow   = new RegistrationWindow(this);
    welcomeWindow        = new WelcomeWindow(this);
    examSelectionWindow  = new ExamSelectionWindow(this);
    examWindow           = new ExamWindow(this);
    examCompletionWindow = new ExamCompletionWindow(this);
    statisticsWindow     = new StatisticsWindow(this);
    profileWindow        = new ProfileWindow(this);
    changePasswordWindow = new ChangePasswordWindow(this);

    authenticationWindow->setClient(client);
    registrationWindow->setClient(client);
    profileWindow->setClient(client);
    changePasswordWindow->setClient(client);

    ui->stackedWidget->addWidget(loginWindow);
    ui->stackedWidget->addWidget(authenticationWindow);
    ui->stackedWidget->addWidget(registrationWindow);
    ui->stackedWidget->addWidget(welcomeWindow);
    ui->stackedWidget->addWidget(examSelectionWindow);
    ui->stackedWidget->addWidget(examWindow);
    ui->stackedWidget->addWidget(examCompletionWindow);
    ui->stackedWidget->addWidget(statisticsWindow);
    ui->stackedWidget->addWidget(profileWindow);
    ui->stackedWidget->addWidget(changePasswordWindow);


    connect(loginWindow, &LoginWindow::registrationRequested, this, &MainWindow::showRegistration);
    connect(loginWindow, &LoginWindow::loginRequested,        this, &MainWindow::showAuthentication);

    connect(authenticationWindow, &AuthenticationWindow::authenticationSucceeded,  this, &MainWindow::showWelcome);
    connect(authenticationWindow, &AuthenticationWindow::backRequested,            this, &MainWindow::showLogin);

    connect(registrationWindow, &RegistrationWindow::registrationSucceeded, this, &MainWindow::showWelcome);
    connect(registrationWindow, &RegistrationWindow::backRequested,         this, &MainWindow::showLogin);

    connect(welcomeWindow, &WelcomeWindow::startExamRequested,      this, &MainWindow::showExamSelection);
    connect(welcomeWindow, &WelcomeWindow::viewStatisticsRequested, this, &MainWindow::showStatistics);
    connect(welcomeWindow, &WelcomeWindow::exitRequested,           this, &MainWindow::close);
    connect(welcomeWindow, &WelcomeWindow::profileRequested,        this, &MainWindow::showProfile);

    connect(profileWindow, &ProfileWindow::backRequested,           this, &MainWindow::showWelcome);
    connect(profileWindow, &ProfileWindow::changePasswordRequested, this, &MainWindow::showChangePasswordWindow);

    connect(changePasswordWindow, &ChangePasswordWindow::backRequested, this, &MainWindow::showProfile);

    connect(examSelectionWindow, &ExamSelectionWindow::examSelected,  this, &MainWindow::showExamWindow);
    connect(examSelectionWindow, &ExamSelectionWindow::backRequested, this, &MainWindow::showWelcome);

    connect(examWindow, &ExamWindow::examFinished,                            this, &MainWindow::onExamFinished);
    connect(examCompletionWindow, &ExamCompletionWindow::exitToMenuRequested, this, &MainWindow::showWelcome);

    connect(statisticsWindow, &StatisticsWindow::backRequested, this, &MainWindow::showWelcome);

    connect(client, &Client::examListReceived, this, [=](const QJsonArray &examList){
        examSelectionWindow->loadExamList(examList);
    });

    connect(client, &Client::examQuestionsReceived, this, [=](const QVector<ExamQuestion> &questions){
        examWindow->setExamQuestions(currentExamId, questions);
    });

    connect(client, &Client::statisticsReceived, this, [=](const QJsonArray &stats){
        statisticsWindow->setStatisticsData(stats);
    });

    connect(client, &Client::profileReceived, this, [=](const QJsonObject &profile){
        profileWindow->loadProfile(profile);
    });


    ui->stackedWidget->setCurrentWidget(loginWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showLogin()
{
    ui->stackedWidget->setCurrentWidget(loginWindow);
}

void MainWindow::showAuthentication()
{
    ui->stackedWidget->setCurrentWidget(authenticationWindow);
}

void MainWindow::showRegistration()
{
    ui->stackedWidget->setCurrentWidget(registrationWindow);
}

void MainWindow::showWelcome()
{
    ui->stackedWidget->setCurrentWidget(welcomeWindow);
}

void MainWindow::showProfile()
{
    client->requestProfile();
    ui->stackedWidget->setCurrentWidget(profileWindow);
}


void MainWindow::showExamSelection()
{
    client->requestExamList();
    ui->stackedWidget->setCurrentWidget(examSelectionWindow);
}

void MainWindow::showExamWindow(int examId)
{
    currentExamId = examId;
    client->requestExamQuestions(examId);
    ui->stackedWidget->setCurrentWidget(examWindow);
}

void MainWindow::showExamCompletion()
{
    ui->stackedWidget->setCurrentWidget(examCompletionWindow);
}

void MainWindow::showStatistics()
{
    client->requestStatistics();
    ui->stackedWidget->setCurrentWidget(statisticsWindow);
}

void MainWindow::onExamFinished(int examId,
                                int score,
                                const QVector<ExamQuestion> &questions,
                                const QVector<QString> &userAnswers)
{
    client->saveExamResults(examId, score, questions, userAnswers);
    examCompletionWindow->setResultData(score, questions, userAnswers);
    ui->stackedWidget->setCurrentWidget(examCompletionWindow);
}

void MainWindow::showChangePasswordWindow()
{
    ui->stackedWidget->setCurrentWidget(changePasswordWindow);
}
