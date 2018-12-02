#pragma once

#include "GeometricShape.hpp"

namespace jbrush 
{
class FilledShape : public GeometricShape
{
protected:
    FilledShape(const QPoint&, FilledShapeProperties);

    FilledShapeProperties props;

    virtual void applyProperties(QPainter&) const;
    virtual std::string stringifyProperties() const;
};
}