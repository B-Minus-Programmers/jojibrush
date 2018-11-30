#include "Rect.hpp"

namespace jbrush
{
/* Constructors */
Rect::Rect(const QPoint& topL, const QPoint& bottomR)
    : Shape(topL)
{
    width  = bottomR.x() - topL.x();
    height = bottomR.y() - topL.y();
}

Rect::Rect(const QPoint& topL, int w, int h)
    : Shape(topL), width(w), height(h)
{}

Rect::Rect(int x, int y, int w, int h)
    : Shape(QPoint(x,y)), width(w), height(h)
{}

/* Getters */
int Rect::getWidth() const
{
    return width;
}

int Rect::getHeight() const
{
    return height;
}

/* Setters */
void Rect::setWidth(int w)
{
    width = w;
}

void Rect::setHeight(int h)
{
    height = h;
}

/* Render */
void Rect::draw(QPainter& qp) const
{
    qp.drawRect(position.x(), position.y(), width, height);
}

/* Rect information */
double Rect::area() const
{
    return qFabs(width * height);
}

double Rect::perimeter() const
{
    return qFabs((width + height) * 2);
}

std::string Rect::toString() const
{
    return "Shape Id: " + std::to_string(getId()) + "\r\n" +
           "ShapeType: Rectangle\r\n" +
           "ShapeDimensions: " +
           std::to_string(position.x()) + ", " +
           std::to_string(position.y()) + ", " +
           std::to_string(width)        + ", " +
           std::to_string(height)       + "\r\n" +
           "PenColor: \r\n" +
           "PenWidth: \r\n" +
           "PenStyle: \r\n" +
           "PenCapStyle: \r\n" +
           "PenJoinStyle: \r\n" +
           "BrushColor: \r\n" +
           "BrushStyle: \r\n";
}
}
