#include "TextPropertiesMenu.hpp"
#include "utils/FileHandler.hpp"
#include "ui_textpropsmenu.h"

TextPropertiesMenu::TextPropertiesMenu(QWidget *parent) :
    QWidget(parent), ui(new Ui::TextPropertiesMenu)
{
    ui->setupUi(this);

    // Set properties based on current values set in the ui
    properties.textColor = jbrush::jconstants::COLOR_MAP[ui->textColorBox->currentText()];
    properties.textAlignment = jbrush::jconstants::TEXT_ALIGN_MAP[ui->textAlignmentBox->currentText()];
    properties.textSize = int8_t(ui->textSizeSlider->value());
    properties.textFontFamily = ui->textFamilyEdit->text();
    properties.textFontStyle = jbrush::jconstants::TEXT_STYLE_MAP[ui->textStyleBox->currentText()];
    properties.textFontWeight = jbrush::jconstants::TEXT_WEIGHT_MAP[ui->textWeightBox->currentText()];
}

TextPropertiesMenu::~TextPropertiesMenu()
{
    delete ui;
}

jbrush::TextShapeProperties TextPropertiesMenu::getProperties() const
{
    return properties;
}

void TextPropertiesMenu::on_textColorBox_currentTextChanged(const QString &arg1)
{
    properties.textColor = jbrush::jconstants::COLOR_MAP[arg1];
    onItemChanged(properties);
}

void TextPropertiesMenu::on_textAlignmentBox_currentTextChanged(const QString &arg1)
{
    properties.textAlignment = jbrush::jconstants::TEXT_ALIGN_MAP[arg1];
    onItemChanged(properties);
}

void TextPropertiesMenu::on_textSizeSlider_valueChanged(int value)
{
    properties.textSize = int8_t(value);
    onItemChanged(properties);
}

void TextPropertiesMenu::on_textFamilyEdit_textEdited(const QString &arg1)
{
    properties.textFontFamily = arg1;
    onItemChanged(properties);
}

void TextPropertiesMenu::on_textStyleBox_currentTextChanged(const QString &arg1)
{
    properties.textFontStyle = jbrush::jconstants::TEXT_STYLE_MAP[arg1];
    onItemChanged(properties);
}

void TextPropertiesMenu::on_textWeightBox_currentTextChanged(const QString &arg1)
{
    properties.textFontWeight = jbrush::jconstants::TEXT_WEIGHT_MAP[arg1];
    onItemChanged(properties);
}
