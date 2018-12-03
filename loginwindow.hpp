#pragma once
#include "mainwindow.hpp"
#include "AccountType.hpp"

namespace Ui{
    class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    /* Constructor */
    explicit Login(MainWindow*);

    /* Destructor */
    ~Login();

private slots:
    void on_pushButton_registered_clicked();
    void on_pushButton_guest_clicked();
    void on_checkBox_showPW_stateChanged(int arg1);

private:
    bool authenticate(QString username, QString password, jbrush::AccountType&) const;
    void authSuccessful(jbrush::AccountType) const;
    void authFailed() const;

    Ui::Login* ui;
    MainWindow* windowAfterLogin;
};
