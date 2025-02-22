#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include<QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QSqlError>

MyTcpServer::~MyTcpServer()
{

    mTcpServer->close();
    //server_status=0;
    db.close();
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection, this, &MyTcpServer::slotNewConnection);

    if (!mTcpServer->listen(QHostAddress::Any, 33333)) {
        qDebug() << "Server is not started";
    } else {
        qDebug() << "Server is started";
    }

    if (!connectToDatabase()) {
        qDebug() << "Failed to connect to database.";
    }
}

void MyTcpServer::slotNewConnection(){
    mTcpSocket = mTcpServer->nextPendingConnection();
    connect(mTcpSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);

    currentUserId = -1; // Сброс ID пользователя
    sendLoginMenu(); // Отправляем меню входа/регистрации
}



void MyTcpServer::slotServerRead()
{
    QByteArray data = mTcpSocket->readAll();
    QString input = QString(data).trimmed();

    if (currentUserId == -1) {
        // Пользователь не авторизован
        if (input == "1") {
            mTcpSocket->write("Enter username: ");
            mTcpSocket->waitForReadyRead();
            QString username = QString(mTcpSocket->readAll()).trimmed();
            mTcpSocket->write("Enter password: ");
            mTcpSocket->waitForReadyRead();
            QString password = QString(mTcpSocket->readAll()).trimmed();
            registerUser(username, password);
        } else if (input == "2") {
            mTcpSocket->write("Enter username: ");
            mTcpSocket->waitForReadyRead();
            QString username = QString(mTcpSocket->readAll()).trimmed();
            mTcpSocket->write("Enter password: ");
            mTcpSocket->waitForReadyRead();
            QString password = QString(mTcpSocket->readAll()).trimmed();
            loginUser(username, password);
        } else {
            mTcpSocket->write("Invalid choice. Please try again.\r\n");
            sendLoginMenu();
        }
    } else {
        // Пользователь авторизован
        if (input == "1") {
            startExam();
        } else if (input == "2") {
            showStatistics();
        } else if (input == "3") {
            mTcpSocket->write("Goodbye!\r\n");
            mTcpSocket->disconnectFromHost();
        } else {
            mTcpSocket->write("Invalid choice. Please try again.\r\n");
            sendMainMenu();
        }
    }
}

void MyTcpServer::slotClientDisconnected(){
    mTcpSocket->close();
}

bool MyTcpServer::connectToDatabase() {
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("exam_system");
    db.setUserName("postgres");
    db.setPassword("0Oijhbgvfcrd4e.");
    db.setPort(5432);

    if (!db.open()) {
        qDebug() << "Error: Could not connect to database.";
        return false;
    }
    qDebug() << "Connected to database.";
    return true;
}

void MyTcpServer::sendMainMenu()
{
    QString menu = R"(
        Main Menu:
        1. Start Exam
        2. View Statistics
        3. Exit
        Please enter your choice:
    )";
    mTcpSocket->write(menu.toUtf8());
}

void MyTcpServer::sendLoginMenu()
{
    QString menu = R"(
    Welcome to the Exam System!
1. Register
2. Login
Please enter your choice:
    )";
    mTcpSocket->write(menu.toUtf8());
}

void MyTcpServer::registerUser(const QString &username, const QString &password)
{
    QString passwordHash = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password_hash) VALUES (:username, :password_hash)");
    query.bindValue(":username", username);
    query.bindValue(":password_hash", passwordHash);

    if (query.exec()) {
        mTcpSocket->write("Registration successful. Please login.\r\n");
        sendLoginMenu();
    } else {
        mTcpSocket->write("Error: Registration failed. Username may already exist.\r\n");
        sendLoginMenu();
    }
}

void MyTcpServer::loginUser(const QString &username, const QString &password)
{
    QString passwordHash = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());

    QSqlQuery query;
    query.prepare("SELECT id FROM users WHERE username = :username AND password_hash = :password_hash");
    query.bindValue(":username", username);
    query.bindValue(":password_hash", passwordHash);

    if (query.exec() && query.next()) {
        currentUserId = query.value("id").toInt();
        mTcpSocket->write("Login successful.\r\n");
        sendMainMenu();
    } else {
        mTcpSocket->write("Error: Invalid username or password.\r\n");
        sendLoginMenu();
    }
}

