#include "mainwindow.h"

#include "ui_mainwindow.h"
#include"chart.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVector<double> x(101),y(101);
    for(int i=0;i<101;i++)
    {
        x[i]=i/5-10;
        y[i]=x[i]*x[i]*x[i];
    }
    ui->qCustomPlot->addGraph();
    ui->qCustomPlot->graph(0)->setData(x,y);
    ui->qCustomPlot->xAxis->setLabel("x");
    ui->qCustomPlot->yAxis->setLabel("y");
    ui->qCustomPlot->xAxis->setRange(-11,11);
    ui->qCustomPlot->yAxis->setRange(-1100,1100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    chart a;
    this->hide();
    a.show();
    a.exec();
    this->show();
}
