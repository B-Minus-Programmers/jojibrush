#include "loginwindow.hpp"
#include "ui_loginwindow.h"

Login::Login(QWidget* windowToOpen) : QDialog(nullptr), ui(new Ui::Login), widg(windowToOpen)
{
    ui->setupUi(this);
    setWindowTitle("Jojibrush");
    setFixedSize(size());
    setWindowIcon(QIcon(":/resources/images/jojibrushicon.png"));
    QPixmap pix(":/resources/images/jojibrushdarkicon.png");
    ui->label_logo->setPixmap(pix.scaled(150,150,Qt::KeepAspectRatio));
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_2_password->text();

    if(username == "jojibrush" && password == "jojibrush")
    {
        QPixmap pix(":/resources/images/jojibrushicon.png");
        ui->label_logo->setPixmap(pix.scaled(150,150,Qt::KeepAspectRatio));
        QTimer::singleShot(500,widg,SLOT(show()));
        QTimer::singleShot(500,this,SLOT(close()));
    }
    else
    {
        QMessageBox::warning(this, "Login", "username and password is not correct");
    }
}
