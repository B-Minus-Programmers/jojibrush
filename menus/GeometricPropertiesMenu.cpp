#include "GeometricPropertiesMenu.hpp"
#include "utils/FileHandler.hpp"
#include "ui_geopropsmenu.h"

GeometricPropertiesMenu::GeometricPropertiesMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GeometricPropertiesMenu)
{
    ui->setupUi(this);

    // Set properties according to whatever values are currently set in the ui
    properties.penWidth = uint8_t(ui->penWeightSlider->value());
    properties.penColor = jbrush::jconstants::COLOR_MAP[ui->penColorBox->currentText()];
    properties.penStyle = jbrush::jconstants::PEN_STYLE_MAP[ui->penStyleBox->currentText()];
    properties.penCapStyle = jbrush::jconstants::PEN_CAP_MAP[ui->penCapBox->currentText()];
    properties.penJoinStyle = jbrush::jconstants::PEN_JOIN_MAP[ui->penJoinBox->currentText()];
}

GeometricPropertiesMenu::~GeometricPropertiesMenu()
{
    delete ui;
}

jbrush::GeometricShapeProperties GeometricPropertiesMenu::getProperties() const
{
    return properties;
}

void GeometricPropertiesMenu::on_penWeightSlider_valueChanged(int value)
{
    properties.penWidth = uint8_t(value);
    onItemChanged(properties);
}

void GeometricPropertiesMenu::on_penColorBox_currentTextChanged(const QString &arg1)
{
    properties.penColor = jbrush::jconstants::COLOR_MAP[arg1];
    onItemChanged(properties);
}

void GeometricPropertiesMenu::on_penStyleBox_currentTextChanged(const QString &arg1)
{
    properties.penStyle = jbrush::jconstants::PEN_STYLE_MAP[arg1];
    onItemChanged(properties);
}

void GeometricPropertiesMenu::on_penCapBox_currentTextChanged(const QString &arg1)
{
    properties.penCapStyle = jbrush::jconstants::PEN_CAP_MAP[arg1];
    onItemChanged(properties);
}

void GeometricPropertiesMenu::on_penJoinBox_currentTextChanged(const QString &arg1)
{
    properties.penJoinStyle = jbrush::jconstants::PEN_JOIN_MAP[arg1];
    onItemChanged(properties);
}
