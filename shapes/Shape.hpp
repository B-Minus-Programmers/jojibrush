#pragma once
#include <QPoint>
#include <QString>
#include <QPainter>
#include <QtMath>

namespace jbrush
{

/**
 * An object that can be rendered onto a Canvas. Shapes track their position and properties that affect their appearance.
 */
class Shape
{
public:
    /* Constructors */

    /**
     * Creates a shape at a given position
     * @param pos the position of the shape
     */
    Shape(const QPoint& pos);

    /* Destructor */
    virtual ~Shape();

    /* Position */

    /**
     * Returns the shape's position. The relationship of the position to the rendered brush depends on the shape
     * @returns the position of the shape
     */
    QPoint getPosition() const;

    /**
     * Moves the shape to a different position on the canvas.
     * @param pos the shape's new position
     */
    void setPosition(const QPoint& pos);

    /* Render */

    /**
     * Draws the shape onto an activated QPainter
     * @param qp QPainter object opened to the Canvas
     */
    virtual void draw(QPainter& qp) const = 0;

    /* Shape Information */

    /**
     * Returns the shape's unique ID number
     * @returns the shape's ID number
     */
    uint32_t getId() const;

    /**
     * Returns the area of the shape
     * @returns the shape's area, or -1 if area is undefined
     */
    virtual double area() const = 0;

    /**
     * Returns the perimeter of the shape
     * @returns the shape's perimeter, or -1 if perimeter is undefined
     */
    virtual double perimeter() const = 0;

    /**
     * Returns the shape represented as a string. This string can be saved to a file and loaded to restore the shape
     * @returns a string to be saved to a file
     */
    virtual std::string toString() const = 0;

    /**
     * Returns the shape as a Qt::QString.
     * @see toString()
     * @returns the result of toString() casted to a QString
     */
    QString toQString() const;

    /* Operators */
    bool operator< (const Shape&) const;
    bool operator<=(const Shape&) const;
    bool operator> (const Shape&) const;
    bool operator>=(const Shape&) const;
    bool operator==(const Shape&) const;
    bool operator!=(const Shape&) const;

    /* Deleted Members */
    Shape(const Shape&) = delete;
    void operator=(const Shape&) = delete;

protected:
    /* Shape Data */
    QPoint position;

private:
    /* Static Variables */
    static uint32_t nextId;

    /* Shape Data */
    uint32_t id;
};
}
