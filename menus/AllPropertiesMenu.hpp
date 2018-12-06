#pragma once

#include "GeometricPropertiesMenu.hpp"
#include "FilledPropertiesMenu.hpp"

#include <QWidget>

namespace Ui {
    class AllPropertiesMenu;
}

// Conatins composes both filled properties and geometric properties windows
class AllPropertiesMenu : public QWidget
{
    Q_OBJECT

public:
    explicit AllPropertiesMenu(QWidget *parent = nullptr);
    ~AllPropertiesMenu();

    // Display or hide the menu with the filled properties
    void displayFilledPropertiesMenu(bool);

    // Get constant pointers to either menu in the full properties menu
    const GeometricPropertiesMenu* getGeometricPropertiesMenu() const;
    const FilledPropertiesMenu* getFilledPropertiesMenu() const;

private:
    Ui::AllPropertiesMenu *ui; // Pointer to the ui-form used to design the layout of the widget
    GeometricPropertiesMenu *geoPropsMenu;   // Menu used for selecting properties of a geometric shape, i.e. the properties of the shape's stroke
    FilledPropertiesMenu *filledPropsMenu;  // Menu used for selecting fill properties of a shape
};
