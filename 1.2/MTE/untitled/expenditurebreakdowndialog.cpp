#include "expenditurebreakdowndialog.h"
#include "ui_expenditurebreakdowndialog.h"
#include"addrecountdialog.h"
#include"pasterecorddialog.h"
#include"pasterecordgettingdialog.h"
#include"pasterecordusingdialog.h"
#include"incomeclassificationdialog.h"
#include"giveusermessagedialog.h"
#include"chart_1dialog.h"
#include"chart_2dialog.h"
#include"chart_3dialog.h"
#include"chart_4dialog.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>
#include"chart_4_1dialog.h"

ExpenditureBreakdownDialog::ExpenditureBreakdownDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExpenditureBreakdownDialog)
{
    ui->setupUi(this);
    //执行相关sql语句
    QSqlQuery sql_query;
    sql_query.exec("SELECT * FROM PEX;");
    int Account1=0,Account2=0,Account3=0,Account4=0,Account5=0,Account6=0,Account7=0,Account8=0,Account9=0;
    sql_query.first();
    while(sql_query.next())
        {
            if(sql_query.value(1).toString()=="餐饮食品")    Account1=Account1+sql_query.value(6).toInt();
            else if(sql_query.value(1).toString()=="服装鞋帽")    Account2=Account2+sql_query.value(6).toInt();
            else if(sql_query.value(1).toString()=="日常居家")    Account3=Account3+sql_query.value(6).toInt();
            else if(sql_query.value(1).toString()=="交通出行")    Account4=Account4+sql_query.value(6).toInt();
            else if(sql_query.value(1).toString()=="休闲娱乐")    Account5=Account5+sql_query.value(6).toInt();
            else if(sql_query.value(1).toString()=="文化教育")    Account6=Account6+sql_query.value(6).toInt();
            else if(sql_query.value(1).toString()=="人情交际")    Account7=Account7+sql_query.value(6).toInt();
            else if(sql_query.value(1).toString()=="医疗保健")    Account8=Account8+sql_query.value(6).toInt();
            else if(sql_query.value(1).toString()=="投资理财")    Account9=Account9+sql_query.value(6).toInt();
        }
     ui->tableWidget->setItem(0,1,new QTableWidgetItem (QString::number(Account1)));
     ui->tableWidget->setItem(1,1,new QTableWidgetItem (QString::number(Account2)));
     ui->tableWidget->setItem(2,1,new QTableWidgetItem (QString::number(Account3)));
     ui->tableWidget->setItem(3,1,new QTableWidgetItem (QString::number(Account4)));
     ui->tableWidget->setItem(4,1,new QTableWidgetItem (QString::number(Account5)));
     ui->tableWidget->setItem(5,1,new QTableWidgetItem (QString::number(Account6)));
     ui->tableWidget->setItem(6,1,new QTableWidgetItem (QString::number(Account7)));
     ui->tableWidget->setItem(7,1,new QTableWidgetItem (QString::number(Account8)));
     ui->tableWidget->setItem(8,1,new QTableWidgetItem (QString::number(Account9)));
}

ExpenditureBreakdownDialog::~ExpenditureBreakdownDialog()
{
    delete ui;
}

void ExpenditureBreakdownDialog::on_ButtonNewAccount_clicked()
{
    emit sendsignal();
        this->close();
}

void ExpenditureBreakdownDialog::on_ButtonFunctionOldthing_clicked()
{
    PasteRecordDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void ExpenditureBreakdownDialog::on_pushButton_7_clicked()
{
    AddRecountDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void ExpenditureBreakdownDialog::on_ButtonFunctionMessage_clicked()
{
    GiveUserMessageDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void ExpenditureBreakdownDialog::on_pushButton_clicked()
{
    PasteRecordGettingDialog a;
    chart_1Dialog b;

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void ExpenditureBreakdownDialog::on_pushButton_3_clicked()
{
    PasteRecordUsingDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void ExpenditureBreakdownDialog::on_pushButton_4_clicked()
{
    IncomeClassificationDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void ExpenditureBreakdownDialog::on_ButtonExit_clicked()
{
    qApp->quit();
}

void ExpenditureBreakdownDialog::on_pushButton_6_clicked()
{
    chart_4Dialog b;
    b.exec();

}



void ExpenditureBreakdownDialog::on_pushButton_9_clicked()
{
    chart_4_1Dialog a;
    a.exec();
}
