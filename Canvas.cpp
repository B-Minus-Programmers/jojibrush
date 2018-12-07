#include "Canvas.hpp"
#include "utils/exceptions.hpp"
#include <QPainter>

using jbrush::Canvas;

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    drawShapeIds = true;
    pGon = nullptr;
    pLine = nullptr;
    mLine = nullptr;
    mRect = nullptr;
    circ = nullptr;
    elli = nullptr;
    text = nullptr;
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
void Canvas::mousePressEvent(QMouseEvent* event)
{
    switch(shapeTypeSelected)
    {
        case SelectableShapeType::LINE:
             mLine = new Line(event->pos(), event->pos(), selectedFilledProperties.border);
             addShape(mLine);
        break;

        case SelectableShapeType::POLYLINE:
        {
             QPoint point = event->pos();

             if(pLine == nullptr)
              {
                 pLine = new Polyline(&point,1, selectedFilledProperties.border);
                 addShape(pLine);
              }
              else
              {
                 pLine->addPoint(event->pos());
              }
        }
        break;

        case SelectableShapeType::POLYGON:
        {
            QPoint point = event->pos();

            if(pGon == nullptr)
            {
                pGon = new Polygon(&point,1, selectedFilledProperties);
                addShape(pGon);
            }
            else
            {
                pGon->addPoint(event->pos());
            }
        }
        break;

        case SelectableShapeType::RECTANGLE:
             mRect = new Rectangle(event->pos(), event->pos(), selectedFilledProperties);
             addShape(mRect);
        break;

        case SelectableShapeType::ELLIPSE:
             elli = new Ellipse(event->pos(),0,0, selectedFilledProperties);
             addShape(elli);
        break;

        case SelectableShapeType::CIRCLE:
             circ = new Circle(event->pos(),0, selectedFilledProperties);
             addShape(circ);
        break;

        case SelectableShapeType::TEXT:
             text = new Text(event->pos(), 100, 100,"", selectedTextProperties);
             addShape(text);
        break;
    }
    repaint();
}

void Canvas::mouseMoveEvent(QMouseEvent* event)
{

    switch(shapeTypeSelected)
    {
        case SelectableShapeType::LINE:
                 mLine->setEnd(event->pos());
             break;

        case SelectableShapeType::RECTANGLE:
            mRect->setHeight(event->pos().y() - mRect->getPosition().y());
            mRect->setWidth(event->pos().x() - mRect->getPosition().x());
        break;

        case SelectableShapeType::ELLIPSE:
            elli->setHeight(event->pos().y() - elli->getPosition().y());
            elli->setWidth(event->pos().x() - elli->getPosition().x());
        break;

        case SelectableShapeType::CIRCLE:
        {
        QPoint point = event->pos() - circ->getPosition();
        int num = qSqrt(qPow(point.x(),2)+ qPow(point.y(),2));

        circ->setRadius(num);
        }
        break;

        case SelectableShapeType::TEXT:
        {

        if(event->pos().y() > text->getPosition().y())
        {
            text->setHeight(event->pos().y() - text->getPosition().y());
            text->setWidth(event->pos().x() - text->getPosition().x());
        }
        else
        {
            text->setWidth(text->getPosition().x() - event->pos().x());
            text->setHeight(text->getPosition().y() - event->pos().y());
        }

        text->setText("Hello World");
        }
        break;
    }

    //it calls the paintEven() function continuously
    update();
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
void Canvas::updateShapeType(jbrush::SelectableShapeType type)
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
