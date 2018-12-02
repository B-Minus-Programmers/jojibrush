#pragma once

#include <QPen>
#include <QFont>

namespace jbrush
{
struct GeometricShapeProperties
{
    Qt::GlobalColor penColor;
    uint8_t penWidth;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;
};

const GeometricShapeProperties DEFAULT_GEOMETRIC_PROPS = 
{ 
    Qt::GlobalColor::black, 
    1, 
    Qt::PenStyle::SolidLine,
    Qt::PenCapStyle::FlatCap,
    Qt::PenJoinStyle::MiterJoin
};

struct FilledShapeProperties
{
    GeometricShapeProperties border;
    Qt::GlobalColor brushColor;
    Qt::BrushStyle brushStyle;
};

const FilledShapeProperties DEFAULT_FILLED_PROPS =
{
    DEFAULT_GEOMETRIC_PROPS,
    Qt::GlobalColor::black,
    Qt::BrushStyle::NoBrush
};

struct TextShapeProperties
{
    Qt::GlobalColor textColor;
    Qt::AlignmentFlag textAlignment;
    int8_t textSize;
    QString textFontFamily;
    QFont::Style textFontStyle;
    QFont::Weight textFontWeight;
};

const TextShapeProperties DEFAULT_TEXT_PROPS =
{
    Qt::GlobalColor::black,
    Qt::AlignmentFlag::AlignLeft,
    12,
    "Comic Sans MS",
    QFont::Style::StyleNormal,
    QFont::Weight::Normal
};
}
