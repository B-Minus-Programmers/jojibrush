#pragma once
#include <QWidget>
#include <QPainter>

#include "utils/vector.hpp"
#include "utils/FileHandler.hpp"
#include "shapes/Shape.hpp"
#include "AccountType.hpp"

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
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};
};
