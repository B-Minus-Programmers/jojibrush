#include "FilledPropertiesMenu.hpp"
#include "utils/FileHandler.hpp"
#include "ui_filledpropsmenu.h"

FilledPropertiesMenu::FilledPropertiesMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilledPropertiesMenu)
{
    ui->setupUi(this);

    // Set properties according to current values set in the ui
    brushColor = jbrush::jconstants::COLOR_MAP[ui->fillColorBox->currentText()];
    brushStyle = jbrush::jconstants::BRUSH_STYLE_MAP[ui->fillPatternBox->currentText()];
}

FilledPropertiesMenu::~FilledPropertiesMenu()
{
    delete ui;
}

Qt::GlobalColor FilledPropertiesMenu::getBrushColor() const
{
    return brushColor;
}

Qt::BrushStyle FilledPropertiesMenu::getBrushStyle() const
{
    return brushStyle;
}

void FilledPropertiesMenu::on_fillColorBox_currentTextChanged(const QString &arg1)
{
    brushColor = jbrush::jconstants::COLOR_MAP[arg1];
    onItemChanged(brushColor, brushStyle);
}

void FilledPropertiesMenu::on_fillPatternBox_currentTextChanged(const QString &arg1)
{
    brushStyle = jbrush::jconstants::BRUSH_STYLE_MAP[arg1];
    onItemChanged(brushColor, brushStyle);
}
