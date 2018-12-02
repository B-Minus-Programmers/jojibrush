#include "FilledShape.hpp"
#include "utils/exceptions.hpp"

namespace jbrush
{
FilledShape::FilledShape(const QPoint& pos, FilledShapeProperties props) : GeometricShape(pos, props.border)
{
    this->props = props;
}

void FilledShape::applyProperties(QPainter& qp) const
{
    GeometricShape::applyProperties(qp);

    QBrush brush;
    brush.setColor(props.brushColor);
    brush.setStyle(props.brushStyle);
    qp.setBrush(brush);
}

std::string FilledShape::stringifyProperties() const
{
    std::string geometricProps, brushColor, brushStyle;

    geometricProps = GeometricShape::stringifyProperties();

    switch (props.brushColor)
    {
        case Qt::GlobalColor::white:
            brushColor = "white"; break;
        case Qt::GlobalColor::black:
            brushColor = "black"; break;
        case Qt::GlobalColor::red:
            brushColor = "red"; break;
        case Qt::GlobalColor::green:
            brushColor = "green"; break;
        case Qt::GlobalColor::blue:
            brushColor = "blue"; break;
        case Qt::GlobalColor::cyan:
            brushColor = "cyan"; break;
        case Qt::GlobalColor::magenta:
            brushColor = "magenta"; break;
        case Qt::GlobalColor::yellow:
            brushColor = "yellow"; break;
        case Qt::GlobalColor::gray:
            brushColor = "gray"; break;
        default:
            throw GeneralException("invalid brush color");
    }

    switch (props.brushStyle)
    {
        case Qt::BrushStyle::SolidPattern:
            brushStyle = "SolidPattern"; break;
        case Qt::BrushStyle::HorPattern:
            brushStyle = "HorPattern"; break;
        case Qt::BrushStyle::VerPattern:
            brushStyle = "VerPattern"; break;
        case Qt::BrushStyle::NoBrush:
            brushStyle = "NoBrush"; break;
        default:
            throw GeneralException("invalid brush style");
    }

    return geometricProps + "\r\n" +
           "BrushColor: " + brushColor + "\r\n" +
           "BrushStyle: " + brushStyle;
}
}
