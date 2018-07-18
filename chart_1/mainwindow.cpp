#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"chart_1dialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    chart_1Dialog a;
    this->hide();
    a.show();
    a.exec();
    this->show();
}
