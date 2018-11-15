#pragma once
#include <QWidget>
#include <QPainter>

#include "utils/vector.hpp"
#include "shapes/Shape.hpp"

using jbrush::Vector;
using jbrush::Shape;

namespace jbrush
{
class Canvas : public QWidget
{
    Q_OBJECT
private:
    Vector<Shape*> shapes;
public:
    Canvas(QWidget *parent = nullptr);
    ~Canvas();

    Vector<Shape*> getShapes();

    void addShape(Shape*);
    void removeShape(uint32_t);
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};
};
