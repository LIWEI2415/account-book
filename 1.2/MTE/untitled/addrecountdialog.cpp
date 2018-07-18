#include "addrecountdialog.h"
#include "ui_addrecountdialog.h"
#include"pasterecorddialog.h"
#include"giveusermessagedialog.h"
#include"pasterecordgettingdialog.h"
#include"pasterecordusingdialog.h"
#include"incomeclassificationdialog.h"
#include"expenditurebreakdowndialog.h"
#include"chart_1dialog.h"
#include"chart_2dialog.h"
#include"chart_3dialog.h"
#include"chart_4dialog.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>
#include<QFile>
#include <QMessageBox>
#include<QTextStream>

//extern int QuanJuBianLiangmeiriyusuan;
//extern int QuanJuBianLiangmeiyueyusuan;

AddRecountDialog::AddRecountDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRecountDialog)
{
    ui->setupUi(this);
    ui->dateEdit_5->setDate(QDate::currentDate());
    ui->dateEdit_6->setDate(QDate::currentDate());
}

AddRecountDialog::~AddRecountDialog()
{
    delete ui;
}

void AddRecountDialog::on_ComeBackMain_clicked()
{
    emit sendsignal();
        this->close();
}

void AddRecountDialog::on_ButtonFunctionOldthing_clicked()
{
    PasteRecordDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void AddRecountDialog::on_ButtonFunctionMessage_clicked()
{
    GiveUserMessageDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void AddRecountDialog::on_pushButton_clicked()
{
    PasteRecordGettingDialog a;
  //  chart_1Dialog b;
    this->hide();
 //   b.exec();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void AddRecountDialog::on_pushButton_3_clicked()
{
    PasteRecordUsingDialog a;
    this->hide();
 //   chart_2Dialog b;
  //  b.exec();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void AddRecountDialog::on_pushButton_4_clicked()
{
    IncomeClassificationDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void AddRecountDialog::on_pushButton_5_clicked()
{
    ExpenditureBreakdownDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void AddRecountDialog::on_btnSaveQuit_3_clicked()
{
    //执行相关sql语句
        QSqlQuery sql_query;
        int ThisStuation=0;
        if(ui->lineEditTradeAmount_3->text()!=NULL)
     {   sql_query.exec("SELECT * FROM PEX;");
        int i;
        sql_query.last();
        int id1 = sql_query.value(0).toInt();
        i=id1+1;
        //增加一组支出的数据
        QString sqlStr1 = QString("INSERT INTO PEX(ID,TYPE,YEAR,MONTH,DAY,MOOD,EXPENSES,REMARK) VALUES(%1,'%2',%3,%4,%5,'%6',%7,'%8');")
                .arg(i)
                .arg(ui->lineEditOutlayMainClass_3->currentText())
                .arg(ui->dateEdit_5->dateTime().date().year())
                .arg(ui->dateEdit_5->dateTime().date().month())
                .arg(ui->dateEdit_5->dateTime().date().day())
                .arg(ui->lineEditOutlayAccountOwner_3->currentText())
                .arg(ui->lineEditTradeAmount_3->text())
                .arg(ui->lineEdit->text());
       sql_query.exec(sqlStr1);
       QMessageBox::about(this,tr("提示信息"),tr("保存支出成功"));
       ThisStuation=1;

       sql_query.exec("SELECT * FROM PEX;");
       int Year,Month,Day;
       Year=ui->dateEdit_5->dateTime().date().year();
       Month=ui->dateEdit_5->dateTime().date().month();
       Day=ui->dateEdit_5->dateTime().date().day();
       int Account1=0,Account2=0;
           while(sql_query.next())
           {
           int Y1 = sql_query.value(2).toInt();
           int M1 = sql_query.value(3).toInt();
           int D1 = sql_query.value(4).toInt();
           if(Y1==Year && Month==M1)
             {
                Account1=Account1+sql_query.value(6).toInt();
                if(D1==Day) Account2=Account2+sql_query.value(6).toInt();
             }
           }

           QFile f("date1.txt");
           if(!f.open(QFile::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,tr("error"),tr("read file date1.txt error:1%").arg(f.errorString()));
               return ;
           }
           QTextStream txtOutput(&f);
           QString s1;
           txtOutput >>s1;
           f.close();

           QFile f2("date2.txt");
           if(!f2.open(QFile::ReadOnly | QFile::Text))
           {
               QMessageBox::warning(this,tr("error"),tr("read file date2.txt error:1%").arg(f.errorString()));
               return ;
           }
           QTextStream txtOutput2(&f2);
           QString s2;
           txtOutput2 >>s2;
           f2.close();


           if(Account2>=s1.toInt())   QMessageBox::about(this,tr("警告"),tr("日支出超支"));
        if(Account1>=s2.toInt())   QMessageBox::about(this,tr("警告"),tr("月支出超支"));
      }
       if(ui->lineEditTradeAmount2_3->text()!=NULL)
     {  sql_query.exec("SELECT * FROM PIN;");
       int m;
       sql_query.last();
       int id2 = sql_query.value(0).toInt();
       m=id2+1;
       //增加一组收入的数据
       QString sqlStr2 = QString("INSERT INTO PIN(ID,TYPE,YEAR,MONTH,DAY,MOOD,INCOME,REMARK) VALUES(%1,'%2',%3,%4,%5,'%6',%7,'%8');")
               .arg(m)
               .arg(ui->lineEditIncomeMainClass_3->currentText())
               .arg(ui->dateEdit_6->dateTime().date().year())
               .arg(ui->dateEdit_6->dateTime().date().month())
               .arg(ui->dateEdit_6->dateTime().date().day())
               .arg(ui->lineEditIncomeAccountOwner_3->currentText())
               .arg(ui->lineEditTradeAmount2_3->text())
               .arg(ui->lineEdit_2->text());
        sql_query.exec(sqlStr2);
        QMessageBox::about(this,tr("提示信息"),tr("收入保存成功"));
        ThisStuation=1;
   }
    if(ThisStuation==0)   QMessageBox::about(this,tr("提示信息"),tr("请输入数据"));




}

void AddRecountDialog::on_ButtonExit_clicked()
{
    qApp->quit();
}
