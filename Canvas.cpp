#include "Canvas.hpp"
#include "utils/exceptions.hpp"
#include <QPainter>
#include <QDebug>

using jbrush::Canvas;

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

Canvas::~Canvas()
{
    // Free all shapes when deleted. Vector class will delete dynamic array
    clearShapes();
}

Vector<Shape*> Canvas::getShapes()
{
    return shapes;
}

bool Canvas::loadFromFile(QString &fileDir)
{
    FileHandler fileUtil;
    Vector<Shape*> shapesLoaded;    // Shapes loaded by the file utility

    // Load the shapes
    shapesLoaded = fileUtil.loadShapesFromFile(fileDir);

    // If shapes were actually loaded from the file, update current shapes
    if(shapesLoaded.getSize() > 0)
    {
        clearShapes();
        shapes = shapesLoaded;
        repaint();

        // Return true - load successful
        return true;
    }
    else
    {
        // Otherwise, if load size is less than or equal to zero, return false - load failed
        return false;
    }
}

void Canvas::addShape(Shape *shape) 
{
    shapes.push_back(shape);
}

void Canvas::removeShape(uint32_t id) 
{
    for (uint32_t i = 0; i < shapes.getSize(); i++) 
    {
        if (shapes[i]->getId() == id)
        {
            shapes.erase(i);
            return;
        }
    }
}

void Canvas::clearShapes()
{   
    // Deallocate space for the shape pointers
    for (auto shapePtr : shapes)
    {
        delete shapePtr;
    }

    // Clear out the shape vector
    shapes.clear();
}

jbrush::AccountType Canvas::getAccountType() const
{
    return accType;
}

void Canvas::setAccountType(jbrush::AccountType type)
{
    accType = type;
}

void Canvas::paintEvent(QPaintEvent*)
{
    QPainter painter;
    painter.begin(this);
    for (auto shape : shapes)
    {
        shape->draw(painter);

        // reset the pen, setting text color to black
        painter.setPen(QPen());
        painter.drawText(shape->getPosition(), "#" + QString::number(shape->getId()));
    }
    painter.end();
}
