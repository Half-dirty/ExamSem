#include "MainWindow.h"
#include "ui_MainWindow.h"

// Подключаем заголовки всех окон и клиента
#include "LoginWindow.h"
#include "AuthenticationWindow.h"
#include "RegistrationWindow.h"
#include "WelcomeWindow.h"
#include "ExamSelectionWindow.h"
#include "ExamWindow.h"
#include "ExamCompletionWindow.h"
#include "StatisticsWindow.h"
#include "Client.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создаём объект клиента
    client = Client::getInstance();


    // Создаём окна
    loginWindow          = new LoginWindow(this);
    authenticationWindow = new AuthenticationWindow(this);
    registrationWindow   = new RegistrationWindow(this);
    welcomeWindow        = new WelcomeWindow(this);
    examSelectionWindow  = new ExamSelectionWindow(this);
    examWindow           = new ExamWindow(this);
    examCompletionWindow = new ExamCompletionWindow(this);
    statisticsWindow     = new StatisticsWindow(this);

    // Передаём клиент, если нужно
    authenticationWindow->setClient(client);
    registrationWindow->setClient(client);

    // Добавляем окна в QStackedWidget (objectName="stackedWidget" в MainWindow.ui)
    ui->stackedWidget->addWidget(loginWindow);
    ui->stackedWidget->addWidget(authenticationWindow);
    ui->stackedWidget->addWidget(registrationWindow);
    ui->stackedWidget->addWidget(welcomeWindow);
    ui->stackedWidget->addWidget(examSelectionWindow);
    ui->stackedWidget->addWidget(examWindow);
    ui->stackedWidget->addWidget(examCompletionWindow);
    ui->stackedWidget->addWidget(statisticsWindow);

    // Подключаем сигналы от loginWindow
    connect(loginWindow, &LoginWindow::registrationRequested, this, &MainWindow::showRegistration);
    connect(loginWindow, &LoginWindow::loginRequested,        this, &MainWindow::showAuthentication);

    // Подключаем сигналы от authenticationWindow
    connect(authenticationWindow, &AuthenticationWindow::backRequested,          this, &MainWindow::showLogin);
    connect(authenticationWindow, &AuthenticationWindow::authenticationSucceeded,this, &MainWindow::showWelcome);

    // Подключаем сигналы от registrationWindow
    connect(registrationWindow, &RegistrationWindow::backRequested,         this, &MainWindow::showLogin);
    connect(registrationWindow, &RegistrationWindow::registrationSucceeded, this, &MainWindow::showLogin);

    // Подключаем сигналы от welcomeWindow
    connect(welcomeWindow, &WelcomeWindow::startExamRequested,       this, &MainWindow::showExamSelection);
    connect(welcomeWindow, &WelcomeWindow::viewStatisticsRequested,  this, &MainWindow::showStatistics);
    connect(welcomeWindow, &WelcomeWindow::exitRequested,            this, &MainWindow::close);

    // Подключаем сигналы от examSelectionWindow
    connect(examSelectionWindow, &ExamSelectionWindow::examSelected, this, &MainWindow::showExamWindow);
    connect(examSelectionWindow, &ExamSelectionWindow::backRequested,this, &MainWindow::showWelcome);

    // Подключаем сигнал завершения экзамена от examWindow
    // Предположим, examWindow генерирует сигнал:
    //   examFinished(int examId, int score,
    //                const QVector<ExamQuestion> &questions,
    //                const QVector<int> &userAnswers)
    connect(examWindow, &ExamWindow::examFinished,
            this, &MainWindow::onExamFinished);


    // Подключаем сигнал "выход в меню" из examCompletionWindow
    connect(examCompletionWindow, &ExamCompletionWindow::exitToMenuRequested,
            this, &MainWindow::showWelcome);

    // Подключаем сигналы от statisticsWindow
    connect(statisticsWindow, &StatisticsWindow::backRequested, this, &MainWindow::showWelcome);

    // Подключаем сигналы от клиента
    connect(client, &Client::examListReceived, this, [=](const QJsonArray &examList){
        examSelectionWindow->loadExamList(examList);
    });

    connect(client, &Client::examQuestionsReceived, this, [=](const QVector<ExamQuestion> &questions){
        examWindow->setExamQuestions(currentExamId, questions);
    });

    connect(client, &Client::statisticsReceived, this, [=](const QJsonArray &stats){
        statisticsWindow->setStatisticsData(stats);
    });

    // Начальное окно — окно логина
    ui->stackedWidget->setCurrentWidget(loginWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// --- Методы переключения окон ---

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

void MainWindow::showExamSelection()
{
    client->requestExamList(); // Запрашиваем список экзаменов
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
    // Сохранить результаты
    client->saveExamResults(examId, score, questions, userAnswers);

    // Отобразить в examCompletionWindow
    examCompletionWindow->setResultData(score, questions, userAnswers);

    // Переключиться на окно результатов
    ui->stackedWidget->setCurrentWidget(examCompletionWindow);
}
