#include "database.h"
#include "databasedestroyer.h"
#include <QSqlError>

Database* Database::p_instance = nullptr;
DatabaseDestroyer Database::destroyer;

Database* Database::getInstance()
{
    if (!p_instance) {
        p_instance = new Database();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}

Database::Database()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("exam_system");
    db.setUserName("postgres");
    db.setPassword("230405");
    db.setPort(5432);

    if (!db.open()) {
        qDebug() << "Error: Could not connect to database.";
    } else {
        qDebug() << "Connected to database.";
    }
}

Database::~Database()
{
    db.close();
}

QString Database::sendQuery(const QString& query)
{
    QSqlQuery sqlQuery;
    if (!sqlQuery.exec(query)) {
        return "Query failed: " + sqlQuery.lastError().text();
    }
    return "Query executed successfully.";
}
