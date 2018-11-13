#include "mainwindow.hpp"
#include "loginwindow.hpp"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen(QPixmap(":/resources/icon.png"));
    splash->show();
    QTimer::singleShot(1500,splash,SLOT(close()));

    MainWindow w;

    Login l(&w);
    QTimer::singleShot(1500, &l,SLOT(show()));

    return a.exec();
}
