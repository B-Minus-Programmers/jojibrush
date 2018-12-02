#include "GeometricShape.hpp"
#include "utils/exceptions.hpp"

namespace jbrush
{
void GeometricShape::applyProperties(QPainter& qp) const
{
    QPen pen;
    pen.setColor(this->props.penColor);
    pen.setWidth(this->props.penWidth);
    pen.setStyle(this->props.penStyle);
    pen.setCapStyle(this->props.penCapStyle);
    pen.setJoinStyle(this->props.penJoinStyle);

    qp.setPen(pen);
}

std::string GeometricShape::stringifyProperties() const
{
    std::string penColor, penWidth, penStyle, penCapStyle, penJoinStyle;

    switch (props.penColor)
    {
        case Qt::GlobalColor::white:
            penColor = "white"; break;
        case Qt::GlobalColor::black:
            penColor = "black"; break;
        case Qt::GlobalColor::red:
            penColor = "red"; break;
        case Qt::GlobalColor::green:
            penColor = "green"; break;
        case Qt::GlobalColor::blue:
            penColor = "blue"; break;
        case Qt::GlobalColor::cyan:
            penColor = "cyan"; break;
        case Qt::GlobalColor::magenta:
            penColor = "magenta"; break;
        case Qt::GlobalColor::yellow:
            penColor = "yellow"; break;
        case Qt::GlobalColor::gray:
            penColor = "gray"; break;
        default:
             throw GeneralException("invalid pen color");
    }

    penWidth = std::to_string(props.penWidth);

    switch (props.penStyle)
    {
        case Qt::PenStyle::NoPen:
            penStyle = "NoPen"; break;
        case Qt::PenStyle::SolidLine:
            penStyle = "SolidLine"; break;
        case Qt::PenStyle::DashLine:
            penStyle = "DashLine"; break;
        case Qt::PenStyle::DotLine:
            penStyle = "DotLine"; break;
        case Qt::PenStyle::DashDotLine:
            penStyle = "DashDotLine"; break;
        case Qt::PenStyle::DashDotDotLine:
            penStyle = "DashDotDotLine"; break;
        default:
            throw GeneralException("invalid pen style");
    }

    switch (props.penCapStyle)
    {
        case Qt::PenCapStyle::FlatCap:
            penCapStyle = "FlatCap"; break;
        case Qt::PenCapStyle::SquareCap:
            penCapStyle = "SquareCap"; break;
        case Qt::PenCapStyle::RoundCap:
            penCapStyle = "RoundCap"; break;
        default:
            throw GeneralException("invalid pen cap style");
    }

    switch (props.penJoinStyle)
    {
        case Qt::PenJoinStyle::MiterJoin:
            penJoinStyle = "MiterJoin"; break;
        case Qt::PenJoinStyle::BevelJoin:
            penJoinStyle = "BevelJoin"; break;
        case Qt::PenJoinStyle::RoundJoin:
            penJoinStyle = "RoundJoin"; break;
        default:
            throw GeneralException("invalid pen join style");
    }

    return "PenColor: " + penColor + "\r\n" +
           "PenWidth: " + penWidth + "\r\n" +
           "PenStyle: " + penStyle + "\r\n" +
           "PenCapStyle: " + penCapStyle + "\r\n" +
           "PenJoinStyle: " + penJoinStyle;
}
}
