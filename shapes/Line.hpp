#pragma once
#include "GeometricShape.hpp"

namespace jbrush
{
class Line final : public GeometricShape
{
public:
    /* Constructors */
    /**
     * Creates a line between two points
     * @param start one endpoint of the line, used as the line's position
     * @param end the other endpoint
     * @param props the shape properties, which adjust shape color and style
     */
    Line(const QPoint& start, const QPoint& end, GeometricShapeProperties props = DEFAULT_GEOMETRIC_PROPS);

    /**
     * Creates a line between two (x,y) coordinate pairs
     * @param x1 x-coordinate of the first point
     * @param y1 y-coordinate of the first point
     * @param x2 x-coordinate of the second point
     * @param y2 y-coordinate of the second point
     * @param props the shape properties, which adjust shape color and style
     */
    Line(int x1, int y1, int x2, int y2, GeometricShapeProperties props = DEFAULT_GEOMETRIC_PROPS);

    /* Getters */

    /**
     * Returns the start endpoint of the line
     * @returns the start endpoint
     */
    QPoint getStart() const;

    /**
     * Returns the end endpoint of the line
     * @returns the end endpoint
     */
    QPoint getEnd() const;

    /* Setters */

    /**
     * Moves the start endpoint to a new position on the canvas
     * @param start the new start endpoint
     */
    void setStart(const QPoint& start);

    /**
     * Moves the end endpoint to a new position on the canvas
     * @param end the new end endpoint
     */
    void setEnd(const QPoint& end);

    /* Render */
    virtual void draw(QPainter&) const override;

    /* Line Information */

    /**
     * Returns -1, as area is not defined for a line
     * @returns -1
     */
    virtual double area() const override;

    /**
     * Returns -1, as perimeter is not defined for a line
     * @returns -1
     */
    virtual double perimeter() const override;
    virtual std::string toString() const override;

private:
    QPoint end;
};
}
