#include "mytcpserver.h"
#include "functions.h"
#include "database.h"
#include <QSqlError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    Database::getInstance();
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);
    mTcpServer->listen(QHostAddress::Any, 33333);
}

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
}

void MyTcpServer::slotNewConnection()
{
    QTcpSocket *socket = mTcpServer->nextPendingConnection();
    connect(socket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(socket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
    addClientSocket(socket); // Добавляем сокет в вектор
}

void MyTcpServer::slotClientDisconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (socket) {
        userIds.remove(socket);
        removeClientSocket(socket); // Удаляем сокет из вектора
        socket->deleteLater();
    }
}

void MyTcpServer::slotServerRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    QByteArray data = socket->readAll();
    QString input = QString(data).trimmed();

    QString command = input.section(' ', 0, 0);
    QString payload = input.section(' ', 1);

    Functions functions(socket, userIds);

    if (command == "LOGIN") {
        QStringList parts = payload.split(" ");
        if (parts.size() == 2) {
            functions.loginUser(parts[0], parts[1]);
        } else {
            socket->write("ERROR\r\n");
        }
    }
    else if (command == "REGISTER") {
        QStringList parts = payload.split(" ");
        if (parts.size() == 2) {
            functions.registerUser(parts[0], parts[1]);
        } else {
            socket->write("ERROR\r\n");
        }
    }
    else if (command == "GET_EXAMS") {
        QJsonArray exams = functions.getExamListJSON();
        QJsonDocument doc(exams);
        socket->write(doc.toJson(QJsonDocument::Compact));
    }
    else if (command == "GET_QUESTIONS") {
        bool ok;
        int examId = payload.toInt(&ok);
        if (ok) {
            QJsonArray questions = functions.getExamQuestionsJSON(examId);
            QJsonDocument doc(questions);
            socket->write(doc.toJson(QJsonDocument::Compact));
        } else {
            socket->write("ERROR\r\n");
        }
    }
    else if (command == "SAVE_RESULTS") {
        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(payload.toUtf8(), &error);
        if (error.error == QJsonParseError::NoError && doc.isObject()) {
            QJsonObject obj = doc.object();
            int examId = obj["examId"].toInt();
            int score = obj["score"].toInt();
            QJsonArray answers = obj["answers"].toArray();
            functions.saveExamResults(userIds[socket], examId, score, answers);
        } else {
            socket->write("ERROR\r\n");
        }
    }
    else if (command == "GET_PROFILE") {
        QSqlQuery query;
        query.prepare("SELECT full_name, birth_date, email FROM users WHERE id = :id");
        query.bindValue(":id", userIds[socket]);
        if (query.exec() && query.next()) {
            QJsonObject profile;
            profile["full_name"] = query.value("full_name").toString();
            profile["birth_date"] = query.value("birth_date").toString();
            profile["email"] = query.value("email").toString();
            QJsonDocument doc(profile);
            socket->write(doc.toJson(QJsonDocument::Compact));
        } else {
            socket->write("ERROR\r\n");
        }
    }
    else if (command == "UPDATE_PROFILE") {
        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(payload.toUtf8(), &error);
        if (error.error == QJsonParseError::NoError && doc.isObject()) {
            QJsonObject obj = doc.object();
            QString fullName = obj["full_name"].toString();
            QString birthDate = obj["birth_date"].toString();
            QString email = obj["email"].toString();

            QSqlQuery query;
            query.prepare("UPDATE users SET full_name = :full_name, birth_date = :birth_date, email = :email WHERE id = :id");
            query.bindValue(":full_name", fullName);
            query.bindValue(":birth_date", birthDate.isEmpty() ? QVariant(QVariant::Date) : birthDate);
            query.bindValue(":email", email);
            query.bindValue(":id", userIds[socket]);

            if (query.exec()) {
                socket->write("OK\r\n");
            } else {
                socket->write("ERROR\r\n");
            }
        } else {
            socket->write("ERROR\r\n");
        }
    }
    else if (command == "CHANGE_PASSWORD") {
        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(payload.toUtf8(), &error);

        if (error.error == QJsonParseError::NoError && doc.isObject()) {
            QJsonObject obj = doc.object();
            QString oldPassword = obj["old_password"].toString();
            QString newPassword = obj["new_password"].toString();
            functions.changeUserPassword(userIds[socket], oldPassword, newPassword);
        } else {
            socket->write("ERROR\r\n");
        }
    }
    else if (command == "GET_STATISTICS") {
        functions.showStatistics();
    }
    else {
        socket->write("ERROR\r\n");
    }
}

void MyTcpServer::addClientSocket(QTcpSocket *socket)
{
    activeSockets.append(socket);
}

void MyTcpServer::removeClientSocket(QTcpSocket *socket)
{
    activeSockets.removeOne(socket);
}
