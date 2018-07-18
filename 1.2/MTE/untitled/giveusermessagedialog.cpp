#include "giveusermessagedialog.h"
#include "ui_giveusermessagedialog.h"
#include"addrecountdialog.h"
#include"pasterecorddialog.h"
#include"pasterecordgettingdialog.h"
#include"pasterecordusingdialog.h"
#include"incomeclassificationdialog.h"
#include"expenditurebreakdowndialog.h"
#include"chart_1dialog.h"
#include"chart_2dialog.h"
#include"chart_3dialog.h"
#include"chart_4dialog.h"
#include<QMessageBox>
#include<QFile>
#include<QTextStream>

 //int QuanJuBianLiangmeiriyusuan;
 //int QuanJuBianLiangmeiyueyusuan;



GiveUserMessageDialog::GiveUserMessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GiveUserMessageDialog)
{
    ui->setupUi(this);
}

GiveUserMessageDialog::~GiveUserMessageDialog()
{
    delete ui;
}

void GiveUserMessageDialog::on_ButtonNewAccount_clicked()
{
    emit sendsignal();
        this->close();
}

void GiveUserMessageDialog::on_ButtonFunctionOldthing_clicked()
{
    PasteRecordDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void GiveUserMessageDialog::on_pushButton_7_clicked()
{
    AddRecountDialog a;
    this->hide();
    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void GiveUserMessageDialog::on_pushButton_clicked()
{
    PasteRecordGettingDialog a;

    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void GiveUserMessageDialog::on_pushButton_3_clicked()
{
    PasteRecordUsingDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void GiveUserMessageDialog::on_pushButton_4_clicked()
{
    IncomeClassificationDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void GiveUserMessageDialog::on_pushButton_5_clicked()
{
    ExpenditureBreakdownDialog a;
    this->hide();

    a.show();
    connect(&a,SIGNAL(sendsignal()),this,SLOT(receivelogin()));//当点击子界面时，调用主界面的reshow()函数
    a.exec();
}

void GiveUserMessageDialog::on_ButtonExit_clicked()
{
     qApp->quit();
}

void GiveUserMessageDialog::on_pushButton_6_clicked()
{

    QFile f("date1.txt");
    if(!f.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("error"),tr("read file date1.txt error:1%").arg(f.errorString()));
        return ;
    }
    QTextStream txtOutput(&f);
    QString s1=ui->lineEdit->text();
    txtOutput << s1 ;
    f.close();

    QFile f2("date2.txt");
    if(!f2.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("error"),tr("read file date2.txt error:1%").arg(f.errorString()));
        return ;
    }
    QTextStream txtOutput2(&f2);
    QString s2=ui->lineEdit_2->text();

    txtOutput2 << s2 ;
    f2.close();

    QMessageBox::about(this,tr("提示"),tr("修改成功"));
}
