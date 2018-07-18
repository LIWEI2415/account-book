#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"chartdialog.h"
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
   chartDialog a;
   this->hide();
   a.show();
   a.exec();
   this->show();
}
