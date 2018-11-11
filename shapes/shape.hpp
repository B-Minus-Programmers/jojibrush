#pragma once
#include <QWidget>
#include <QPoint>
#include <QString>
#include <QPainter>
#include <string>

namespace jbrush
{
class Shape
{
public:
    /* Constructors */
    Shape(QPoint);

    /* Destructor */
    virtual ~Shape();

    /* Position */
    QPoint getPosition() const;
    void   setPosition(QPoint);

    /* Render */
    virtual void draw(QPainter&) const = 0;

    /* Shape Information */
    unsigned int getId() const;
    virtual unsigned int area()      const = 0;
    virtual unsigned int perimeter() const = 0;
    virtual std::string  toString()  const = 0;
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

private:
    /* Static Variables */
    static unsigned int nextId;

    /* Shape Data */
    unsigned int id;
    QPoint position;
};
}
