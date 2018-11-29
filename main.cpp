#include "mainwindow.hpp"
#include "loginwindow.hpp"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

/**
 * \mainpage Jojibrush Documentation
 * 
 * \section jojibrush Jojibrush
 * 
 * By the B-Minus Programmers
 * 
 * Jojibrush is a high-performance 2D rendering library and paint program. Developed in Qt, Jojibrush can
 * be used to draw a number of different geometric, linear, and text shapes to a Canvas.
 * 
 * Features:
 *  - Create circles, ellipses, rectangles, lines, and text boxes (and more) on a canvas
 *  - Save and load documents to disk
 *  - High-security access control, including administrators, users, and guest users
 *  - Multiple shape properties including color, width, and font
 */

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
