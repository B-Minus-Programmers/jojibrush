#include "shapeselectmenu.hpp"
#include "ui_shapeselectmenu.h"

ShapeSelectMenu::ShapeSelectMenu(QWidget *parent) :
    QWidget(parent),
    shapeTypeSelected(jbrush::SelectableShapeType::LINE),
    ui(new Ui::ShapeSelectMenu)
{
    ui->setupUi(this);

    // Make all select buttons checkable
    ui->selectLine->setCheckable(true);
    ui->selectPolyline->setCheckable(true);
    ui->selectPolygon->setCheckable(true);
    ui->selectRectangle->setCheckable(true);
    ui->selectEllipse->setCheckable(true);
    ui->selectCircle->setCheckable(true);
    ui->selectText->setCheckable(true);
}

QPushButton *ShapeSelectMenu::getSelectLineButton() const
{
    return ui->selectLine;
}

QPushButton *ShapeSelectMenu::getSelectPolylineButton() const
{
    return ui->selectPolyline;
}
QPushButton *ShapeSelectMenu::getSelectRectangleButton() const
{
    return ui->selectRectangle;
}
QPushButton *ShapeSelectMenu::getSelectEllipseButton() const
{
    return ui->selectEllipse;
}
QPushButton *ShapeSelectMenu::getSelectCircleButton() const
{
    return ui->selectCircle;
}
QPushButton *ShapeSelectMenu::getSelectTextButton() const
{
    return ui->selectText;
}

void ShapeSelectMenu::on_selectLine_clicked()
{
    shapeTypeSelected = jbrush::SelectableShapeType::LINE;

    // Check line select and de-select everything else
    ui->selectLine->setChecked(true);
    ui->selectPolyline->setChecked(false);
    ui->selectPolygon->setChecked(false);
    ui->selectRectangle->setChecked(false);
    ui->selectEllipse->setChecked(false);
    ui->selectCircle->setChecked(false);
    ui->selectText->setChecked(false);

    // Emit the "onSelection" signal
    onSelection(shapeTypeSelected);
}

void ShapeSelectMenu::on_selectPolyline_clicked()
{
    shapeTypeSelected = jbrush::SelectableShapeType::POLYLINE;

    // Check line select and de-select everything else
    ui->selectLine->setChecked(false);
    ui->selectPolyline->setChecked(true);
    ui->selectPolygon->setChecked(false);
    ui->selectRectangle->setChecked(false);
    ui->selectEllipse->setChecked(false);
    ui->selectCircle->setChecked(false);
    ui->selectText->setChecked(false);

    // Emit the "onSelection" signal
    onSelection(shapeTypeSelected);
}

void ShapeSelectMenu::on_selectPolygon_clicked()
{
    shapeTypeSelected = jbrush::SelectableShapeType::POLYGON;

    // Check line select and de-select everything else
    ui->selectLine->setChecked(false);
    ui->selectPolyline->setChecked(false);
    ui->selectPolygon->setChecked(true);
    ui->selectRectangle->setChecked(false);
    ui->selectEllipse->setChecked(false);
    ui->selectCircle->setChecked(false);
    ui->selectText->setChecked(false);

    // Emit the "onSelection" signal
    onSelection(shapeTypeSelected);
}

void ShapeSelectMenu::on_selectRectangle_clicked()
{
    shapeTypeSelected = jbrush::SelectableShapeType::RECTANGLE;

    // Check line select and de-select everything else
    ui->selectLine->setChecked(false);
    ui->selectPolyline->setChecked(false);
    ui->selectPolygon->setChecked(false);
    ui->selectRectangle->setChecked(true);
    ui->selectEllipse->setChecked(false);
    ui->selectCircle->setChecked(false);
    ui->selectText->setChecked(false);

    // Emit the "onSelection" signal
    onSelection(shapeTypeSelected);
}

void ShapeSelectMenu::on_selectEllipse_clicked()
{
    shapeTypeSelected = jbrush::SelectableShapeType::ELLIPSE;

    // Check line select and de-select everything else
    ui->selectLine->setChecked(false);
    ui->selectPolyline->setChecked(false);
    ui->selectPolygon->setChecked(false);
    ui->selectRectangle->setChecked(false);
    ui->selectEllipse->setChecked(true);
    ui->selectCircle->setChecked(false);
    ui->selectText->setChecked(false);

    // Emit the "onSelection" signal
    onSelection(shapeTypeSelected);
}

void ShapeSelectMenu::on_selectCircle_clicked()
{
    shapeTypeSelected = jbrush::SelectableShapeType::CIRCLE;

    // Check line select and de-select everything else
    ui->selectLine->setChecked(false);
    ui->selectPolyline->setChecked(false);
    ui->selectPolygon->setChecked(false);
    ui->selectRectangle->setChecked(false);
    ui->selectEllipse->setChecked(false);
    ui->selectCircle->setChecked(true);
    ui->selectText->setChecked(false);

    // Emit the "onSelection" signal
    onSelection(shapeTypeSelected);
}

void ShapeSelectMenu::on_selectText_clicked()
{
    shapeTypeSelected = jbrush::SelectableShapeType::TEXT;

    // Check line select and de-select everything else
    ui->selectLine->setChecked(false);
    ui->selectPolyline->setChecked(false);
    ui->selectPolygon->setChecked(false);
    ui->selectRectangle->setChecked(false);
    ui->selectEllipse->setChecked(false);
    ui->selectCircle->setChecked(false);
    ui->selectText->setChecked(true);

    // Emit the "onSelection" signal
    onSelection(shapeTypeSelected);
}
