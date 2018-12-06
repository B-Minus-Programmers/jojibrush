#include "Polyline.hpp"

namespace jbrush
{
/* Constructors */
Polyline::Polyline(const QPoint* const pts, uint32_t count, GeometricShapeProperties props)
        : GeometricShape(pts[0], props), points(new QPoint[count]), pointCount(count)
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

void Polyline::addPoint(const QPoint& point)
{
    pointCount++;

    QPoint* newPoints = new QPoint[pointCount];

    for(uint32_t i = 0; i < pointCount - 1; i++)
    {
        newPoints[i] = points[i];
    }

    delete[] points;
    newPoints[pointCount - 1] = point;
    points = newPoints;
}

void Polyline::setPoint(uint32_t index, const QPoint& pt)
{
    if(index < pointCount)
        points[index] = pt;
}

/* Render */
void Polyline::draw(QPainter& qp) const
{
    Shape::draw(qp);
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
    std::string dimensions;

    for(uint32_t i = 0; i < pointCount; i++)
    {
        dimensions += std::to_string(points[i].x()) + ", " + std::to_string(points[i].y());
        dimensions += (i != pointCount - 1? ", " : "\r\n");
    }

    return "Shape Id: " + std::to_string(getId()) + "\r\n" +
           "ShapeType: Polyline\r\n" +
           "ShapeDimensions: " + dimensions +
           stringifyProperties() + "\r\n";
}
}
