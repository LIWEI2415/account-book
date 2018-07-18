#include "incomeclassificationdialog.h"
#include "ui_incomeclassificationdialog.h"
#include"addrecountdialog.h"
#include"pasterecorddialog.h"
#include"pasterecordgettingdialog.h"
#include"pasterecordusingdialog.h"
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
#include"chart_3_1dialog.h"

IncomeClassificationDialog::IncomeClassificationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncomeClassificationDialog)
{
    ui->setupUi(this);
    //执行相关sql语句
    QSqlQuery sql_query;
    sql_query.exec("SELECT * FROM PIN;");
    int Account1=0,Account2=0,Account3=0;
    sql_query.first();
    while(sql_query.next())
        {
            if(sql_query.value(1).toString()=="薪水津贴")    Account1=Account1+sql_query.value(6).toInt();
            else if(sql_query.value(1).toString()=="红包礼金")    Account2=Account2+sql_query.value(6).toInt();
            else if(sql_query.value(1).toString()=="生意买卖")    Account3=Account3+sql_query.value(6).toInt();
        }
     ui->tableWidget->setItem(0,1,new QTableWidgetItem (QString::number(Account1)));
     ui->tableWidget->setItem(1,1,new QTableWidgetItem (QString::number(Account2)));
     ui->tableWidget->setItem(2,1,new QTableWidgetItem (QString::number(Account3)));
}

IncomeClassificationDialog::~IncomeClassificationDialog()
{
    delete ui;
}

void IncomeClassificationDialog::on_ButtonNewAccount_clicked()
{
    emit sendsignal();
        this->close();
}

void IncomeClassificationDialog::on_ButtonFunctionOldthing_2_clicked()
{
    PasteRecordDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void IncomeClassificationDialog::on_pushButton_9_clicked()
{
    AddRecountDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void IncomeClassificationDialog::on_ButtonFunctionMessage_2_clicked()
{
    GiveUserMessageDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void IncomeClassificationDialog::on_pushButton_clicked()
{
    PasteRecordGettingDialog a;

    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void IncomeClassificationDialog::on_pushButton_3_clicked()
{
    PasteRecordUsingDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void IncomeClassificationDialog::on_pushButton_5_clicked()
{
    ExpenditureBreakdownDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void IncomeClassificationDialog::on_ButtonExit_2_clicked()
{
     qApp->quit();
}

void IncomeClassificationDialog::on_pushButton_2_clicked()
{
    chart_3Dialog b;
    b.exec();

}




void IncomeClassificationDialog::on_pushButton_7_clicked()
{
    chart_3_1Dialog a;
    a.exec();
}
