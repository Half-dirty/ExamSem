#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QTcpSocket>

class Functions : public QObject
{
    Q_OBJECT
public:
    // currentUserId передается по ссылке для сохранения id авторизованного пользователя
    explicit Functions(QTcpSocket *socket, int &currentUserId, QObject *parent = nullptr);

    // Аутентификация и регистрация
    bool loginUser(const QString &username, const QString &password);
    void registerUser(const QString &username, const QString &password);

    // Получение данных для клиента
    QJsonArray getExamListJSON();
    QJsonArray getExamQuestionsJSON(int examId);
    void showStatistics();

    // Сохранение результатов экзамена
    void saveExamResults(int userId, int examId, int score, const QJsonArray &answers);

private:
    // Метод для получения правильных ответов для экзамена
    QJsonArray getCorrectAnswers(int examId);

    QTcpSocket *mTcpSocket;
    int &currentUserId;
};

#endif // FUNCTIONS_H
