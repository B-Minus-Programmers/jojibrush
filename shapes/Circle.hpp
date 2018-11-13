#pragma once
#include "Shape.hpp"

namespace jbrush
{
class Circle final : public Shape
{
public:
    /* Constructors */
    Circle(const QPoint& center, int radius);
    Circle(int x, int y, int radius);

    /* Getters */
    int getRadius() const;

    /* Setters */
    void setRadius(int);

    /* Render */
    virtual void draw(QPainter&) const override;

    /* Circle Information */
    virtual double area() const override;
    virtual double perimeter() const override;
    virtual std::string toString() const override;

private:
    int radius;
};
}
