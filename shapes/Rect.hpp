#pragma once
#include "Shape.hpp"

namespace jbrush
{
class Rect final : public Shape
{
public:
    /* Constructors */
    
    /**
     * Creates a rectangle from two points
     * @param topL the top-left point of the rectangle
     * @param bottomR the bottom-right point of the rectangle
     */
    Rect(const QPoint& topL, const QPoint& bottomR);

    /**
     * Creates a rectangle at a given position, with a given width and height
     * @param topL the top-left point of the rectangle
     * @param width the width of the rectangle
     * @param height the height of the rectangle
     */
    Rect(const QPoint& topL, int width, int height);

    /**
     * Creates a rectangle at a given (x,y) coordinate pair, with a given width and height
     * @param x the x-coordinate of the top left of the rectangle
     * @param y the y-coordinate of the top left of the rectangle
     * @param width the width of the rectangle
     * @param height the height of the rectangle
     */
    Rect(int x, int y, int width, int height);

    /* Getters */

    /**
     * Returns the width of the rectangle
     * @returns the width of the rectangle
     */
    int getWidth() const;

    /**
     * Returns the height of the rectangle
     * @returns the height of the rectangle
     */
    int getHeight() const;

    /* Setters */

    /**
     * Sets the width of the rectangle
     * @param width the new width of the rectangle
     */
    void setWidth(int width);

    /**
     * Sets the height of the rectangle
     * @param height the new height of the rectangle
     */
    void setHeight(int height);

    /* Render */
    virtual void draw(QPainter&) const override;

    /* Rect Information */

    /**
     * Calculates the area of the rectangle as \f$ width \times height \f$
     * @returns the area of the rectangle
     */
    virtual double area() const override;

    /**
     * Calculates the perimeter of the rectangle as \f$ 2 \times width + 2 \times height \f$
     * @returns the perimeter of the rectangle
     */
    virtual double perimeter() const override;
    virtual std::string toString() const override;

private:
    int width;
    int height;
};
}
