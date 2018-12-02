#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "Canvas.hpp"
#include "shapes/Shapes.hpp"

using jbrush::Canvas;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), canvas(new jbrush::Canvas)
{
    setWindowIcon(QIcon(":/resources/icon.png"));
    ui->setupUi(this);

    MainWindow::setCentralWidget(canvas);

    QPoint p1(100,100);
    QPoint p2(200,200);
    jbrush::FilledShapeProperties props;
    props.border.penCapStyle = Qt::PenCapStyle::FlatCap;
    props.border.penColor = Qt::GlobalColor::blue;
    props.border.penJoinStyle = Qt::PenJoinStyle::BevelJoin;
    props.border.penStyle = Qt::PenStyle::DashLine;
    props.border.penWidth = 10;
    props.brushColor = Qt::GlobalColor::green;
    props.brushStyle = Qt::BrushStyle::HorPattern;
    jbrush::Shape* shape = new jbrush::Rectangle(p1, p2, props);

    jbrush::Shape* defaultPropsShape = new jbrush::Ellipse(500, 200, 300, 100);

    canvas->addShape(shape);
    canvas->addShape(defaultPropsShape);
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
    if(!fileDir.isEmpty())
    {
        if(canvas->loadFromFile(fileDir))
        {
            currentFile = fileDir;
        }
    }
}
