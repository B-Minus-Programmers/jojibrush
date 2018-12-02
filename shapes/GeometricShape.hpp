#pragma once

#include "Shape.hpp"
#include "Properties.hpp"

namespace jbrush
{
class GeometricShape : public Shape
{
protected:
    GeometricShape(const QPoint& pos, GeometricShapeProperties props) : Shape(pos), props(props) {}
    GeometricShapeProperties props;

    virtual void applyProperties(QPainter&) const;
    virtual std::string stringifyProperties() const;
};
}
