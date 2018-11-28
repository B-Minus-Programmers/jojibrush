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
    std::string dimensions;

    for(uint32_t i = 0; i < pointCount; i++)
    {
        dimensions += std::to_string(points[i].x()) + ", " + std::to_string(points[i].y());
        dimensions += (i != pointCount - 1? ", " : "\n");
    }

    return "Shape Id: " + std::to_string(getId()) + "\n" +
           "ShapeType: Polyline\n" +
           "ShapeDimensions: " + dimensions +
           "PenColor: \n" +
           "PenWidth: \n" +
           "PenStyle: \n" +
           "PenCapStyle: \n" +
           "PenJoinStyle: \n";
}
}
