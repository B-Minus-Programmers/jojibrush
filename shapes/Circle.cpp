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
    return M_PI * radius * radius;
}

double Circle::perimeter() const
{
    return 2 * M_PI * radius;
}

std::string Circle::toString() const
{
    return "";
}
}
