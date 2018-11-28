#include "Ellipse.hpp"

namespace jbrush
{
/* Constructors */
Ellipse::Ellipse(const QPoint& center, int w, int h)
       : Shape(center), width(w), height(h)
{}

Ellipse::Ellipse(int x, int y, int w, int h)
       : Shape(QPoint(x,y)), width(w), height(h)
{}

/* Getters */
int Ellipse::getWidth() const
{
    return width;
}

int Ellipse::getHeight() const
{
    return height;
}

/* Setters */
void Ellipse::setWidth(int w)
{
    width = w;
}

void Ellipse::setHeight(int h)
{
    height = h;
}

/* Render */
void Ellipse::draw(QPainter& qp) const
{
    qp.drawEllipse(position, width, height);
}

/* Ellipse Information */
double Ellipse::area() const
{
    return qFabs(M_PI * width * height / 4);
}

double Ellipse::perimeter() const
{
    double a = qFabs(width / 2);
    double b = qFabs(height / 2);

    return M_PI * (3 * (a + b) - qSqrt((3 * a + b) * (a + 3 * b)));
}

std::string Ellipse::toString() const
{
    return "Shape Id: " + std::to_string(getId()) + "\n" +
           "ShapeType: Ellipse\n" +
           "ShapeDimensions: " +
           std::to_string(position.x()) + ", " +
           std::to_string(position.y()) + ", " +
           std::to_string(width / 2)    + ", " +
           std::to_string(height / 2)   + "\n" +
           "PenColor: \n" +
           "PenWidth: \n" +
           "PenStyle: \n" +
           "PenCapStyle: \n" +
           "PenJoinStyle: \n" +
           "BrushColor: \n" +
           "BrushStyle: \n";
}
}
