#include "mytcpserver.h"
#include "functions.h"
#include <QSqlError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    // Слушаем на порту 33333
    mTcpServer->listen(QHostAddress::Any, 33333);

    // Подключаемся к базе данных
    connectToDatabase();
}

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
}

bool MyTcpServer::connectToDatabase()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("exam_system");
    db.setUserName("postgres");
    db.setPassword("230405");
    db.setPort(5432);

    return db.open();
}

void MyTcpServer::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();
    connect(mTcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
}

void MyTcpServer::slotClientDisconnected()
{
    mTcpSocket->close();
}

void MyTcpServer::slotServerRead()
{
    QByteArray data = mTcpSocket->readAll();
    QString input = QString(data).trimmed();

    // Создаем объект Functions для обработки запроса
    Functions functions(mTcpSocket, currentUserId);

    // Обрабатываем команды от клиента:
    // 1. LOGIN username password
    // 2. REGISTER username password
    // 3. GET_EXAMS
    // 4. GET_QUESTIONS examId
    // 5. SAVE_RESULTS JSON_string
    // 6. GET_STATISTICS

    if (input.startsWith("LOGIN")) {
        QStringList parts = input.split(" ");
        if (parts.size() == 3) {
            QString username = parts[1];
            QString password = parts[2];
            functions.loginUser(username, password);
        } else {
            mTcpSocket->write("ERROR\r\n");
        }
    }
    else if (input.startsWith("REGISTER")) {
        QStringList parts = input.split(" ");
        if (parts.size() == 3) {
            QString username = parts[1];
            QString password = parts[2];
            functions.registerUser(username, password);
        } else {
            mTcpSocket->write("ERROR\r\n");
        }
    }
    else if (input.startsWith("GET_EXAMS")) {
        QJsonArray exams = functions.getExamListJSON();
        QJsonDocument doc(exams);
        mTcpSocket->write(doc.toJson(QJsonDocument::Compact));
    }
    else if (input.startsWith("GET_QUESTIONS")) {
        QStringList parts = input.split(" ");
        if (parts.size() == 2) {
            bool ok;
            int examId = parts[1].toInt(&ok);
            if (ok) {
                QJsonArray questions = functions.getExamQuestionsJSON(examId);
                QJsonDocument doc(questions);
                mTcpSocket->write(doc.toJson(QJsonDocument::Compact));
            } else {
                mTcpSocket->write("ERROR\r\n");
            }
        } else {
            mTcpSocket->write("ERROR\r\n");
        }
    }
    else if (input.startsWith("SAVE_RESULTS")) {
        // Ожидается, что после команды будет пробел и JSON-строка:
        // Пример: SAVE_RESULTS {"examId":3, "score":5, "answers":[1,2,3,0,...]}
        int index = input.indexOf(" ");
        if (index != -1) {
            QString jsonPart = input.mid(index+1).trimmed();
            QJsonParseError error;
            QJsonDocument doc = QJsonDocument::fromJson(jsonPart.toUtf8(), &error);
            if (error.error == QJsonParseError::NoError && doc.isObject()) {
                QJsonObject obj = doc.object();
                int examId = obj["examId"].toInt();
                int score = obj["score"].toInt();
                QJsonArray answers = obj["answers"].toArray();
                functions.saveExamResults(currentUserId, examId, score, answers);
            } else {
                mTcpSocket->write("ERROR\r\n");
            }
        } else {
            mTcpSocket->write("ERROR\r\n");
        }
    }
    else if (input.startsWith("GET_STATISTICS")) {
        functions.showStatistics();
    }
    else {
        mTcpSocket->write("ERROR\r\n");
    }
}
