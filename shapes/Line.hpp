#pragma once
#include "Shape.hpp"

namespace jbrush
{
class Line final : public Shape
{
public:
    /* Constructors */
    Line(const QPoint& start, const QPoint& end);
    Line(int x1, int y1, int x2, int y2);

    /* Getters */
    QPoint getStart() const;
    QPoint getEnd()   const;

    /* Setters */
    void setStart(const QPoint&);
    void setEnd(const QPoint&);


    /* Render */
    virtual void draw(QPainter&) const override;

    /* Line Information */
    virtual double area() const override;
    virtual double perimeter() const override;
    virtual std::string toString() const override;

private:
    QPoint end;
};
}
