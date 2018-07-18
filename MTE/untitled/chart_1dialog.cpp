#include "chart_1dialog.h"
#include "ui_chart_1dialog.h"

chart_1Dialog::chart_1Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chart_1Dialog)
{
    ui->setupUi(this);
}

chart_1Dialog::~chart_1Dialog()
{
    delete ui;
}
