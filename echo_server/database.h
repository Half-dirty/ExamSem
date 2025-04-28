#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class DatabaseDestroyer;

class Database
{
public:
    static Database* getInstance();
    QString sendQuery(const QString& query);

private:
    Database();
    ~Database();

    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    QSqlDatabase db;

    static Database* p_instance;
    static DatabaseDestroyer destroyer;

    friend class DatabaseDestroyer;
};

#endif // DATABASE_H
