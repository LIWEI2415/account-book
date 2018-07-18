#include "chart.h"
#include "ui_chart.h"
#include<

chart::chart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chart)
{
    ui->setupUi(this);
    QVector<Q
}

chart::~chart()
{
    delete ui;
}
