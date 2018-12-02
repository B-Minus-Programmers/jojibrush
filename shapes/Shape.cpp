#include "Shape.hpp"

namespace jbrush
{
/* Static Variables */
uint32_t Shape::nextId = 0;

/* Constructors */
Shape::Shape(const QPoint& pos) : position(pos), id(nextId)
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

void Shape::setPosition(const QPoint& point)
{
    position = point;
}

void Shape::draw(QPainter& qp) const
{
    this->applyProperties(qp);
}

/* Shape Information */
uint32_t Shape::getId() const
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
