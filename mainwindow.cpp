#include <QFileDialog>
#include <QMessageBox>
#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "shapes/Shapes.hpp"

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

void MainWindow::setAccountType(jbrush::AccountType type)
{
    canvas->setAccountType(type);
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
void MainWindow::on_actionShape_Id_s_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,"Save File / ID report",nullptr,"Text File(*.txt)");

    if(!filename.isEmpty())
    {
        QFile file(filename);
        QTextStream qOut(&file);
        file.open(QIODevice::ReadWrite);
        Vector<Shape*> shapes = canvas->getShapes();
        jbrush::sort(shapes,jbrush::compareId);
        Vector<Shape*>::iterator itor = shapes.begin();

        while(itor != shapes.end())
        {
            qOut << (*itor) ->toQString() << "\r\n\r\n";
            ++itor;
        }
        file.close();
    }
}

void MainWindow::on_actionShape_Area_s_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,"Save File / Area Report",nullptr,"Text File(*.txt)");
    if(!filename.isEmpty())
    {
        QFile file(filename);
        QTextStream qOut(&file);
        file.open(QIODevice::ReadWrite);
        Vector<Shape*> shapes = canvas->getShapes();
        jbrush::sort(shapes,jbrush::compareArea);
        Vector<Shape*>::iterator itor = shapes.begin();

        while(itor != shapes.end())
        {
            if((*itor)->area() != -1)
            {
                qOut << "Shape Area: " <<(*itor) ->area() << "\r\n";
                qOut << (*itor)->toQString();
                qOut << "\r\n";
            }
            ++itor;
        }
        file.close();
    }
}

void MainWindow::on_actionShape_Perimeters_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,"Save File / Perimeter Report",nullptr,"Text File(*.txt)");
    if(!filename.isEmpty())
    {
        QFile file(filename);
        QTextStream qOut(&file);
        file.open(QIODevice::ReadWrite);
        Vector<Shape*> shapes = canvas->getShapes();
        jbrush::sort(shapes,jbrush::comparePerimeter);
        Vector<Shape*>::iterator itor = shapes.begin();

        while(itor != shapes.end())
        {
            if((*itor)->perimeter() != -1)
            {
                qOut <<"Shape Perimeter: " <<(*itor) ->perimeter() << "\r\n";
                qOut << (*itor)->toQString();
                qOut << "\r\n";
            }
            ++itor;
        }
        file.close();
    }
}

void MainWindow::on_actionExport_triggered()
{
    QString imgDir;
    QPixmap pixmap = canvas->grab(canvas->rect());
    imgDir = QFileDialog::getSaveFileName(this,"Save Image",nullptr,"Bitmap files (*.bmp);;JPG files (*.jpg);;PNG files (*.png)");
    pixmap.save(imgDir);
}


