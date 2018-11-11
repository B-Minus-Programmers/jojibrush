#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "Canvas.hpp"

using jbrush::Canvas;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon(":/resources/icon.png"));
    ui->setupUi(this);

    Canvas *canvas = new Canvas;
    MainWindow::setCentralWidget(canvas);
}

MainWindow::~MainWindow()
{
    delete ui;
}
