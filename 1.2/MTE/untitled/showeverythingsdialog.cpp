#include "showeverythingsdialog.h"
#include "ui_showeverythingsdialog.h"
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
#include <QMessageBox>
#include<QDate>

extern int QuanJuBianLiangnumberone;
extern int QuanJuBianLiangnumberyear;
extern int QuanJuBianLiangnumbermonth;
extern int QuanJuBianLiangnumberday;
extern QDate QuanJuBianLiangriqi;
int QuanJuBianLiangnumbertwo=0;

ShowEveryThingsDialog::ShowEveryThingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowEveryThingsDialog)
{
     ui->setupUi(this);


    //执行相关sql语句
    QSqlQuery sql_query;

    //打开表格PEX,PIN
    int NowNumber=0,Y1,M1,D1;
    sql_query.exec("SELECT * FROM PEX;");
    sql_query.first();
    while(sql_query.next())
    {
         Y1 = sql_query.value(2).toInt();
         M1 = sql_query.value(3).toInt();
         D1 = sql_query.value(4).toInt();
        if(Y1==QuanJuBianLiangnumberyear && QuanJuBianLiangnumbermonth==M1 && QuanJuBianLiangnumberday==D1)
        {
            if(NowNumber==QuanJuBianLiangnumberone)
            {
                ui->lineEditOutlayMainClass_3->setCurrentText(sql_query.value(1).toString());
                ui->dateEdit_5->setDate(QuanJuBianLiangriqi);
           //    ui->dateEdit_5->dateTime().date().month()=QuanJuBianLiangnumbermonth;
           //     ui->dateEdit_5->dateTime().date().day()=QuanJuBianLiangnumberday;
                ui->lineEditOutlayAccountOwner_3->setCurrentText(sql_query.value(5).toString());
                ui->lineEditTradeAmount_3->setText(sql_query.value(6).toString());
                ui->lineEdit->setText(sql_query.value(7).toString());
                }
            NowNumber=NowNumber+1;
            QuanJuBianLiangnumbertwo=1;
          }
    }
    sql_query.exec("SELECT * FROM PIN;");
    sql_query.first();
    while(sql_query.next())
    {
         Y1 = sql_query.value(2).toInt();
         M1 = sql_query.value(3).toInt();
         D1 = sql_query.value(4).toInt();
        if(Y1==QuanJuBianLiangnumberyear && QuanJuBianLiangnumbermonth==M1 && QuanJuBianLiangnumberday==D1)
        {
            if(NowNumber==QuanJuBianLiangnumberone)
            {
                ui->lineEditIncomeSubClass_3->setCurrentText(sql_query.value(1).toString());
                ui->dateEdit_6->setDate(QuanJuBianLiangriqi);
                ui->lineEditIncomeAccountOwner_3->setCurrentText(sql_query.value(5).toString());
                ui->lineEditTradeAmount2_3->setText(sql_query.value(6).toString());
                ui->lineEdit_2->setText(sql_query.value(7).toString());
                }
            NowNumber=NowNumber+1;
        QuanJuBianLiangnumbertwo=0;
          }
    }

}

ShowEveryThingsDialog::~ShowEveryThingsDialog()
{
    delete ui;
}

void ShowEveryThingsDialog::on_ComeBackMain_clicked()
{
    emit sendsignal();
        this->close();
}

