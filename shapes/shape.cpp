#include "shape.hpp"

namespace jbrush
{
/* Static Variables */
unsigned int Shape::nextId = 0;

/* Constructors */
Shape::Shape(QPoint point) : id(nextId), position(point)
{
    nextId++;
}

/* Destructor */
Shape::~Shape() {}

/* Position */
QPoint Shape::getPosition() const
{
    return position;
}

void Shape::setPosition(QPoint point)
{
    position = point;
}

/* Shape Information */
unsigned int Shape::getId() const
{
    return id;
}

QString Shape::toQString() const
{
    return QString::fromStdString(toString());
}

/* Operators */
bool Shape::operator<(const Shape& as) const
{
    return id < as.id;
}

bool Shape::operator<=(const Shape& as) const
{
    return id <= as.id;
}

bool Shape::operator>(const Shape& as) const
{
    return id > as.id;
}

bool Shape::operator>=(const Shape& as) const
{
    return id >= as.id;
}

bool Shape::operator==(const Shape& as) const
{
    return id == as.id;
}

bool Shape::operator!=(const Shape& as) const
{
    return id != as.id;
}
}