void MyTcpServer::startExam()
{
    mTcpSocket->write("Starting exam...\r\n");

    // Получаем вопросы из базы данных
    QJsonArray questions = getExamQuestions(1); // Пример: экзамен с ID = 1

    int score = 0;
    QJsonArray answers;
    for (const QJsonValue &question : questions) {
        QJsonObject qObj = question.toObject();
        QString questionText = qObj["text"].toString();
        QJsonArray options = qObj["options"].toArray(); // Получаем варианты ответов
        QJsonArray correctAnswers = qObj["correct_answers"].toArray();

        // Отправляем вопрос и варианты ответов
        mTcpSocket->write((questionText + "\r\n").toUtf8());
        for (const QJsonValue &option : options) {
            mTcpSocket->write((option.toString() + "\r\n").toUtf8());
        }
        mTcpSocket->write("Your answer: ");

        // Ждем ответа от пользователя
        if (mTcpSocket->waitForReadyRead()) {
            QString userAnswer = QString(mTcpSocket->readAll()).trimmed();
            answers.append(userAnswer);

            // Проверяем правильность ответа
            if (correctAnswers.contains(userAnswer)) {
                score++;
            }
        }
    }

    // Сохраняем результаты
    saveExamResults(currentUserId, 1, score, answers);
    mTcpSocket->write(QString("Exam completed. Your score: %1/%2\r\n").arg(score).arg(questions.size()).toUtf8());
    sendMainMenu(); // Возвращаем пользователя в главное меню
}

void MyTcpServer::showStatistics()
{
    mTcpSocket->write("Fetching statistics...\r\n");

    QSqlQuery query;
    query.prepare("SELECT score, details FROM results WHERE user_id = :user_id");
    query.bindValue(":user_id", currentUserId);

    if (query.exec()) {
        while (query.next()) {
            int score = query.value("score").toInt();
            QString details = query.value("details").toString();
            mTcpSocket->write(QString("Score: %1, Details: %2\r\n").arg(score).arg(details).toUtf8());
        }
    } else {
        mTcpSocket->write("Error fetching statistics.\r\n");
    }

    sendMainMenu();
}

QJsonArray MyTcpServer::getExamQuestions(int examId)
{
    QSqlQuery query;
    query.prepare("SELECT question_text, correct_answers, options FROM questions WHERE exam_id = :exam_id");
    query.bindValue(":exam_id", examId);

    QJsonArray questions;
    if (query.exec()) {
        while (query.next()) {
            QJsonObject question;
            question["text"] = query.value("question_text").toString();
            question["correct_answers"] = QJsonDocument::fromJson(query.value("correct_answers").toString().toUtf8()).array();
            question["options"] = QJsonDocument::fromJson(query.value("options").toString().toUtf8()).array();
            questions.append(question);
        }
    } else {
        qDebug() << "Error fetching questions:" << query.lastError().text();
    }

    return questions;
}

void MyTcpServer::saveExamResults(int userId, int examId, int score, const QJsonArray &answers)
{
    QSqlQuery query;
    query.prepare("INSERT INTO results (user_id, exam_id, score, details) VALUES (:user_id, :exam_id, :score, :details)");
    query.bindValue(":user_id", userId);
    query.bindValue(":exam_id", examId);
    query.bindValue(":score", score);

    // Формируем JSON с ответами пользователя
    QJsonObject details;
    details["user_answers"] = answers;
    details["correct_answers"] = getCorrectAnswers(examId); // Получаем правильные ответы

    query.bindValue(":details", QJsonDocument(details).toJson());

    if (!query.exec()) {
        qDebug() << "Error saving exam results:" << query.lastError().text();
    }
}

QJsonArray MyTcpServer::getCorrectAnswers(int examId)
{
    QSqlQuery query;
    query.prepare("SELECT correct_answers FROM questions WHERE exam_id = :exam_id");
    query.bindValue(":exam_id", examId);

    QJsonArray correctAnswers;
    if (query.exec()) {
        while (query.next()) {
            QString correctAnswer = query.value("correct_answers").toString();
            correctAnswers.append(QJsonDocument::fromJson(correctAnswer.toUtf8()).array());
        }
    } else {
        qDebug() << "Error fetching correct answers:" << query.lastError().text();
    }

    return correctAnswers;
}
