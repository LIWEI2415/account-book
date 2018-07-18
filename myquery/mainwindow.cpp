#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSqlQuery>
#include<QDebug>
#include<QSqlRecord>
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
    QSqlQuery query;
    int id=ui->spinBox->value();
    query.exec(QString("select name from student where id=%1")
               .arg(id));
    query.next();
    QString name=query.value(0).toString();
    qDebug()<<name;
}
