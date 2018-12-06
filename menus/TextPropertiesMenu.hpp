#pragma once

#include "shapes/Properties.hpp"
#include <QWidget>

namespace Ui {
    class TextPropertiesMenu;
}

class TextPropertiesMenu : public QWidget
{
    Q_OBJECT
public:
    explicit TextPropertiesMenu(QWidget *parent = nullptr);
    ~TextPropertiesMenu();

    // Get the properties currently selected by the user
    jbrush::TextShapeProperties getProperties() const;

signals:
    void onItemChanged(jbrush::TextShapeProperties);    // Emmitted whenever a selection is made on the menu

private slots:
    void on_textColorBox_currentTextChanged(const QString &arg1);

    void on_textAlignmentBox_currentTextChanged(const QString &arg1);

    void on_textSizeSlider_valueChanged(int value);

    void on_textFamilyEdit_textEdited(const QString &arg1);

    void on_textStyleBox_currentTextChanged(const QString &arg1);

    void on_textWeightBox_currentTextChanged(const QString &arg1);

private:
    jbrush::TextShapeProperties properties; // Holds the current values of the ui form
    Ui::TextPropertiesMenu *ui; // Pointer to the widget set up using a ui form
};
