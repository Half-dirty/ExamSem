#include "functions.h"
#include "database.h"
#include "databasedestroyer.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

Functions::Functions(QTcpSocket *socket, int &currentUserId, QObject *parent)
    : QObject(parent), mTcpSocket(socket), currentUserId(currentUserId)
{
}

// 1. Аутентификация: сверяем логин/пароль с таблицей users
bool Functions::loginUser(const QString &username, const QString &password)
{
    QString passwordHash = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());

    QSqlQuery query;
    query.prepare("SELECT id FROM users WHERE username = :username AND password_hash = :password_hash");
    query.bindValue(":username", username);
    query.bindValue(":password_hash", passwordHash);

    if (query.exec() && query.next()) {
        currentUserId = query.value("id").toInt();  // Устанавливаем реальный id из таблицы users
        mTcpSocket->write("OK\r\n");  // Или другой ответ
        return true;
    } else {
        mTcpSocket->write("ERROR\r\n");
        return false;
    }
}

// 2. Регистрация: вставляем нового пользователя в таблицу users
void Functions::registerUser(const QString &username, const QString &password)
{
    QString passwordHash = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password_hash) VALUES (:username, :password_hash)");
    query.bindValue(":username", username);
    query.bindValue(":password_hash", passwordHash);

    if(query.exec()){
        mTcpSocket->write("OK\r\n");
    } else {
        mTcpSocket->write("ERROR\r\n");
    }
}

// 3. Получение списка экзаменов из таблицы exams
QJsonArray Functions::getExamListJSON()
{
    QSqlQuery query;
    query.prepare("SELECT id, name FROM exams");

    QJsonArray examList;
    if(query.exec()){
        while(query.next()){
            QJsonObject exam;
            exam["id"] = query.value("id").toInt();
            exam["name"] = query.value("name").toString();
            examList.append(exam);
        }
    }
    return examList;
}

// 4. Получение вопросов экзамена по examId из таблицы questions
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
            // Предполагается, что поля correct_answers и options хранятся как JSON-строки
            question["correct_answers"] = QJsonDocument::fromJson(query.value("correct_answers").toString().toUtf8()).array();
            question["options"] = QJsonDocument::fromJson(query.value("options").toString().toUtf8()).array();
            questions.append(question);
        }
    }
    return questions;
}

// 5. Сохранение результатов экзамена и отправка корректных ответов клиенту
void Functions::saveExamResults(int userId, int examId, int score, const QJsonArray &answers)
{
    QSqlQuery query;
    query.prepare("INSERT INTO results (user_id, exam_id, score, details) VALUES (:user_id, :exam_id, :score, :details)");
    query.bindValue(":user_id", userId);
    query.bindValue(":exam_id", examId);
    query.bindValue(":score", score);

    // Формируем JSON-объект для столбца details
    QJsonObject details;
    details["user_answers"] = answers;
    QJsonArray correctAnswers = getCorrectAnswers(examId);
    details["correct_answers"] = correctAnswers;

    QJsonDocument doc(details);
    QString jsonString = doc.toJson(QJsonDocument::Compact);

    query.bindValue(":details", jsonString);

    if(query.exec()){
        // При успешном сохранении отправляем клиенту JSON с корректными ответами
        QJsonObject response;
        response["status"] = "OK";
        response["correct_answers"] = correctAnswers;
        QJsonDocument respDoc(response);
        mTcpSocket->write(respDoc.toJson(QJsonDocument::Compact));
    } else {
        mTcpSocket->write("ERROR\r\n");
    }
}

// Метод для получения правильных ответов для заданного экзамена
QJsonArray Functions::getCorrectAnswers(int examId)
{
    QSqlQuery query;
    query.prepare("SELECT correct_answers FROM questions WHERE exam_id = :exam_id");
    query.bindValue(":exam_id", examId);

    QJsonArray correctAnswers;
    if(query.exec()){
        while(query.next()){
            QString jsonStr = query.value("correct_answers").toString();
            QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8());
            if(doc.isArray()){
                QJsonArray arr = doc.array();
                // Предположим, для каждого вопроса нас интересует первый правильный ответ
                if(!arr.isEmpty()){
                    correctAnswers.append(arr.at(0));
                }
            }
        }
    }
    return correctAnswers;
}

// 6. Получение статистики для текущего пользователя
void Functions::showStatistics()
{
    QSqlQuery query;
    query.prepare("SELECT r.exam_id, r.score, e.name, details FROM results r JOIN exams e ON r.exam_id = e.id WHERE r.user_id = :user_id");
    query.bindValue(":user_id", currentUserId);

    QJsonArray stats;
    if (query.exec()) {
        while (query.next()) {
            QJsonObject stat;
            stat["exam_id"] = query.value("exam_id").toInt();
            stat["exam_name"] = query.value("name").toString();
            stat["score"] = query.value("score").toInt();
            // Здесь можно добавить обработку details, если нужно
            stats.append(stat);
        }
        QJsonDocument doc(stats);
        mTcpSocket->write(doc.toJson(QJsonDocument::Compact));
    } else {
        mTcpSocket->write("ERROR\r\n");
    }
}

