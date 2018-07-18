#include "zhucejiemian.h"
#include "ui_zhucejiemian.h"

zhucejiemian::zhucejiemian(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zhucejiemian)
{
    ui->setupUi(this);
}

zhucejiemian::~zhucejiemian()
{
    delete ui;
}
