#include "pasterecordusingdialog.h"
#include "ui_pasterecordusingdialog.h"
#include"addrecountdialog.h"
#include"pasterecorddialog.h"
#include"pasterecordgettingdialog.h"
#include"incomeclassificationdialog.h"
#include"expenditurebreakdowndialog.h"
#include"giveusermessagedialog.h"
#include"chart_1dialog.h"
#include"chart_2dialog.h"
#include"chart_3dialog.h"
#include"chart_4dialog.h"
#include"chart_2_1dialog.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>


PasteRecordUsingDialog::PasteRecordUsingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasteRecordUsingDialog)
{
    ui->setupUi(this);
    //执行相关sql语句
    QSqlQuery sql_query;
    sql_query.exec("SELECT * FROM PEX;");
    int Year=2018,Month=1;
    int line=0,Account;
    while(Month<7)
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
        ui->tableWidget->setItem(line,0,new QTableWidgetItem (QString::number(Account)));
        line=line+1;
        Month=Month+1;
    }
    if(line==6) line=0;
    while(Month<13 && Month>6)
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
        ui->tableWidget_2->setItem(line,0,new QTableWidgetItem (QString::number(Account)));
        line=line+1;
        Month=Month+1;
    }
}

PasteRecordUsingDialog::~PasteRecordUsingDialog()
{
    delete ui;
}

void PasteRecordUsingDialog::on_ButtonNewAccount_clicked()
{
    emit sendsignal();
        this->close();
}

void PasteRecordUsingDialog::on_ButtonFunctionOldthing_clicked()
{
    PasteRecordDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void PasteRecordUsingDialog::on_pushButton_7_clicked()
{
    AddRecountDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void PasteRecordUsingDialog::on_ButtonFunctionMessage_clicked()
{
    GiveUserMessageDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void PasteRecordUsingDialog::on_pushButton_clicked()
{
    PasteRecordGettingDialog a;

    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void PasteRecordUsingDialog::on_pushButton_4_clicked()
{
    IncomeClassificationDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void PasteRecordUsingDialog::on_pushButton_5_clicked()
{
    ExpenditureBreakdownDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void PasteRecordUsingDialog::on_ButtonExit_clicked()
{
     qApp->quit();
}

void PasteRecordUsingDialog::on_pushButton_6_clicked()
{
    chart_2Dialog b;
    b.exec();

}



void PasteRecordUsingDialog::on_pushButton_9_clicked()
{
    chart_2_1Dialog a;
    a.exec();
}
