#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonArray>
#include <QVector>
#include "ExamQuestion.h"

class Client : public QObject
{
    Q_OBJECT
public:
    static Client* getInstance();

    // Методы для отправки команд серверу
    void registerUser(const QString &username, const QString &password);
    void loginUser(const QString &username, const QString &password);
    void requestExamQuestions(int examId);
    void requestExamResult(int examId);
    void requestExamList();
    void requestStatistics();
    void saveExamResults(int examId, int score, const QVector<ExamQuestion> &questions, const QVector<QString> &userAnswers);

signals:
    // Сигналы для передачи данных, полученных от сервера
    void examQuestionsReceived(const QVector<ExamQuestion> &questions);
    void examListReceived(const QJsonArray &examList);
    void examResultReceived(const QJsonObject &result);
    void loginError(const QString &errorMessage);
    void loginSuccess();
    void registrationError(const QString&);
    void registrationSuccess();
    void statisticsReceived(const QJsonArray &stats);
    void examFinished(int score,
                      const QVector<ExamQuestion> &questions,
                      const QVector<int> &userAnswers);


private slots:
    void onReadyRead();

private:
    explicit Client(QObject *parent = nullptr);
    // Удаляем конструктор копирования и оператор присваивания
    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;

    // Указатель на сокет
    QTcpSocket *socket;

    // Статический указатель на единственный экземпляр
    static Client* instance;
};

#endif // CLIENT_H
