#include "pasterecorddialog.h"
#include "ui_pasterecorddialog.h"
#include"addrecountdialog.h"
#include"giveusermessagedialog.h"
#include"pasterecordgettingdialog.h"
#include"pasterecordusingdialog.h"
#include"incomeclassificationdialog.h"
#include"expenditurebreakdowndialog.h"
#include"sickeverydaydialog.h"
#include"chart_1dialog.h"
#include"chart_2dialog.h"
#include"chart_3dialog.h"
#include"chart_4dialog.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>

PasteRecordDialog::PasteRecordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasteRecordDialog)
{
    ui->setupUi(this);

    //执行相关sql语句
    QSqlQuery sql_query;
    sql_query.exec("SELECT * FROM PEX;");
    int Year=2018,Month=1;
    int line=0,Account;
    while(Month<5)
    {
        Account=0;
        sql_query.first();
        while(sql_query.next())
        {
        int Y1 = sql_query.value(2).toInt();
        int M1 = sql_query.value(3).toInt();
        if(Y1==Year && Month==M1)
          {
             Account=Account+sql_query.value(6).toInt();
          }
        }
        ui->tableWidget->setItem(0,line,new QTableWidgetItem (QString::number(Account)));
        line=line+1;
        Month=Month+1;
    }
    line=0;
    while(Month<9 && Month>4)
    {
        Account=0;
        sql_query.first();
        while(sql_query.next())
        {
        int Y1 = sql_query.value(2).toInt();
        int M1 = sql_query.value(3).toInt();
        if(Y1==Year && Month==M1)
          {
             Account=Account+sql_query.value(6).toInt();
          }
        }
        ui->tableWidget_2->setItem(0,line,new QTableWidgetItem (QString::number(Account)));
        line=line+1;
        Month=Month+1;
    }
    line=0;
    while(Month<13 && Month>8)
    {
        Account=0;
        sql_query.first();
        while(sql_query.next())
        {
        int Y1 = sql_query.value(2).toInt();
        int M1 = sql_query.value(3).toInt();
        if(Y1==Year && Month==M1)
          {
             Account=Account+sql_query.value(6).toInt();
          }
        }
        ui->tableWidget_3->setItem(0,line,new QTableWidgetItem (QString::number(Account)));
        line=line+1;
        Month=Month+1;
    }

    sql_query.exec("SELECT * FROM PIN;");
    Month=1;
    line=0;
    while(Month<5)
    {
        Account=0;
        sql_query.first();
        while(sql_query.next())
        {
        int Y1 = sql_query.value(2).toInt();
        int M1 = sql_query.value(3).toInt();
        if(Y1==Year && Month==M1)
          {
             Account=Account+sql_query.value(6).toInt();
          }
        }
        ui->tableWidget->setItem(1,line,new QTableWidgetItem (QString::number(Account)));
        line=line+1;
        Month=Month+1;
    }
    line=0;
    while(Month<9 && Month>4)
    {
        Account=0;
        sql_query.first();
        while(sql_query.next())
        {
        int Y1 = sql_query.value(2).toInt();
        int M1 = sql_query.value(3).toInt();
        if(Y1==Year && Month==M1)
          {
             Account=Account+sql_query.value(6).toInt();
          }
        }
        ui->tableWidget_2->setItem(1,line,new QTableWidgetItem (QString::number(Account)));
        line=line+1;
        Month=Month+1;
    }
    line=0;
    while(Month<13 && Month>8)
    {
        Account=0;
        sql_query.first();
        while(sql_query.next())
        {
        int Y1 = sql_query.value(2).toInt();
        int M1 = sql_query.value(3).toInt();
        if(Y1==Year && Month==M1)
          {
             Account=Account+sql_query.value(6).toInt();
          }
        }
        ui->tableWidget_3->setItem(1,line,new QTableWidgetItem (QString::number(Account)));
        line=line+1;
        Month=Month+1;
    }

}

PasteRecordDialog::~PasteRecordDialog()
{
    delete ui;
}

void PasteRecordDialog::on_ButtonNewAccount_clicked()
{
    emit sendsignal();
        this->close();
}

void PasteRecordDialog::on_pushButton_7_clicked()
{
    AddRecountDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void PasteRecordDialog::on_ButtonFunctionMessage_clicked()
{
    GiveUserMessageDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void PasteRecordDialog::on_pushButton_clicked()
{
    PasteRecordGettingDialog a;

    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void PasteRecordDialog::on_pushButton_3_clicked()
{
    PasteRecordUsingDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void PasteRecordDialog::on_pushButton_4_clicked()
{
    IncomeClassificationDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void PasteRecordDialog::on_pushButton_5_clicked()
{
    ExpenditureBreakdownDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void PasteRecordDialog::on_pushButton_6_clicked()
{
    SickEveryDayDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void PasteRecordDialog::on_ButtonExit_clicked()
{
     qApp->quit();
}
