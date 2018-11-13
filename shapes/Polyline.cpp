#include "Polyline.hpp"

namespace jbrush
{
/* Constructors */
Polyline::Polyline(const QPoint* const pts, uint32_t count)
        : Shape(pts[0]), points(new QPoint[count]), pointCount(count)
{
    for(uint32_t i = 0; i < pointCount; i++)
        points[i] = pts[i];
}

/* Destructor */
Polyline::~Polyline()
{
    delete[] points;
}

/* Getters */
QPoint Polyline::getPoint(uint32_t index) const
{
    return points[index];
}

uint32_t Polyline::getPointCount() const
{
    return pointCount;
}

/* Setters */
void Polyline::setPoints(const QPoint* const pts, uint32_t count)
{
    delete[] points;
    points = new QPoint[count];
    pointCount = count;

    for(uint32_t i = 0; i < pointCount; i++)
        points[i] = pts[i];
}

void Polyline::setPoint(uint32_t index, const QPoint& pt)
{
    if(index < pointCount)
        points[index] = pt;
}

/* Render */
void Polyline::draw(QPainter& qp) const
{
    qp.drawPolyline(points, static_cast<int>(pointCount));
}

/* Polyline Information */
double Polyline::area() const
{
    return -1;
}

double Polyline::perimeter() const
{
    return -1;
}

std::string Polyline::toString() const
{
    return "";
}
}
