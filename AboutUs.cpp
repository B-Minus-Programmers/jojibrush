#include "AboutUs.hpp"
#include "ui_aboutus.h"

AboutUs::AboutUs() :
    QDialog(nullptr),
    ui(new Ui::AboutUs)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
}

AboutUs::~AboutUs()
{
    delete ui;
}
