#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "shapes/Rect.hpp"

using jbrush::Canvas;

#include "Canvas.hpp"
#include "shapes/Rect.hpp"

using jbrush::Canvas;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), canvas(new jbrush::Canvas)
{
    setWindowIcon(QIcon(":/resources/icon.png"));
    ui->setupUi(this);

    setCentralWidget(canvas);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete canvas;
}

void MainWindow::on_actionLoad_triggered()
{
    QString fileDir;    // Directory of the file to load

    // Bring up a panel for the user to select a directory
    fileDir = QFileDialog::getOpenFileName(this, "Open", currentFile, "Jojibrush files (*" + jbrush::jconstants::FILE_EXTENSION + ")");

    // If loading to the canvas is successful, update the current file
    if(canvas->loadFromFile(fileDir))
    {
        currentFile = fileDir;
    }
}
