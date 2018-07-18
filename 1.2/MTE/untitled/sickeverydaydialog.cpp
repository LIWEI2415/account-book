#include "sickeverydaydialog.h"
#include "ui_sickeverydaydialog.h"
#include"showeverythingsdialog.h"
#include"addrecountdialog.h"
#include"pasterecorddialog.h"
#include"pasterecordgettingdialog.h"
#include"pasterecordusingdialog.h"
#include"incomeclassificationdialog.h"
#include"expenditurebreakdowndialog.h"
#include"giveusermessagedialog.h"
#include"chart_1dialog.h"
#include"chart_2dialog.h"
#include"chart_3dialog.h"
#include"chart_4dialog.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>

int QuanJuBianLiangnumberone;
int QuanJuBianLiangnumberyear;
int QuanJuBianLiangnumbermonth;
int QuanJuBianLiangnumberday;
QDate QuanJuBianLiangriqi;



SickEveryDayDialog::SickEveryDayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SickEveryDayDialog)
{
    ui->setupUi(this);
    ui->dateEdit_2->setDate(QDate::currentDate());

    //a = new ShowEveryThingsDialog(this);
}

SickEveryDayDialog::~SickEveryDayDialog()
{
    delete ui;
}

void SickEveryDayDialog::on_ButtonNewAccount_clicked()
{
    emit sendsignal();
        this->close();
}

void SickEveryDayDialog::on_tableWidget_cellClicked(int row, int column)
{
    QuanJuBianLiangnumberone=row;
  //  qDebug() << QuanJuBianLiangnumberone;
    QuanJuBianLiangriqi=ui->dateEdit_2->date();

    QuanJuBianLiangnumberyear=ui->dateEdit_2->date().year();
  //   qDebug() << QuanJuBianLiangnumberyear;

    QuanJuBianLiangnumbermonth=ui->dateEdit_2->date().month();
  //   qDebug() << QuanJuBianLiangnumbermonth;

    QuanJuBianLiangnumberday=ui->dateEdit_2->date().day();
  //   qDebug() << QuanJuBianLiangnumberday;

    //a->getData();

    //this->hide();
    ShowEveryThingsDialog a;
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void SickEveryDayDialog::on_pushButton_clicked()
{
    PasteRecordGettingDialog a;

    this->hide();

    //a.show();
    //connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void SickEveryDayDialog::on_pushButton_3_clicked()
{
    PasteRecordUsingDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void SickEveryDayDialog::on_pushButton_4_clicked()
{
    IncomeClassificationDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void SickEveryDayDialog::on_pushButton_5_clicked()
{
    ExpenditureBreakdownDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void SickEveryDayDialog::on_ButtonFunctionOldthing_clicked()
{
    PasteRecordDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void SickEveryDayDialog::on_pushButton_7_clicked()
{
    AddRecountDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void SickEveryDayDialog::on_ButtonFunctionMessage_clicked()
{
    GiveUserMessageDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void SickEveryDayDialog::on_pushButton_6_clicked()
{
    //执行相关sql语句
    QSqlQuery sql_query;
    sql_query.exec("SELECT * FROM PEX;");
    ui->tableWidget->clearContents();
  //  ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    int Year=ui->dateEdit_2->dateTime().date().year();
    int Month=ui->dateEdit_2->dateTime().date().month();
    int Day=ui->dateEdit_2->dateTime().date().day();
    sql_query.first();
    int money,line=0;
    while(sql_query.next())
    {

    int Y1 = sql_query.value(2).toInt();
    int M1 = sql_query.value(3).toInt();
    int D1 = sql_query.value(4).toInt();
    if(Y1==Year && Month==M1 && Day==D1)
      {

         line=line+1;
    }}
     sql_query.exec("SELECT * FROM PIN;");
    sql_query.first();
    while(sql_query.next())
    {
    int Y1 = sql_query.value(2).toInt();
    int M1 = sql_query.value(3).toInt();
    int D1 = sql_query.value(4).toInt();
    if(Y1==Year && Month==M1 && Day==D1)
      {
         line=line+1;

      }
    }
    ui->tableWidget->setRowCount(line);


     Year=ui->dateEdit_2->dateTime().date().year();
     Month=ui->dateEdit_2->dateTime().date().month();
     Day=ui->dateEdit_2->dateTime().date().day();
    sql_query.first();
     line=0;
    while(sql_query.next())
    {

    int Y1 = sql_query.value(2).toInt();
    int M1 = sql_query.value(3).toInt();
    int D1 = sql_query.value(4).toInt();
    if(Y1==Year && Month==M1 && Day==D1)
      {
         money=sql_query.value(6).toInt();
         ui->tableWidget->setItem(line,0,new QTableWidgetItem (QString::number(money)));
         ui->tableWidget->setItem(line,1,new QTableWidgetItem (QString( sql_query.value(5).toString())));
         ui->tableWidget->setItem(line,2,new QTableWidgetItem (QString( sql_query.value(1).toString())));
         ui->tableWidget->setItem(line,3,new QTableWidgetItem (QString( sql_query.value(7).toString())));
         ui->tableWidget->setItem(line,4,new QTableWidgetItem ("支出"));
         line=line+1;
      //   if(line>4)   ui->tableWidget->setRowCount(line);
      }
    }
     sql_query.exec("SELECT * FROM PIN;");
    sql_query.first();
    while(sql_query.next())
    {
    int Y1 = sql_query.value(2).toInt();
    int M1 = sql_query.value(3).toInt();
    int D1 = sql_query.value(4).toInt();
    if(Y1==Year && Month==M1 && Day==D1)
      {
         money=sql_query.value(6).toInt();
         ui->tableWidget->setItem(line,0,new QTableWidgetItem (QString::number(money)));
         ui->tableWidget->setItem(line,1,new QTableWidgetItem (QString( sql_query.value(5).toString())));
         ui->tableWidget->setItem(line,2,new QTableWidgetItem (QString( sql_query.value(1).toString())));
         ui->tableWidget->setItem(line,3,new QTableWidgetItem (QString( sql_query.value(7).toString())));
         ui->tableWidget->setItem(line,4,new QTableWidgetItem ("收入"));
         line=line+1;
      //   if(line>4)   ui->tableWidget->setRowCount(line);
      }
    }
}

void SickEveryDayDialog::on_ButtonExit_clicked()
{
     qApp->quit();
}
