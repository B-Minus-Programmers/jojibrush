#pragma once
#include "Canvas.hpp"
#include "AccountType.hpp"
#include "AboutUs.hpp"
#include "menus/shapeselectmenu.hpp"
#include "menus/AllPropertiesMenu.hpp"
#include "menus/TextPropertiesMenu.hpp"
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Set the account type on the canvas
    void setAccountType(jbrush::AccountType);

private slots:
    void on_actionLoad_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_actionShow_Shape_IDs_toggled(bool);

    void on_actionShape_Id_s_triggered();
    void on_actionShape_Area_s_triggered();
    void on_actionShape_Perimeters_triggered();
    void on_actionExport_triggered();

    void on_actionAbout_Us_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile;    // Directory of the file containing shapes currently loaded into the program
    jbrush::Canvas* canvas; // Points to the main canvas
    AboutUs about;

    ShapeSelectMenu *shapeSelectMenu; // Menu widget enables selection of the shape type the admin will add to the canvas
    AllPropertiesMenu *shapePropertiesMenu; // Menu used to allow the user to select properties of the shape to be added to the canvas
    TextPropertiesMenu *textPropertiesMenu; // Menu used to set the properties of a text shape object

    // Setup the menus and widgets in the window
    void setupMenusAndWidgets();

    // Connect signals and slots across widgets that don't know about each other
    void connectSignalsAndSlots();

    // Display the correct set of selectable properties depending on the shape type selected to add
    void updatePropertiesMenus();
};
