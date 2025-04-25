#include "Client.h"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QDebug>

Client* Client::instance = nullptr;

Client* Client::getInstance()
{
    if (!instance) {
        instance = new Client(nullptr); // Родитель можно задать по необходимости
    }
    return instance;
}

Client::Client(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    // Подключаемся к серверу (укажите адрес и порт по необходимости)
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
        // Если объект содержит ключ "id", считаем, что это список экзаменов
        if (firstObj.contains("id")) {
            emit examListReceived(arr);
        }
        // Если объект содержит ключ "text", считаем, что это список вопросов
        else if (firstObj.contains("text")) {
            QVector<ExamQuestion> questions;
            for (const QJsonValue &val : arr) {
                QJsonObject obj = val.toObject();
                ExamQuestion q;
                q.questionText = obj["text"].toString();

                // Парсим варианты ответов
                QJsonArray optionsArray = obj["options"].toArray();
                for (const QJsonValue &opt : optionsArray) {
                    q.options.append(opt.toString());
                }

                // Разбор правильного ответа.
                // Если correct_answers приходит как вложенный массив (например, [["4"]]),
                // то извлекаем первую строку из внутреннего массива.
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
        // Если объект содержит "exam_id", считаем, что это статистика (результаты экзамена)
        else if (firstObj.contains("exam_id")) {
            // Предполагается, что вы объявили сигнал statisticsReceived(const QJsonArray &stats)
            emit statisticsReceived(arr);
        }
    }
    // Если получен JSON-объект, можно обработать его по необходимости
    else if (doc.isObject()) {
        QJsonObject obj = doc.object();
        if (obj.contains("score"))
            emit examResultReceived(obj);
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

    // Можете, если нужно, добавить логику про questions
    // ...

    QJsonDocument doc(obj);
    QString command = "SAVE_RESULTS " + QString(doc.toJson(QJsonDocument::Compact));
    socket->write(command.toUtf8());
    socket->flush();
}
