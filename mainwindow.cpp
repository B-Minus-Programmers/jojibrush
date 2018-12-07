#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "Canvas.hpp"
#include "shapes/Shapes.hpp"
#include "shapes/Rectangle.hpp"
#include "utils/FileHandler.hpp"

using jbrush::Canvas;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow),
    canvas(new jbrush::Canvas), shapeSelectMenu(new ShapeSelectMenu),
    shapePropertiesMenu(new AllPropertiesMenu), textPropertiesMenu(new TextPropertiesMenu)
{
    // Setup the main menu's ui
    ui->setupUi(this);

    // Put the shape menus in the placeholder on the form
    canvas->setParent(ui->canvasWidget);
    shapeSelectMenu->setParent(ui->shapeSelectMenuWidget);
    shapePropertiesMenu->setParent(ui->shapePropertiesMenuWidget);
    textPropertiesMenu->setParent(ui->shapePropertiesMenuWidget);

    // Calculate the dimensions of the canvas to fill in the remainder of the space not taken up by the menu widgets
    canvas->setFixedHeight(height());
    canvas->setFixedWidth(width() - ui->shapeSelectMenuWidget->width() - ui->shapePropertiesMenuWidget->width());

    // Set selected properties with the initial values on the menus
    canvas->setSelectedShapeType(shapeSelectMenu->getShapeTypeSelected());
    canvas->setSelectedFilledProperties(shapePropertiesMenu->getGeometricPropertiesMenu()->getProperties(),
                                        shapePropertiesMenu->getFilledPropertiesMenu()->getBrushColor(),
                                        shapePropertiesMenu->getFilledPropertiesMenu()->getBrushStyle());
    canvas->setSelectedTextProperties(textPropertiesMenu->getProperties());

    // Update the properties menus
    updatePropertiesMenus();

    // Connect signals and slots across widgets that are unaware of each other
    connectSignalsAndSlots();
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

void MainWindow::on_actionSave_triggered()
{
    jbrush::FileHandler fileUtil;

    // If there is a current file,save to it
    if(!currentFile.isEmpty())
    {
        fileUtil.saveShapesToFile(canvas->getShapes(), currentFile);
    }
    // Otherwise, ask the user to select one, then set it to that file
    else
    {
        // Get the name of the file the user wants to save
        QString fileDir = QFileDialog::getSaveFileName(this, "Save File", currentFile, jbrush::jconstants::FILE_TYPE);

        // If a file was selected, save to that file
        if(!fileDir.isEmpty())
        {
            fileUtil.saveShapesToFile(canvas->getShapes(), fileDir);
            currentFile = fileDir;
        }
    }
}

void MainWindow::on_actionSaveAs_triggered()
{
    // Get the name of the file the user wants to save
    QString fileDir = QFileDialog::getSaveFileName(this, "Save File", currentFile, jbrush::jconstants::FILE_TYPE);

    // If a file directory was specified, save to it and update the current file
    if(!fileDir.isEmpty())
    {
        jbrush::FileHandler fileUtil;
        fileUtil.saveShapesToFile(canvas->getShapes(), fileDir);

        // If the current file hasn't been set yet, set it to the file specified by the user
        if(currentFile.isEmpty())
        {
            currentFile = fileDir;
        }
    }
}

void MainWindow::on_actionLoad_triggered()
{
    // Use a file dialog to get a file to load from
    QString fileDir = QFileDialog::getOpenFileName(this, "Open", currentFile, jbrush::jconstants::FILE_TYPE);

    // If loading to the canvas is successful, update the current file
    if(!fileDir.isEmpty())
    {
        if(canvas->loadFromFile(fileDir))
        {
            currentFile = fileDir;
        }
    }
}

void MainWindow::connectSignalsAndSlots()
{
    // Connect signals and slots such that the properties menus update whenever any shape type is selected
    connect(shapeSelectMenu, &ShapeSelectMenu::onSelection, this, &MainWindow::updatePropertiesMenus);

    // Update selected properties on the canvas whenever a selection is made in the menus
    connect(shapeSelectMenu, &ShapeSelectMenu::onSelection, canvas, &Canvas::updateShapeType);
    connect(shapePropertiesMenu->getGeometricPropertiesMenu(), &GeometricPropertiesMenu::onItemChanged,
            canvas, &Canvas::updateGeometricProperties);
    connect(shapePropertiesMenu->getFilledPropertiesMenu(), &FilledPropertiesMenu::onItemChanged,
            canvas, &Canvas::updateFilledProperties);
    connect(textPropertiesMenu, &TextPropertiesMenu::onItemChanged,
            canvas, &Canvas::updateTextProperties);
}

void MainWindow::updatePropertiesMenus()
{
    // If text is selected, show text properties and hide shape properties
    if(shapeSelectMenu->getShapeTypeSelected() == jbrush::SelectableShapeType::TEXT)
    {
        textPropertiesMenu->show();
        shapePropertiesMenu->hide();
    }
    // Otherwise, do exactly the opposite
    else
    {
        textPropertiesMenu->hide();
        shapePropertiesMenu->show();

        // Display fill properties when the shape type selected isn't a line
        shapePropertiesMenu->displayFilledPropertiesMenu
                (shapeSelectMenu->getShapeTypeSelected() != jbrush::SelectableShapeType::LINE &&
                shapeSelectMenu->getShapeTypeSelected() != jbrush::SelectableShapeType::POLYLINE);
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

void MainWindow::on_actionShow_Shape_IDs_toggled(bool checked)
{
    canvas->setDrawShapeIds(checked);
}
void MainWindow::on_actionAbout_Us_triggered()
{
    about.setModal(true);
    about.exec();
}
