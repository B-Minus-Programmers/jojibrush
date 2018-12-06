#pragma once
#include <QMap>
#include <QWidget>
#include <QPushButton>

namespace Ui {
    class ShapeSelectMenu;
}

namespace jbrush {

// Enum class contains shape types that can be selected and created by the administrator
enum class SelectableShapeType
{
    LINE,
    POLYLINE,
    POLYGON,
    RECTANGLE,
    ELLIPSE,
    CIRCLE,
    TEXT
};

namespace jconstants {
// Maps a selectable shape type with a descriptive string
const QMap<SelectableShapeType, QString> SELECTABLE_SHAPE_TYPE_MAP = {
    {SelectableShapeType::LINE, "Line"}, {SelectableShapeType::RECTANGLE, "Rectangle"},
    {SelectableShapeType::ELLIPSE, "Ellipse"}, {SelectableShapeType::TEXT, "Text"}
};
}// end jconstants
}// end jbrush

// Class composed by the MainWindow with methods and fields that
// enable the administrator edit the canvas rendering area by
// adding shapes, removing shapes, and moving shapes
class ShapeSelectMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ShapeSelectMenu(QWidget *parent = nullptr);

    // Get the current shape type selected
    jbrush::SelectableShapeType getShapeTypeSelected() { return shapeTypeSelected; }

    QPushButton *getSelectLineButton() const;
    QPushButton *getSelectPolylineButton() const;
    QPushButton *getSelectRectangleButton() const;
    QPushButton *getSelectEllipseButton() const;
    QPushButton *getSelectCircleButton() const;
    QPushButton *getSelectTextButton() const;

signals:
    void onSelection(jbrush::SelectableShapeType); // Signal emmits when any selection is made

private slots:
    void on_selectLine_clicked();

    void on_selectRectangle_clicked();

    void on_selectEllipse_clicked();

    void on_selectText_clicked();

    void on_selectPolyline_clicked();

    void on_selectCircle_clicked();

    void on_selectPolygon_clicked();

private:
    jbrush::SelectableShapeType shapeTypeSelected;  // Shape type currently selected to be drawn to the screen
    Ui::ShapeSelectMenu *ui;
};

