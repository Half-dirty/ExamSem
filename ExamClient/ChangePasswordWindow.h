#ifndef CHANGEPASSWORDWINDOW_H
#define CHANGEPASSWORDWINDOW_H

#include <QWidget>

class Client;

namespace Ui {
class ChangePasswordWindow;
}

class ChangePasswordWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePasswordWindow(QWidget *parent = nullptr);
    ~ChangePasswordWindow();

    void setClient(Client *client);

signals:
    void backRequested();

private slots:
    void on_applyPasswordButton_clicked();
    void on_backButton_clicked();

private:
    Ui::ChangePasswordWindow *ui;
    Client *m_client;
};

#endif
