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

private:
    Ui::MainWindow *ui;
    QString currentFile;    // Directory of the file containing shapes currently loaded into the program
    jbrush::Canvas* canvas; // Points to the main canvas
};
