#pragma once
#include <QWidget>
#include <QPainter>
#include "utils/vector.hpp"
#include "utils/FileHandler.hpp"
#include "shapes/Shape.hpp"
#include "AccountType.hpp"
#include "shapes/Properties.hpp"
#include "menus/shapeselectmenu.hpp"

using jbrush::Vector;
using jbrush::Shape;

namespace jbrush
{
class Canvas : public QWidget
{
    Q_OBJECT
private:
    Vector<Shape*> shapes;
    jbrush::AccountType accType;

    bool drawShapeIds;

    SelectableShapeType shapeTypeSelected;    // Shape type currently selected by the user
    FilledShapeProperties selectedFilledProperties; // Set of filled shape properties currently selected by the user
    TextShapeProperties selectedTextProperties; // Set of text properties currently selected by the

public slots:
    void updateShapeType(SelectableShapeType);
    void updateGeometricProperties(GeometricShapeProperties);   // Update geometric properties with the properties signalled
    void updateFilledProperties(Qt::GlobalColor, Qt::BrushStyle);   // Update brush color and style
    void updateTextProperties(TextShapeProperties); // Update text properties with the propertiers emitted

public:
    Canvas(QWidget *parent = nullptr);
    ~Canvas();

    Vector<Shape*> getShapes();

    bool loadFromFile(QString& file);
        // Gets shapes from file at the directory specified and draws them to the screen
        // Returns true if the load was successful, false otherwise
        // Current shapes are unmodified if the load fails

    void addShape(Shape*);
    void removeShape(uint32_t);

    void clearShapes();

    jbrush::AccountType getAccountType() const;
    void setAccountType(jbrush::AccountType);

    void setDrawShapeIds(bool);

    void setSelectedShapeType(SelectableShapeType);
    void setSelectedFilledProperties(GeometricShapeProperties, Qt::GlobalColor, Qt::BrushStyle);
    void setSelectedTextProperties(TextShapeProperties);
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};
};
