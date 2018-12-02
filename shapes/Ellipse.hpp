#pragma once
#include "FilledShape.hpp"

namespace jbrush
{
class Ellipse final : public FilledShape
{
public:
    /* Constructors */
    /**
     * Creates an ellipse centered around a point with a given width and height
     * @param center the center of the ellipse
     * @param width the width of the ellipse
     * @param height the height of the ellipse
     * @param props the shape properties, which adjust shape color and style
     */
    Ellipse(const QPoint& center, int width, int height, FilledShapeProperties props = DEFAULT_FILLED_PROPS);

    /**
     * Creates an ellipse centered around an (x,y) coordinate pair with a given width and height
     * @param x the x-coordinate of the center of the ellipse
     * @param y the y-coordinate of the center of the ellipse
     * @param width the width of the ellipse
     * @param height the height of the ellipse
     * @param props the shape properties, which adjust shape color and style
     */
    Ellipse(int x, int y, int width, int height, FilledShapeProperties props = DEFAULT_FILLED_PROPS);

    /* Getters */

    /**
     * Gets the width of the ellipse
     * @returns the width of the ellipse
     */
    int getWidth() const;

    /**
     * Gets the height of the ellipse
     * @returns the height of the ellipse
     */
    int getHeight() const;

    /* Setters */

    /**
     * Updates the width of the ellipse
     * @param width the new width of the ellipse
     */
    void setWidth(int width);

    /**
     * Updates the height of the ellipse
     * @param height the new height of the ellipse
     */
    void setHeight(int height);

    /* Render */
    virtual void draw(QPainter&) const override;

    /* Ellipse Information */

    /**
     * Calculates the area of the ellipse as \f$ \frac{\pi}{4} \times w \times h \f$
     * @returns area of the ellipse
     */
    virtual double area() const override;

    /**
     * Calculates the perimeter (circumference) of the ellipse from the major 
     * and minor axes as \f$ \pi \lbrack 3 (a + b) - \sqrt{(3a+b)(a+3b)} \rbrack \f$
     * @returns perimeter (circumference) of the ellipse
     */
    virtual double perimeter() const override;
    virtual std::string toString() const override;

private:
    int width;
    int height;
};
}
