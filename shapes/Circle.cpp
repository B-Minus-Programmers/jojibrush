#include "Circle.hpp"

namespace jbrush
{
/* Constructors */
Circle::Circle(const QPoint& center, int r)
      : Shape(center), radius(r)
{}

Circle::Circle(int x, int y, int r)
      : Shape(QPoint(x,y)), radius(r)
{}

/* Getters */
int Circle::getRadius() const
{
    return radius;
}

/* Setters */
void Circle::setRadius(int r)
{
    radius = r;
}

/* Render */
void Circle::draw(QPainter& qp) const
{
    qp.drawEllipse(position, radius, radius);
}

/* Circle Information */
double Circle::area() const
{
    return qFabs(M_PI * radius * radius);
}

double Circle::perimeter() const
{
    return qFabs(2 * M_PI * radius);
}

std::string Circle::toString() const
{
    return "Shape Id: " + std::to_string(getId()) + "\r\n" +
           "ShapeType: Circle\r\n" +
           "ShapeDimensions: " +
           std::to_string(position.x()) + ", " +
           std::to_string(position.y()) + ", " +
           std::to_string(radius)       + "\r\n" +
           "PenColor: \r\n" +
           "PenWidth: \r\n" +
           "PenStyle: \r\n" +
           "PenCapStyle: \r\n" +
           "PenJoinStyle: \r\n" +
           "BrushColor: \r\n" +
           "BrushStyle: \r\n";
}
}
