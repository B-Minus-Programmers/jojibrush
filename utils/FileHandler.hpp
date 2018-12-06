#pragma once

#include "shapes/Shapes.hpp"
#include "Canvas.hpp"
#include "exceptions.hpp"
#include "utils/algorithms.hpp"
#include <QString>
#include <QChar>
#include <QMap>
#include <QColor>
#include <QFont>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

namespace jbrush {

namespace jconstants {
// Base extension for files used to load from/save to
const QString FILE_EXTENSION = ".jbrush";

// Data class member functions expect these strings as identifiers for the shape that is being read in
const QString LINE = "Line";
const QString POLYLINE = "Polyline";
const QString POLYGON = "Polygon";
const QString RECTANGLE = "Rectangle";
const QString SQUARE = "Square";
const QString ELLIPSE = "Ellipse";
const QString CIRCLE = "Circle";
const QString TEXT = "Text";
const QStringList TYPE_LIST = {LINE, POLYLINE, POLYGON, RECTANGLE, SQUARE, ELLIPSE, CIRCLE, TEXT };

// Maps the name of the shape to the number dimensions that should be listed for it
const QMap<QString, uint32_t> DIMENSION_COUNT_MAP = {
    {LINE, 4}, {RECTANGLE, 4}, {SQUARE, 3}, {ELLIPSE, 4}, {CIRCLE, 3}, {TEXT, 4}
};

// The parser expects this character at the end of descriptive titles for data
const QChar TITLE_INTERRUPTOR = ':';
// The parser expects this character to interrupt each piece of data in the line of text that gives the shape's dimensions
const QChar DIMENSION_INTERRUPTOR = ',';

// Maps enable the parser to quickly obtain the value associated with the text used to initialize the shape's data
const QMap<QString, Qt::GlobalColor> COLOR_MAP = {
  {"white", Qt::GlobalColor::white}, {"black", Qt::GlobalColor::black}, {"red", Qt::GlobalColor::red},
  {"green", Qt::GlobalColor::green}, {"blue", Qt::GlobalColor::blue}, {"cyan", Qt::GlobalColor::cyan},
  {"magenta", Qt::GlobalColor::magenta}, {"yellow", Qt::GlobalColor::yellow}, {"gray", Qt::GlobalColor::gray}
};
const QMap<QString, Qt::PenStyle> PEN_STYLE_MAP = {
    {"NoPen", Qt::NoPen}, {"SolidLine", Qt::SolidLine}, {"DashLine", Qt::DashLine},
    {"DotLine", Qt::DotLine}, {"DashDotLine", Qt::DashDotLine}, {"DashDotDotLine", Qt::DashDotDotLine},
    {"CustomDashLine", Qt::CustomDashLine}
};
const QMap<QString, Qt::PenCapStyle> PEN_CAP_MAP = {
    {"SquareCap", Qt::SquareCap}, {"FlatCap", Qt::FlatCap}, {"RoundCap", Qt::RoundCap}
};
const QMap<QString, Qt::PenJoinStyle> PEN_JOIN_MAP = {
    {"BevelJoin", Qt::BevelJoin}, {"MiterJoin", Qt::MiterJoin}, {"RoundJoin", Qt::RoundJoin}
};
const QMap<QString, Qt::BrushStyle> BRUSH_STYLE_MAP = {
    {"SolidPattern", Qt::SolidPattern}, {"Dense1Pattern", Qt::Dense1Pattern}, {"Dense2Pattern", Qt::Dense2Pattern},
    {"Dense3Pattern", Qt::Dense3Pattern}, {"Dense4Pattern", Qt::Dense4Pattern}, {"Dense5Pattern", Qt::Dense5Pattern},
    {"Dense6Pattern", Qt::Dense6Pattern}, {"Dense7Pattern", Qt::Dense7Pattern}, {"NoBrush", Qt::NoBrush},
    {"HorPattern", Qt::HorPattern}, {"VerPattern", Qt::VerPattern}, {"CrossPattern", Qt::CrossPattern},
    {"BDiagPattern", Qt::BDiagPattern}, {"FDiagPattern", Qt::FDiagPattern}, {"DiagCrossPattern", Qt::DiagCrossPattern},
    {"LinearGradientPattern", Qt::LinearGradientPattern}, {"LinearGradientPattern", Qt::LinearGradientPattern}, {"ConicalGradientPattern", Qt::ConicalGradientPattern}
};
const QMap<QString, Qt::AlignmentFlag> TEXT_ALIGN_MAP = {
    {"AlignLeft", Qt::AlignLeft}, {"AlignRight", Qt::AlignRight}, {"AlignTop", Qt::AlignTop},
    {"AlignBottom", Qt::AlignBottom}, {"AlignCenter", Qt::AlignCenter}
};
const QMap<QString, QFont::Style> TEXT_STYLE_MAP = {
    {"StyleNormal", QFont::StyleNormal}, {"StyleItalic", QFont::StyleItalic}, {"StyleOblique", QFont::StyleOblique}
};
const QMap<QString, QFont::Weight> TEXT_WEIGHT_MAP = {
    {"Thin", QFont::Thin}, {"ExtraLight", QFont::ExtraLight}, {"Light", QFont::Light},
    {"Normal", QFont::Normal}, {"Medium", QFont::Medium}, {"DemiBold", QFont::DemiBold},
    {"Bold", QFont::Bold}, {"ExtraBold", QFont::ExtraBold}, {"Black", QFont::Black},
};
}

class FileHandler
{
public:
    Vector<Shape*> loadShapesFromFile(const QString&);
        // Returns a shape vector from data at the directory specified

private:
    Shape *extractShape(QTextStream&);  // Large helper function extracts and returns the shape that the text stream is currently on
    Shape *extractNonText(QTextStream&, QString&, QList<int>&);    // Extract data for a shape that isn't a text, like a line or a square
    Shape *extractText(QTextStream&, QList<int>&);   // Extract all the data needed for a text object
    QList<int> extractDimensions(QTextStream&, const QString&);  // Extract dimensions from the file stream
    QPen extractPen(QTextStream&);
    QBrush extractBrush(QTextStream&);
    QFont extractFont(QTextStream&);  // Extract data on the shape's font from the text stream specified

    Shape *constructLine(QString&, QList<int>&);  // Construct a line-type using the given data
    Shape *constructShape(QString&, QList<int>&); // Construct a 2-d type shape with the given data

    QPoint *getPoints(QList<int>&);    // Helper function converts a list of integers to a pointer to a block of qpoitns

    void checkDimensions(const QTextStream&, const QString&, uint32_t);    // Check the dimensions length given against the shape name and see if the list is valid
};
}
