#include "Rectangle.hpp"

namespace jbrush
{
/* Constructors */
Rectangle::Rectangle(const QPoint& topL, const QPoint& bottomR, FilledShapeProperties props)
    : FilledShape(topL, props)
{
    width  = bottomR.x() - topL.x();
    height = bottomR.y() - topL.y();
}

Rectangle::Rectangle(const QPoint& topL, int w, int h, FilledShapeProperties props)
    : FilledShape(topL, props), width(w), height(h)
{}

Rectangle::Rectangle(int x, int y, int w, int h, FilledShapeProperties props)
    : FilledShape(QPoint(x,y), props), width(w), height(h)
{}

/* Getters */
int Rectangle::getWidth() const
{
    return width;
}

int Rectangle::getHeight() const
{
    return height;
}

/* Setters */
void Rectangle::setWidth(int w)
{
    width = w;
}

void Rectangle::setHeight(int h)
{
    height = h;
}

/* Render */
void Rectangle::draw(QPainter& qp) const
{
    Shape::draw(qp);
    qp.drawRect(position.x(), position.y(), width, height);
}

/* Rect information */
double Rectangle::area() const
{
    return qFabs(width * height);
}

double Rectangle::perimeter() const
{
    return qFabs(width + height) * 2;
}

std::string Rectangle::toString() const
{
    return "Shape Id: " + std::to_string(getId()) + "\r\n" +
           "ShapeType: Rectangle\r\n" +
           "ShapeDimensions: " +
           std::to_string(position.x()) + ", " +
           std::to_string(position.y()) + ", " +
           std::to_string(width)        + ", " +
           std::to_string(height)       + "\r\n" +
           stringifyProperties() + "\r\n";
}
}
