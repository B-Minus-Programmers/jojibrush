#include "Line.hpp"

namespace jbrush
{
/* Constructors */
Line::Line(const QPoint& s, const QPoint& e)
    : Shape(s), end(e)
{}

Line::Line(int x1, int y1, int x2, int y2)
    : Shape(QPoint(x1,y1)), end(QPoint(x2,y2))
{}

/* Getters */
QPoint Line::getStart() const
{
    return position;
}

QPoint Line::getEnd() const
{
    return end;
}

/* Setters */
void Line::setStart(const QPoint& s)
{
    position = s;
}

void Line::setEnd(const QPoint& e)
{
    end = e;
}

/* Render */
void Line::draw(QPainter& qp) const
{
    qp.drawLine(position, end);
}

/* Line Information */
double Line::area() const
{
    return -1;
}

double Line::perimeter() const
{
    return -1;
}

std::string Line::toString() const
{
    return "";
}
}
