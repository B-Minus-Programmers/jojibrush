#pragma once
#include "Shape.hpp"

namespace jbrush
{
class Ellipse final : public Shape
{
public:
    /* Constructors */
    Ellipse(const QPoint& center, int width, int height);
    Ellipse(int x, int y, int width, int height);

    /* Getters */
    int getWidth()  const;
    int getHeight() const;

    /* Setters */
    void setWidth(int);
    void setHeight(int);

    /* Render */
    virtual void draw(QPainter&) const override;

    /* Ellipse Information */
    virtual double area() const override;
    virtual double perimeter() const override;
    virtual std::string toString() const override;

private:
    int width;
    int height;
};
}
