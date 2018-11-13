#include "Polygon.hpp"

namespace jbrush
{
/* Constructors */
Polygon::Polygon(const QPoint* const pts, uint32_t count)
       : Shape(pts[0]), points(new QPoint[count]), pointCount(count)
{
    for(uint32_t i = 0; i < pointCount; i++)
        points[i] = pts[i];
}

/* Destructor */
Polygon::~Polygon()
{
    delete[] points;
}

/* Getters */
QPoint Polygon::getPoint(uint32_t index) const
{
    return points[index];
}

uint32_t Polygon::getPointCount() const
{
    return pointCount;
}

/* Setters */
void Polygon::setPoints(const QPoint* const pts, uint32_t count)
{
    delete[] points;
    points = new QPoint[count];
    pointCount = count;

    for(uint32_t i = 0; i < pointCount; i++)
        points[i] = pts[i];
}

void Polygon::setPoint(uint32_t index, const QPoint& pt)
{
    if(index < pointCount)
        points[index] = pt;
}

/* Render */
void Polygon::draw(QPainter& qp) const
{
    qp.drawPolygon(points, static_cast<int>(pointCount));
}

/* Polyline Information */
double Polygon::area() const
{
    return -1;
}

double Polygon::perimeter() const
{
    double perimeter = 0;

    for(uint32_t i = 0; i < pointCount; i++)
    {
        QPoint resultant = points[i] - points[i + 1];
        perimeter += qSqrt(qPow(resultant.x(),2) + qPow(resultant.y(),2));
    }

    return perimeter;
}

std::string Polygon::toString() const
{
    return "";
}
}
