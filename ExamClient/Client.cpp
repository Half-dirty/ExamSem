#include "Client.h"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QDebug>

Client* Client::instance = nullptr;

Client* Client::getInstance()
{
    if (!instance) {
        instance = new Client(nullptr);
    }
    return instance;
}

Client::Client(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    socket->connectToHost("localhost", 33333);
    if (socket->waitForConnected(3000)) {
        qDebug() << "Подключение к серверу установлено.";
    } else {
        qDebug() << "Не удалось подключиться к серверу!";
    }
    connect(socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
}

void Client::registerUser(const QString &username, const QString &password)
{
    QString request = QString("REGISTER %1 %2").arg(username, password);
    socket->write(request.toUtf8());
    socket->flush();
}

void Client::loginUser(const QString &username, const QString &password)
{
    QString request = QString("LOGIN %1 %2").arg(username, password);
    socket->write(request.toUtf8());
    socket->flush();
}

void Client::requestExamQuestions(int examId)
{
    QString request = QString("GET_QUESTIONS %1").arg(examId);
    socket->write(request.toUtf8());
    socket->flush();
}

void Client::requestStatistics()
{
    QString request = "GET_STATISTICS";
    socket->write(request.toUtf8());
    socket->flush();
}


void Client::requestExamResult(int examId)
{
    QString request = QString("GET_EXAM_RESULT %1").arg(examId);
    socket->write(request.toUtf8());
    socket->flush();
}

void Client::requestExamList()
{
    QString request = "GET_EXAMS";
    socket->write(request.toUtf8());
    socket->flush();
}

void Client::onReadyRead()
{
    QByteArray data = socket->readAll();
    qDebug() << "Сырой ответ от сервера:" << data;

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        // Обработка текстового ответа
        QString textReply = QString::fromUtf8(data).trimmed();
        qDebug() << "Текстовый ответ от сервера:" << textReply;
        if (textReply == "OK") {
            emit loginSuccess();
        } else if (textReply == "ERROR") {
            emit loginError("Неверное имя пользователя или пароль (или другая ошибка).");
        }
        return;
    }

    if (doc.isArray()) {
        QJsonArray arr = doc.array();
        if (arr.isEmpty())
            return;

        QJsonObject firstObj = arr.first().toObject();
        if (firstObj.contains("id")) {
            emit examListReceived(arr);
        }
        else if (firstObj.contains("text")) {
            QVector<ExamQuestion> questions;
            for (const QJsonValue &val : arr) {
                QJsonObject obj = val.toObject();
                ExamQuestion q;
                q.questionText = obj["text"].toString();

                QJsonArray optionsArray = obj["options"].toArray();
                for (const QJsonValue &opt : optionsArray) {
                    q.options.append(opt.toString());
                }
                QJsonArray outer = obj["correct_answers"].toArray();
                if (!outer.isEmpty()) {
                    QJsonValue inner = outer.at(0);
                    if (inner.isArray()) {
                        QJsonArray innerArray = inner.toArray();
                        if (!innerArray.isEmpty())
                            q.correctAnswerText = innerArray.at(0).toString();
                    } else {
                        q.correctAnswerText = inner.toString();
                    }
                }

                questions.append(q);
            }
            emit examQuestionsReceived(questions);
        }
        else if (firstObj.contains("exam_id")) {
            emit statisticsReceived(arr);
        }
    }
    else if (doc.isObject()) {
        QJsonObject obj = doc.object();
        if (obj.contains("full_name") && obj.contains("birth_date") && obj.contains("email")) {
            emit profileReceived(obj);
        }
        else if (obj.contains("score")) {
            emit examResultReceived(obj);
        }
        else
            qDebug() << "Получен JSON-объект:" << obj;
    }
    else {
        qDebug() << "Неизвестный формат ответа:" << data;
    }
}

void Client::saveExamResults(int examId, int score, const QVector<ExamQuestion> &questions, const QVector<QString> &userAnswers)
{
    QJsonObject obj;
    obj["examId"] = examId;
    obj["score"] = score;

    QJsonArray arr;
    for (const QString &answer : userAnswers) {
        arr.append(answer);
    }
    obj["answers"] = arr;

    QJsonDocument doc(obj);
    QString command = "SAVE_RESULTS " + QString(doc.toJson(QJsonDocument::Compact));
    socket->write(command.toUtf8());
    socket->flush();
}

void Client::requestProfile()
{
    QString request = "GET_PROFILE";
    socket->write(request.toUtf8());
    socket->flush();
}

void Client::updateProfile(const QJsonObject &profile)
{
    QJsonDocument doc(profile);
    QString command = "UPDATE_PROFILE " + QString(doc.toJson(QJsonDocument::Compact));
    socket->write(command.toUtf8());
    socket->flush();
}

void Client::changePassword(const QString &oldPassword, const QString &newPassword)
{
    QJsonObject obj;
    obj["old_password"] = oldPassword;
    obj["new_password"] = newPassword;
    QJsonDocument doc(obj);

    QString command = "CHANGE_PASSWORD " + QString(doc.toJson(QJsonDocument::Compact));
    socket->write(command.toUtf8());
    socket->flush();
}
