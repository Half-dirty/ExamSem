#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QTcpSocket>
#include <QMap>

class Functions : public QObject
{
    Q_OBJECT
public:
    explicit Functions(QTcpSocket *socket, QMap<QTcpSocket*, int> &userIds, QObject *parent = nullptr);

    void loginUser(const QString &username, const QString &password);
    void registerUser(const QString &username, const QString &password);
    QJsonArray getExamListJSON();
    QJsonArray getExamQuestionsJSON(int examId);
    void showStatistics();
    void saveExamResults(int userId, int examId, int score, const QJsonArray &answers);
    void changeUserPassword(int userId, const QString &oldPassword, const QString &newPassword);

private:
    QJsonArray getCorrectAnswers(int examId);

    QTcpSocket *mTcpSocket;
    QMap<QTcpSocket*, int> &userIds;
};

#endif

