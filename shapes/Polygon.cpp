#include "Polygon.hpp"

namespace jbrush
{
/* Constructors */
Polygon::Polygon(const QPoint* const pts, uint32_t count, FilledShapeProperties props)
       : FilledShape(pts[0], props), points(new QPoint[count]), pointCount(count)
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
    Shape::draw(qp);
    qp.drawPolygon(points, static_cast<int>(pointCount));
}

/* Polygon Information */
double Polygon::area() const
{
    double area = 0;

    for(uint32_t i = 0; i < pointCount; i++)
    {
        area += points[i].x() * points[(i + 1) % pointCount].y() - points[(i + 1) % pointCount].x() * points[i].y();
    }

    return qFabs(area / 2.0);
}

double Polygon::perimeter() const
{
    double perimeter = 0;

    for(uint32_t i = 0; i < pointCount; i++)
    {
        QPoint resultant = points[i] - points[(i + 1) % pointCount];
        perimeter += qSqrt(qPow(resultant.x(),2) + qPow(resultant.y(),2));
    }

    return perimeter;
}

std::string Polygon::toString() const
{
    std::string dimensions;

    for(uint32_t i = 0; i < pointCount; i++)
    {
        dimensions += std::to_string(points[i].x()) + ", " + std::to_string(points[i].y());
        dimensions += (i != pointCount - 1? ", " : "\r\n");
    }

    return "Shape Id: " + std::to_string(getId()) + "\r\n" +
           "ShapeType: Polygon\r\n" +
           "ShapeDimensions: " + dimensions +
           stringifyProperties() + "\r\n";
}
}
