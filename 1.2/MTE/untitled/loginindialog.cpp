#include "loginindialog.h"
#include "ui_loginindialog.h"
#include<QMessageBox>
#include"newloginindialog.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>


LogininDialog::LogininDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogininDialog)
{
    ui->setupUi(this);
}

LogininDialog::~LogininDialog()
{
    delete ui;
}

void LogininDialog::on_btnLogin_clicked()
{
    //执行相关sql语句
    QSqlQuery sql_query;
    sql_query.exec("SELECT * FROM LOGIN;");
    //遍历数据库，如果和数据库中某个用户名、密码相同，则登入
    int m=0;
    while(sql_query.next())
        {
            //sql_query.value(0)是userName的值，将其转换为字符型
            int id = sql_query.value(0).toInt();
            QString username = sql_query.value(1).toString();
            QString userpassword = sql_query.value(2).toString();
            if(ui->usrLineEdit->text().trimmed() == username &&
                   ui->textPassword->text() == userpassword)
            {
                m=m+1;
            }
        }
    // 判断用户名和密码是否正确，
      // 如果错误则弹出警告对话框
    if(m>0)
    {
       this->hide();
       emit showmainwindow();
    }  else {
         QMessageBox::warning(this, tr("警告！"),
                     tr("用户名或密码错误！"),
                     QMessageBox::Yes);
         // 清空内容并定位光标
         ui->usrLineEdit->clear();
         ui->textPassword->clear();
         ui->usrLineEdit->setFocus();
      }
}

void LogininDialog::on_pushButton_clicked()
{
    NewLogininDialog a;
    a.exec();
}

void LogininDialog::receiveshow()
{
    this->show();
}
