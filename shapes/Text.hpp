#pragma once
#include "Shape.hpp"
#include "Properties.hpp"

namespace jbrush
{
class Text final : public Shape
{
public:
    /* Constructor */
    /**
     * Creates a text box at a given position with a given message
     * @param position position of the text box
     * @param width the width of the text box
     * @param height the height of the text box
     * @param msg the contents of the text box
     * @param props the text properties, which adjust font and color
     */
    Text(const QPoint& position, int width, int height, const QString& msg, TextShapeProperties props = DEFAULT_TEXT_PROPS);

    /* Getters */

    /**
     * Returns the contents of the text box
     * @returns contents of the text box
     */
    QString getText() const;

    /* Setters */
    
    /**
     * Updates the contents of the text box
     * @param msg the new contents of the text box
     */
    void setText(const QString&);

    /* Render */
    virtual void draw(QPainter&) const override;

    /* Text Information */

    /**
     * Returns -1, as area is not defined for a text box
     * @returns -1
     */
    virtual double area() const override;

    /**
     * Returns -1, as perimeter is not defined for a text box
     * @returns -1
     */
    virtual double perimeter() const override;
    virtual std::string toString() const override;

private:
    int width, height;
    QString text;
    TextShapeProperties props;

    virtual void applyProperties(QPainter&) const override;
    virtual std::string stringifyProperties() const override;
};
}
