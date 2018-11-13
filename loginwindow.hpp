#pragma once
#include <QDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QTimer>

namespace Ui{
    class Login;
}

class Login : public QDialog
{
    Q_OBJECT

    public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login* ui;
    QWidget* widg;
};
