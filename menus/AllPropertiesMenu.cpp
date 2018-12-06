#include "AllPropertiesMenu.hpp"
#include "ui_allpropsmenu.h"

AllPropertiesMenu::AllPropertiesMenu(QWidget *parent) :
    QWidget(parent), ui(new Ui::AllPropertiesMenu),
    geoPropsMenu(new GeometricPropertiesMenu), filledPropsMenu(new FilledPropertiesMenu)
{
    ui->setupUi(this);
    geoPropsMenu->setParent(ui->geometricPropertiesMenu);
    filledPropsMenu->setParent(ui->filledPropertiesMenu);
}

AllPropertiesMenu::~AllPropertiesMenu()
{
    delete ui;
    delete geoPropsMenu;
    delete filledPropsMenu;
}

void AllPropertiesMenu::displayFilledPropertiesMenu(bool display)
{
    if(display)
    {
        ui->filledPropertiesMenu->show();
    }
    else
    {
        ui->filledPropertiesMenu->hide();
    }
}

const GeometricPropertiesMenu *AllPropertiesMenu::getGeometricPropertiesMenu() const
{
    return geoPropsMenu;
}

const FilledPropertiesMenu *AllPropertiesMenu::getFilledPropertiesMenu() const
{
    return filledPropsMenu;
}
