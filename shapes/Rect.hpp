#pragma once
#include "Shape.hpp"

namespace jbrush
{
class Rect final : public Shape
{
public:
    /* Constructors */
    Rect(const QPoint& topL, const QPoint& bottomR);
    Rect(const QPoint& topL, int width, int height);
    Rect(int x, int y, int width, int height);

    /* Getters */
    int getWidth()  const;
    int getHeight() const;

    /* Setters */
    void setWidth(int);
    void setHeight(int);

    /* Render */
    virtual void draw(QPainter&) const override;

    /* Rect Information */
    virtual double area() const override;
    virtual double perimeter() const override;
    virtual std::string toString() const override;

private:
    int width;
    int height;
};
}
