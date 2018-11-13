#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "Canvas.hpp"
#include "shapes/Rect.hpp"

using jbrush::Canvas;

#include "Canvas.hpp"
#include "shapes/Rect.hpp"

using jbrush::Canvas;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon(":/resources/icon.png"));
    ui->setupUi(this);

    Canvas *canvas = new Canvas;
    MainWindow::setCentralWidget(canvas);

    QPoint p1(100,100);
    QPoint p2(200,200);
    jbrush::Shape* shape = new jbrush::Rect(p1,p2);

    canvas->addShape(shape);
}

MainWindow::~MainWindow()
{
    delete ui;
}
