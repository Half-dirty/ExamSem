#include "functions.h"
#include "database.h"
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlError>
#include <QCryptographicHash>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

Functions::Functions(QTcpSocket *socket, QMap<QTcpSocket*, int> &userIds, QObject *parent)
    : QObject(parent), mTcpSocket(socket), userIds(userIds)
{}

void Functions::loginUser(const QString &username, const QString &password)
{
    QString passwordHash = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());

    QSqlQuery query;
    query.prepare("SELECT id FROM users WHERE username = :username AND password_hash = :password_hash");
    query.bindValue(":username", username);
    query.bindValue(":password_hash", passwordHash);

    if (query.exec()) {
        if (query.next()) {
            int id = query.value("id").toInt();
            userIds[mTcpSocket] = id;
            qDebug() << "[Login Success] user_id =" << id;
            mTcpSocket->write("OK\r\n");
        } else {
            mTcpSocket->write("ERROR\r\n");
        }
    } else {
        mTcpSocket->write("ERROR\r\n");
    }
}


void Functions::registerUser(const QString &username, const QString &password)
{
    QString passwordHash = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password_hash) VALUES (:username, :password_hash) RETURNING id");
    query.bindValue(":username", username);
    query.bindValue(":password_hash", passwordHash);

    if (query.exec() && query.next()) {
        int id = query.value("id").toInt();
        userIds[mTcpSocket] = id;
        mTcpSocket->write("OK\r\n");
    } else {
        mTcpSocket->write("ERROR\r\n");
    }
}

QJsonArray Functions::getExamListJSON()
{
    QSqlQuery query("SELECT id, name FROM exams");
    QJsonArray examList;
    while (query.next()) {
        QJsonObject exam;
        exam["id"] = query.value(0).toInt();
        exam["name"] = query.value(1).toString();
        examList.append(exam);
    }
    return examList;
}

QJsonArray Functions::getExamQuestionsJSON(int examId)
{
    QSqlQuery query;
    query.prepare("SELECT question_text, correct_answers, options FROM questions WHERE exam_id = :exam_id");
    query.bindValue(":exam_id", examId);

    QJsonArray questions;
    if(query.exec()){
        while(query.next()){
            QJsonObject question;
            question["text"] = query.value("question_text").toString();
            question["correct_answers"] = QJsonDocument::fromJson(query.value("correct_answers").toString().toUtf8()).array();
            question["options"] = QJsonDocument::fromJson(query.value("options").toString().toUtf8()).array();
            questions.append(question);
        }
    }
    return questions;
}

void Functions::saveExamResults(int userId, int examId, int score, const QJsonArray &answers)
{
    QSqlDatabase::database().transaction(); // <<< начать транзакцию вручную

    QSqlQuery query;
    query.prepare("INSERT INTO results (user_id, exam_id, score, details, passed_at) VALUES (:user_id, :exam_id, :score, :details, NOW())");
    query.bindValue(":user_id", userId);
    query.bindValue(":exam_id", examId);
    query.bindValue(":score", score);

    QJsonObject details;
    details["user_answers"] = answers;
    QJsonArray correctAnswers = getCorrectAnswers(examId);
    details["correct_answers"] = correctAnswers;

    QJsonDocument doc(details);
    query.bindValue(":details", QString::fromUtf8(doc.toJson(QJsonDocument::Compact)));

    QSqlDatabase db = QSqlDatabase::database();

    if (query.exec()) {

        if (QSqlDatabase::database().commit()) {
        }
        QJsonObject response;
        response["status"] = "OK";
        response["correct_answers"] = correctAnswers;
        QJsonDocument respDoc(response);
        mTcpSocket->write(respDoc.toJson(QJsonDocument::Compact));
    } else {
        QSqlDatabase::database().rollback(); // Откат если ошибка
        mTcpSocket->write("ERROR\r\n");
    }
}



QJsonArray Functions::getCorrectAnswers(int examId)
{
    QSqlQuery query;
    query.prepare("SELECT correct_answers FROM questions WHERE exam_id = :exam_id");
    query.bindValue(":exam_id", examId);

    QJsonArray correctAnswers;
    if(query.exec()){
        while(query.next()){
            QJsonDocument doc = QJsonDocument::fromJson(query.value(0).toString().toUtf8());
            if(doc.isArray()){
                QJsonArray arr = doc.array();
                if(!arr.isEmpty()){
                    correctAnswers.append(arr.at(0));
                }
            }
        }
    }
    return correctAnswers;
}

void Functions::showStatistics()
{
    QSqlQuery query;
    query.prepare(R"(
        SELECT r.exam_id, e.name, r.score, r.details, r.passed_at
        FROM results r
        JOIN exams e ON r.exam_id = e.id
        WHERE r.user_id = :user_id
    )");
    query.bindValue(":user_id", userIds[mTcpSocket]);

    QJsonArray stats;
    if (query.exec()) {
        while (query.next()) {
            QJsonObject stat;
            stat["exam_id"] = query.value("exam_id").toInt();
            stat["exam_name"] = query.value("name").toString();
            stat["score"] = query.value("score").toInt();
            stat["passed_at"] = query.value("passed_at").toString();

            QString detailsJson = query.value("details").toString();
            QJsonDocument detailsDoc = QJsonDocument::fromJson(detailsJson.toUtf8());
            if (!detailsDoc.isNull() && detailsDoc.isObject()) {
                QJsonObject detailsObj = detailsDoc.object();
                stat["user_answers"] = detailsObj["user_answers"];
                stat["correct_answers"] = detailsObj["correct_answers"];
            }

            stats.append(stat);
        }
        QJsonDocument doc(stats);
        mTcpSocket->write(doc.toJson(QJsonDocument::Compact));
    } else {
        mTcpSocket->write("ERROR\r\n");
    }
}


void Functions::changeUserPassword(int userId, const QString &oldPassword, const QString &newPassword)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT password_hash FROM users WHERE id = :id");
    if (!query.isActive()) {
        qDebug() << "[SERVER DEBUG] Query not active after prepare!";
    }

    query.bindValue(":id", userId);

    if (!query.exec()) {
        qDebug() << "[SERVER DEBUG] Query execution failed:" << query.lastError().text();
    }
    else if (!query.next()) {query.prepare("SELECT password_hash FROM users WHERE id = :id");

        //qDebug() << "[SERVER DEBUG] No user found with id:" << userId;
    }
    else {
        QString currentHash = query.value("password_hash").toString();
        QString oldHash = QString(QCryptographicHash::hash(oldPassword.toUtf8(), QCryptographicHash::Sha256).toHex());

        if (currentHash == oldHash) {
            QSqlQuery updateQuery;
            QString newHash = QString(QCryptographicHash::hash(newPassword.toUtf8(), QCryptographicHash::Sha256).toHex());
            updateQuery.prepare("UPDATE users SET password_hash = :password_hash WHERE id = :id");
            updateQuery.bindValue(":password_hash", newHash);
            updateQuery.bindValue(":id", userId);

            if (updateQuery.exec()) {
                mTcpSocket->write("OK\r\n");
                return;
            }
        } else {
            qDebug() << "[SERVER DEBUG] Пароли не совпадают!";
        }
    }
    mTcpSocket->write("ERROR\r\n");
}
