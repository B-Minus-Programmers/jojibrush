#include "Circle.hpp"

namespace jbrush
{
/* Constructors */
Circle::Circle(const QPoint& center, int r, FilledShapeProperties props)
      : FilledShape(center, props), radius(r)
{}

Circle::Circle(int x, int y, int r, FilledShapeProperties props)
      : FilledShape(QPoint(x,y), props), radius(r)
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
    Shape::draw(qp);
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
           stringifyProperties() + "\r\n";
}
}
