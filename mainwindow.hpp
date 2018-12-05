#pragma once
#include <QMainWindow>
#include "Canvas.hpp"
#include "AccountType.hpp"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setAccountType(jbrush::AccountType);

private slots:
    void on_actionLoad_triggered();

    void on_actionShape_Id_s_triggered();
    void on_actionShape_Area_s_triggered();
    void on_actionShape_Perimeters_triggered();
    void on_actionExport_triggered();


private:
    Ui::MainWindow *ui;
    QString currentFile;    // Directory of the file containing shapes currently loaded into the program
    jbrush::Canvas* canvas; // Points to the main canvas
};
