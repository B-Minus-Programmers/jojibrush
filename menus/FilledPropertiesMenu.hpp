#pragma once
#include "shapes/Properties.hpp"
#include <QWidget>

namespace Ui {
    class FilledPropertiesMenu;
}

class FilledPropertiesMenu : public QWidget
{
    Q_OBJECT
public:
    explicit FilledPropertiesMenu(QWidget *parent = nullptr);
    ~FilledPropertiesMenu();

    // Getters return local properties
    Qt::GlobalColor getBrushColor() const;
    Qt::BrushStyle getBrushStyle() const;

signals:
    void onItemChanged(Qt::GlobalColor, Qt::BrushStyle);   // Emmitted when any item is changed

private slots:
    void on_fillColorBox_currentTextChanged(const QString &arg1);

    void on_fillPatternBox_currentTextChanged(const QString &arg1);

private:
    Qt::GlobalColor brushColor; // Colored used to fill in the shape
    Qt::BrushStyle brushStyle;  // Style of fill for the shape
    Ui::FilledPropertiesMenu *ui;   // Pointer to the ui form used to set up this widget
};
