
#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QMap>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();

private slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void slotServerRead();

private:
    QTcpServer *mTcpServer;
    QSqlDatabase db;
    QMap<QTcpSocket*, int> userIds;
    QVector<QTcpSocket*> activeSockets; // Хранение всех клиентов(Вектор с ссылками на сокеты)

    void addClientSocket(QTcpSocket *socket);
    void removeClientSocket(QTcpSocket *socket);
};

#endif
