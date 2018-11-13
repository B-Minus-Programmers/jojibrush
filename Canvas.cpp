#include "Canvas.hpp"
#include <QPainter>

using jbrush::Canvas;

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

Canvas::~Canvas()
{
    // Free all shapes when deleted. Vector class will delete dynamic array
    for (auto shapePtr : this->shapes)
    {
        delete shapePtr;
    }
}

Vector<Shape*> Canvas::getShapes()
{
    return this->shapes;
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

void Canvas::paintEvent(QPaintEvent*)
{
    QPainter painter;
    painter.begin(this);
    for (auto shape : shapes)
    {
        shape->draw(painter);
    }
    painter.end();
}
