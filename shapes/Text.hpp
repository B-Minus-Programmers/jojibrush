#pragma once
#include "Shape.hpp"

namespace jbrush
{
class Text final : public Shape
{
public:
    /* Constructor */

    /**
     * Creates a text box at a given position with a given message
     * @param position position of the text box
     * @param msg the contents of the text box
     */
    Text(const QPoint& position, const QString& msg);

    /**
     * Creates a text box at a given position, with a given message with a custom font
     * @param position position of the text box
     * @param msg contents of the text box
     * @param font font to use when rendering the message
     */
    Text(const QPoint& position, const QString& msg, const QFont& font);

    /* Getters */

    /**
     * Returns the contents of the text box
     * @returns contents of the text box
     */
    QString getText() const;

    /**
     * Returns the font being used to render the contents of the text box
     * @returns the font
     */
    QFont getFont() const;

    /* Setters */

    /**
     * Updates the contents of the text box
     * @param msg the new contents of the text box
     */
    void setText(const QString& msg);

    /**
     * Updates the font used to draw the contents of the text box
     * @param font the new font
     */
    void setFont(const QFont& font);

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
    QString text;
    QFont   font;
};
}
