#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QByteArray>
#include <QDebug>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QSqlDatabase>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
    bool connectToDatabase(); // Метод для подключения к базе данных
public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();
private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
    //int server_status;
    QSqlDatabase db; // Объект для работы с базой данных

    int currentUserId = -1; // ID текущего пользователя

    void sendMainMenu(); // Отправка главного меню
    void sendLoginMenu(); // Отправка меню входа/регистрации
    void registerUser(const QString &username, const QString &password); // Регистрация пользователя
    void loginUser(const QString &username, const QString &password); // Авторизация пользователя
    void startExam(); // Начало экзамена
    void showStatistics(); // Показать статистику
    QJsonArray getExamQuestions(int examId); // Получить вопросы из базы данных
    void saveExamResults(int userId, int examId, int score, const QJsonArray &answers); // Сохранить результаты
    QJsonArray getCorrectAnswers(int examId);
};
#endif // MYTCPSERVER_H







