#include "mainwindow.hpp"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/resources/icon.png"));
    splash->show();

    MainWindow w;

    QTimer::singleShot(1500,splash,SLOT(close()));
    QTimer::singleShot(3000, &w,SLOT(show()));


    w.show();

    return a.exec();
}
