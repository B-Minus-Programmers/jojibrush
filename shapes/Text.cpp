#include "Text.hpp"

namespace jbrush
{
/* Constructors */
Text::Text(const QPoint& pos, const QString& msg)
    : Shape(pos), text(msg)
{}

Text::Text(const QPoint& pos, const QString& msg, const QFont& fnt)
    : Shape(pos), text(msg), font(fnt)
{}

/* Getters */
QString Text::getText() const
{
    return text;
}

QFont Text::getFont() const
{
    return font;
}

/* Setters */
void Text::setText(const QString& msg)
{
    text = msg;
}

void Text::setFont(const QFont& fnt)
{
    font = fnt;
}

/* Render */
void Text::draw(QPainter& qp) const
{
    qp.setFont(font);
    qp.drawText(position, text);
}

/* Text Information */
double Text::area() const
{
    return -1;
}

double Text::perimeter() const
{
    return -1;
}

std::string Text::toString() const
{
    return "Shape Id: " + std::to_string(getId()) + "\r\n" +
           "ShapeType: Text\r\n" +
           "ShapeDimensions: " +
           std::to_string(position.x())  + ", " +
           std::to_string(position.y())  + "\r\n" +
           "TextString: " + text.toStdString() + "\r\n" +
           "TextColor: \r\n" +
           "TextAlignment: \r\n" +
           "TextPointSize: \r\n" +
           "TextFontFamily: \r\n" +
           "TextFontStyle: \r\n"
           "TextFontWeight: \r\n";
}
}
