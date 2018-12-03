#include <QTimer>
#include "loginwindow.hpp"
#include "ui_loginwindow.h"
#include "utils/exceptions.hpp"

/* Constructor */
Login::Login(MainWindow* window)
     : QDialog(nullptr), ui(new Ui::Login), windowAfterLogin(window)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);

    QPixmap pix(":/resources/login/image/dark.png");
    ui->label_logo->setPixmap(pix.scaled(150, 150, Qt::KeepAspectRatio));
}

/* Destructor */
Login::~Login()
{
    delete ui;
}

/* Private slots */
void Login::on_pushButton_registered_clicked()
{
    try
    {
        QString usernameInput = ui->lineEdit_username->text();
        QString passwordInput = ui->lineEdit_password->text();
        jbrush::AccountType type;

        if(authenticate(usernameInput, passwordInput, type))
        {
            authSuccessful(type);
        }
        else
        {
            authFailed();
        }
    }
    catch(jbrush::GeneralException& exception)
    {
        exception.errorWindow();
    }
}

void Login::on_pushButton_guest_clicked()
{
    authSuccessful(jbrush::AccountType::GUEST);
}

bool Login::authenticate(QString usernameInput, QString passwordInput, jbrush::AccountType& type) const
{
    QFile authFile(":/resources/login/auth.txt");
    QTextStream qin(&authFile);

    if(!authFile.open(QIODevice::ReadOnly))
    {
        throw jbrush::BadFile("Authentication failed, contact admin!");
    }

    QString usernameFile;
    QString passwordFile;
    QString accTypeFile;
    bool authValid = false;

    /* Search for correct username and password */
    while(!authValid && !qin.atEnd())
    {
        usernameFile = qin.readLine();
        passwordFile = qin.readLine();
        accTypeFile  = qin.readLine();
        qin.readLine(); //clears the empty line

        if(usernameFile.isEmpty() || passwordFile.isEmpty() || accTypeFile.isEmpty())
        {
            throw jbrush::BadFileFormat("Authentication failed, contact admin!");
        }
        else if(usernameFile == usernameInput && passwordFile == passwordInput)
        {
            authValid = true;

            if(accTypeFile == "admin")
            {
                type = jbrush::AccountType::ADMIN;
            }
            else if(accTypeFile == "user")
            {
                type = jbrush::AccountType::USER;
            }
            else
            {
                throw jbrush::BadFileFormat("Authentication failed, contact admin!");
            }
        }
    }

    authFile.close();

    return authValid;
}

void Login::authSuccessful(jbrush::AccountType type) const
{
    QPixmap pix;

    if(type == jbrush::AccountType::ADMIN)
    {
        pix.load(":/resources/login/image/nani.png");
    }
    else
    {
        pix.load(":/resources/login/image/normal.png");
    }

    ui->label_logo->setPixmap(pix.scaled(150, 150, Qt::KeepAspectRatio));

    ui->label_errorMsg->setStyleSheet(" QLabel { opacity: 0 } ");
    ui->label_errorMsg->setText("Login successful");

    windowAfterLogin->setAccountType(type);

    QTimer::singleShot(500, windowAfterLogin, SLOT(show()));
    QTimer::singleShot(500, this, SLOT(close()));
}

void Login::authFailed() const
{
    ui->label_errorMsg->setStyleSheet(" QLabel { background-color: red; color: white; }");
    ui->label_errorMsg->setText("Username/Password was incorrect");
}

void Login::on_checkBox_showPW_stateChanged(int)
{
    if(ui->checkBox_showPW->checkState() == Qt::CheckState::Checked)
    {
        ui->lineEdit_password->setEchoMode(QLineEdit::EchoMode::Normal);
    }
    else
    {
        ui->lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password);
    }
}
