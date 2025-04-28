#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QWidget>
#include <QJsonObject>

class Client;

namespace Ui {
class ProfileWindow;
}

class ProfileWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileWindow(QWidget *parent = nullptr);
    ~ProfileWindow();

    void setClient(Client *client);
    void loadProfile(const QJsonObject &profile);

signals:
    void backRequested();
    void changePasswordRequested();

private slots:
    void on_saveButton_clicked();
    void on_backButton_clicked();
    void on_changePasswordButton_clicked();

private:
    Ui::ProfileWindow *ui;
    Client *m_client;
};

#endif