void ShowEveryThingsDialog::on_pushButton_clicked()
{
    PasteRecordGettingDialog a;

    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void ShowEveryThingsDialog::on_pushButton_3_clicked()
{
    PasteRecordUsingDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void ShowEveryThingsDialog::on_pushButton_4_clicked()
{
    IncomeClassificationDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void ShowEveryThingsDialog::on_pushButton_5_clicked()
{
    ExpenditureBreakdownDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void ShowEveryThingsDialog::on_ButtonFunctionOldthing_clicked()
{
    PasteRecordDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void ShowEveryThingsDialog::on_pushButton_7_clicked()
{
    AddRecountDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void ShowEveryThingsDialog::on_ButtonFunctionMessage_clicked()
{
    GiveUserMessageDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void ShowEveryThingsDialog::on_ButtonExit_clicked()
{
     qApp->quit();
}

void ShowEveryThingsDialog::on_btnEditAccounter_3_clicked()
{
    //执行相关sql语句
        QSqlQuery sql_query;
        //打开表格PEX,PIN
        int EX;
        int id3;
        int IN;
        int id4;
        int Year1=ui->dateEdit_5->dateTime().date().year();
        int Month1=ui->dateEdit_5->dateTime().date().month();
        int Day1=ui->dateEdit_5->dateTime().date().day();
        int Year2=ui->dateEdit_6->dateTime().date().year();
        int Month2=ui->dateEdit_6->dateTime().date().month();
        int Day2=ui->dateEdit_6->dateTime().date().day();
        //更改支出数据
        if(QuanJuBianLiangnumbertwo==1)
        {
        sql_query.exec("SELECT * FROM PEX;");
        QString a,b,c;
        while(sql_query.next())
        {
            int Y1 = sql_query.value(2).toInt();
            int M1 = sql_query.value(3).toInt();
            int D1 = sql_query.value(4).toInt();
            if(Y1==Year1 && Month1==M1 && Day1==D1)
            {
                id3=sql_query.value(0).toInt()+QuanJuBianLiangnumberone;
                EX=ui->lineEditTradeAmount_3->text().toInt();
                a=ui->lineEditOutlayMainClass_3->currentText();
                b=ui->lineEditOutlayAccountOwner_3->currentText();
                c=ui->lineEdit->text();
                break;
            }
        }
        QString sqlStr3 = QString("UPDATE PEX SET EXPENSES=%1,TYPE='%2',MOOD='%3',REMARK='%4' WHERE ID=%5;")
                .arg(EX)
                .arg(a)
                .arg(b)
                .arg(c)
                .arg(id3);
        sql_query.exec(sqlStr3);
        }

        else{
        //更改收入数据
        sql_query.exec("SELECT * FROM PIN;");
        QString x,y,z;
        while(sql_query.next())
        {
            int Y2 = sql_query.value(2).toInt();
            int M2 = sql_query.value(3).toInt();
            int D2 = sql_query.value(4).toInt();
            if(Y2==Year2 && Month2==M2 && Day2==D2)
            {
                id4=sql_query.value(0).toInt();
                x=ui->lineEditIncomeSubClass_3->currentText();
                y=ui->lineEditIncomeAccountOwner_3->currentText();
                z=ui->lineEdit_2->text();
                IN=ui->lineEditTradeAmount2_3->text().toInt();
                break;
            }
        }
        QString sqlStr4 = QString("UPDATE PIN SET INCOME=%1,TYPE='%2',MOOD='%3',REMARK='%4' WHERE ID=%2;")
                .arg(IN)
                .arg(x)
                .arg(y)
                .arg(z)
                .arg(id4);
        sql_query.exec(sqlStr4);
        }
        QMessageBox::about(this,tr("提示信息"),tr("修改成功"));
}

void ShowEveryThingsDialog::on_btnCancle_3_clicked()
{
    //执行相关sql语句
        QSqlQuery sql_query;
        //打开表格PEX,PIN
        int id5;//用来记录被删除的那一行支出数据的id
        int id6;//用来记录被删除的支出数据以下的数据id
        int id7;//用来记录被删除的那一行收入的数据的id
        int id8;//用来记录被删除的收入数据以下的数据id
        //以下分别表示支出、收入的年月日
        int Year1=ui->dateEdit_5->dateTime().date().year();
        int Month1=ui->dateEdit_5->dateTime().date().month();
        int Day1=ui->dateEdit_5->dateTime().date().day();
        int Year2=ui->dateEdit_6->dateTime().date().year();
        int Month2=ui->dateEdit_6->dateTime().date().month();
        int Day2=ui->dateEdit_6->dateTime().date().day();
        if(QuanJuBianLiangnumbertwo==1)
        {
        //删除支出数据
        sql_query.exec("SELECT * FROM PEX;");
        while(sql_query.next())
        {
            //以下分别表示PEX数据库表中的年月日
            int Y1 = sql_query.value(2).toInt();
            int M1 = sql_query.value(3).toInt();
            int D1 = sql_query.value(4).toInt();
            if(Y1==Year1 && Month1==M1 && Day1==D1)
            {
                id5=sql_query.value(0).toInt()+QuanJuBianLiangnumberone;
                QString sqlStr5 = QString("DELETE FROM PEX WHERE ID=%1;")
                        .arg(id5);
                sql_query.exec(sqlStr5);
                while(sql_query.next())
                {
                    id6=sql_query.value(0).toInt();
                    QString sqlStr6 = QString("UPDATE PEX SET ID=%1 WHERE ID=%2;")
                            .arg(id5)
                            .arg(id6);
                    sql_query.exec(sqlStr6);
                    id5=id6;
                }
                break;
            }
        }
        }

        else{
        //删除收入数据
        sql_query.exec("SELECT * FROM PIN;");
        while(sql_query.next())
        {
            //以下分别表示PIN数据库表中年月日
            int Y2 = sql_query.value(2).toInt();
            int M2 = sql_query.value(3).toInt();
            int D2 = sql_query.value(4).toInt();
            if(Y2==Year2 && Month2==M2 && Day2==D2)
            {
                id7=sql_query.value(0).toInt()+QuanJuBianLiangnumberone;
                QString sqlStr7 = QString("DELETE FROM PIN WHERE ID=%1;")
                        .arg(id7);
                sql_query.exec(sqlStr7);
                while(sql_query.next())
                {
                    id8=sql_query.value(0).toInt();
                    QString sqlStr8 = QString("UPDATE PIN SET ID=%1 WHERE ID=%2;")
                            .arg(id7)
                            .arg(id8);
                    sql_query.exec(sqlStr8);
                    id7=id8;
                }
                break;
            }
        }
        }
        QMessageBox::about(this,tr("提示信息"),tr("删除成功"));
}
