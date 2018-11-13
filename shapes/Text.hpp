#pragma once
#include "Shape.hpp"

namespace jbrush
{
class Text final : public Shape
{
public:
    /* Constructor */
    Text(const QPoint& position, const QString&);
    Text(const QPoint& position, const QString&, const QFont&);

    /* Getters */
    QString getText() const;
    QFont   getFont() const;

    /* Setters */
    void setText(const QString&);
    void setFont(const QFont&);

    /* Render */
    virtual void draw(QPainter&) const override;

    /* Text Information */
    virtual double area() const override;
    virtual double perimeter() const override;
    virtual std::string toString() const override;

private:
    QString text;
    QFont   font;
};
}
