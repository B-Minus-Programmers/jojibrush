#include "Canvas.hpp"
#include "utils/exceptions.hpp"
#include <QPainter>

using jbrush::Canvas;

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    drawShapeIds = true;
}

Canvas::~Canvas()
{
    // Free all shapes when deleted. Vector class will delete dynamic array
    clearShapes();
}

Vector<Shape*> Canvas::getShapes()
{
    return shapes;
}

bool Canvas::loadFromFile(QString &fileDir)
{
    jbrush::FileHandler fileUtil;
    Vector<Shape*> shapesLoaded;    // Shapes loaded by the file utility

    // Load the shapes
    shapesLoaded = fileUtil.loadShapesFromFile(fileDir);

    // If shapes were actually loaded from the file, update current shapes
    if(shapesLoaded.getSize() > 0)
    {
        clearShapes();
        shapes = shapesLoaded;
        repaint();

        // Return true - load successful
        return true;
    }
    else
    {
        // Otherwise, if load size is less than or equal to zero, return false - load failed
        return false;
    }
}

void Canvas::addShape(Shape *shape) 
{
    shapes.push_back(shape);
}

void Canvas::removeShape(uint32_t id) 
{
    for (uint32_t i = 0; i < shapes.getSize(); i++) 
    {
        if (shapes[i]->getId() == id)
        {
            shapes.erase(i);
            return;
        }
    }
}

void Canvas::clearShapes()
{   
    // Deallocate space for the shape pointers
    for (auto shapePtr : shapes)
    {
        delete shapePtr;
    }

    // Clear out the shape vector
    shapes.clear();
}

jbrush::AccountType Canvas::getAccountType() const
{
    return accType;
}

void Canvas::setAccountType(jbrush::AccountType type)
{
    accType = type;
}

void Canvas::paintEvent(QPaintEvent*)
{
    QPainter painter;
    painter.begin(this);
    for (auto shape : shapes)
    {
        shape->draw(painter);

        // reset the pen, setting text color to black
        painter.setPen(QPen());
        if (drawShapeIds)
        {
            painter.drawText(shape->getPosition(), "#" + QString::number(shape->getId()));
        }
    }
    painter.end();
}

void Canvas::setDrawShapeIds(bool drawShapeIds) {
    this->drawShapeIds = drawShapeIds;
    this->repaint();
}

void Canvas::setSelectedShapeType(jbrush::SelectableShapeType type)
{
    shapeTypeSelected = type;
}

void Canvas::setSelectedFilledProperties(jbrush::GeometricShapeProperties border, Qt::GlobalColor color, Qt::BrushStyle style)
{
    selectedFilledProperties.border = border;
    selectedFilledProperties.brushColor = color;
    selectedFilledProperties.brushStyle = style;
}

void Canvas::setSelectedTextProperties(jbrush::TextShapeProperties props)
{
    selectedTextProperties = props;
}

// SLOT DEFINITIONS
void Canvas::updateShapeType(SelectableShapeType type)
{
    shapeTypeSelected = type;
}
void Canvas::updateGeometricProperties(jbrush::GeometricShapeProperties props)
{
    selectedFilledProperties.border = props;
}
void Canvas::updateFilledProperties(Qt::GlobalColor color, Qt::BrushStyle style)
{
    selectedFilledProperties.brushColor = color;
    selectedFilledProperties.brushStyle = style;
}
void Canvas::updateTextProperties(jbrush::TextShapeProperties props)
{
    selectedTextProperties = props;
}
