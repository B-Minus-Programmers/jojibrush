#pragma once
#include "shapes/Properties.hpp"
#include <QWidget>

namespace Ui {
    class GeometricPropertiesMenu;
}

class GeometricPropertiesMenu : public QWidget
{
    Q_OBJECT
public:
    explicit GeometricPropertiesMenu(QWidget *parent = nullptr);
    ~GeometricPropertiesMenu();

    // Return the properties currently set by user
    jbrush::GeometricShapeProperties getProperties() const;

signals:
    void onItemChanged(jbrush::GeometricShapeProperties);   // Signal emmited if any object changes

private slots:
    void on_penColorBox_currentTextChanged(const QString &arg1);

    void on_penWeightSlider_valueChanged(int value);

    void on_penStyleBox_currentTextChanged(const QString &arg1);

    void on_penCapBox_currentTextChanged(const QString &arg1);

    void on_penJoinBox_currentTextChanged(const QString &arg1);

private:
    jbrush::GeometricShapeProperties properties;    // Struct contains info on properties currently selected by the user
    Ui::GeometricPropertiesMenu *ui;    // Pointer to the ui form used to design this widget
};
