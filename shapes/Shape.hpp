#pragma once
#include <QPoint>
#include <QString>
#include <QPainter>
#include <QtMath>

namespace jbrush
{
class Shape
{
public:
    /* Constructors */
    Shape(const QPoint&);

    /* Destructor */
    virtual ~Shape();

    /* Position */
    QPoint getPosition() const;
    void   setPosition(const QPoint&);

    /* Render */
    virtual void draw(QPainter&) const = 0;

    /* Shape Information */
    uint32_t getId() const;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string toString() const = 0;
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
