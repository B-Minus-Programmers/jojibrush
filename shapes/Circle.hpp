#pragma once
#include "Shape.hpp"

namespace jbrush
{
class Circle final : public Shape
{
public:
    /* Constructors */

    /**
     * Creates a circle centered at a point with a given radius
     * @param center the center of the circle
     * @param radius the radius of the circle
     */
    Circle(const QPoint& center, int radius);

    /**
     * Creates a circle centered at an (x,y) coordinate pair with a given radius
     * @param x the x-coordinate to center the circle around
     * @param y the y-coordinate to center the circle around
     * @param radius the radius of the circle
     */
    Circle(int x, int y, int radius);

    /* Getters */

    /**
     * Returns the radius of the circle
     * @returns the circle's radius
     */
    int getRadius() const;

    /* Setters */

    /**
     * Sets the radius of the circle to a new value
     * @param radius the new radius
     */
    void setRadius(int radius);

    /* Render */
    virtual void draw(QPainter&) const override;

    /* Circle Information */

    /**
     * Calculates the area of the circle as \f$ \pi r^2 \f$
     * @returns the area of the circle
     */
    virtual double area() const override;

    /**
     * Calculates the perimeter (circumference) of the circle as \f$ 2 \pi r \f$
     * @returns the circumference of the circle
     */
    virtual double perimeter() const override;
    virtual std::string toString() const override;

private:
    int radius;
};
}
