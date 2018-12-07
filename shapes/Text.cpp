#include "Text.hpp"

namespace jbrush
{
/* Constructors */
Text::Text(const QPoint& pos, int width, int height, const QString& msg, TextShapeProperties props)
    : Shape(pos), width(width), height(height), text(msg), props(props)
{}

/* Getters */
QString Text::getText() const
{
    return text;
}

int Text::getWidth() const
{
    return width;
}

int Text::getHeight() const
{
    return height;
}

/* Setters */
void Text::setText(const QString& txt)
{
    text = txt;
}

void Text::setWidth(int w)
{
    width = w;
}

void Text::setHeight(int h)
{
    height = h;
}

/* Render */
void Text::draw(QPainter& qp) const
{
    Shape::draw(qp);
    qp.drawText(position.x(), position.y(), width, height, (int) props.textAlignment, text);
}

void Text::applyProperties(QPainter& qp) const
{
    qp.setPen(props.textColor); // QFont doesn't have a color cuz dumb dumb
    QFont font;
    
    font.setPointSize(props.textSize);
    font.setFamily(props.textFontFamily);
    font.setStyle(props.textFontStyle);

    qp.setFont(font);
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
           std::to_string(position.y())  + ", " +
           std::to_string(width)         + ", " +
           std::to_string(height)        + "\r\n" +
           "TextString: " + text.toStdString() + "\r\n" +
           stringifyProperties() + "\r\n";
}

std::string Text::stringifyProperties() const
{
    std::string textColor, textAlignment, textPointSize, textFontFamily, textFontStyle, textFontWeight;

    switch (props.textColor)
    {
        case Qt::GlobalColor::white:
            textColor = "white"; break;
        case Qt::GlobalColor::black:
            textColor = "black"; break;
        case Qt::GlobalColor::red:
            textColor = "red"; break;
        case Qt::GlobalColor::green:
            textColor = "green"; break;
        case Qt::GlobalColor::blue:
            textColor = "blue"; break;
        case Qt::GlobalColor::cyan:
            textColor = "cyan"; break;
        case Qt::GlobalColor::magenta:
            textColor = "magenta"; break;
        case Qt::GlobalColor::yellow:
            textColor = "yellow"; break;
        case Qt::GlobalColor::gray:
            textColor = "gray"; break;
    }

    switch (props.textAlignment)
    {
        case Qt::AlignmentFlag::AlignLeft:
            textAlignment = "AlignLeft"; break;
        case Qt::AlignmentFlag::AlignRight:
            textAlignment = "AlignRight"; break;
        case Qt::AlignmentFlag::AlignTop:
            textAlignment = "AlignTop"; break;
        case Qt::AlignmentFlag::AlignBottom:
            textAlignment = "AlignBottom"; break;
        case Qt::AlignmentFlag::AlignCenter:
            textAlignment = "AlignCenter"; break;
    }

    textPointSize = std::to_string(props.textSize);

    textFontFamily = props.textFontFamily.toStdString();

    switch (props.textFontStyle)
    {
        case QFont::Style::StyleNormal:
            textFontStyle = "StyleNormal"; break;
        case QFont::Style::StyleItalic:
            textFontStyle = "StyleItalic"; break;
        case QFont::Style::StyleOblique:
            textFontStyle = "StyleOblique"; break;
    }

    switch (props.textFontWeight)
    {
        case QFont::Weight::Thin:
            textFontWeight = "Thin"; break;
        case QFont::Weight::Light:
            textFontWeight = "Light"; break;
        case QFont::Weight::Normal:
            textFontWeight = "Normal"; break;
        case QFont::Weight::Bold:
            textFontWeight = "Bold"; break;
    }

    return "TextColor: " + textColor + "\r\n"
           "TextAlignment: " + textAlignment + "\r\n" +
           "TextPointSize: " + textPointSize + "\r\n" +
           "TextFontFamily: " + textFontFamily + "\r\n" +
           "TextFontStyle: " + textFontStyle + "\r\n" +
           "TextFontWeight: " + textFontWeight;
}
}
