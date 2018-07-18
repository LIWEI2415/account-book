#include "newloginindialog.h"
#include "ui_newloginindialog.h"
#include"loginindialog.h"
#include<QMessageBox>
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>


NewLogininDialog::NewLogininDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewLogininDialog)
{
    ui->setupUi(this);
}

NewLogininDialog::~NewLogininDialog()
{
    delete ui;
}

void NewLogininDialog::on_btnLogin_clicked()
{
    //执行相关sql语句
    QSqlQuery sql_query;
    //打开数据库的LOGIN表格
    sql_query.exec("SELECT * FROM LOGIN;");
    if(ui->usrLineEdit->text()==NULL)
        {
            QMessageBox::warning(NULL, "warning", "用户名不能为空");
            ui->textPassword->clear();
            ui->textPassword_2->clear();
            ui->usrLineEdit->setFocus();
        }
    else
        {
            int m=0;
            int id;
            while(sql_query.next())
                {
                    //sql_query.value(0)是userName的值，将其转换为字符型
                    id = sql_query.value(0).toInt();
                    QString username = sql_query.value(1).toString();
                    if(ui->usrLineEdit->text().trimmed() == username)
                    {
                        m=m+1;
                    }
                }
            if(m>0)
            {
                QMessageBox::warning(this, tr("警告！"), tr("用户名已注册！"),  QMessageBox::Yes);
                ui->usrLineEdit->clear();
            }
            else if(ui->textPassword->text()==NULL)
                    QMessageBox::warning(NULL, "warning", "密码不能为空");
            else if(ui->textPassword->text() ==  ui->textPassword_2->text()) {
                sql_query.last();
                id = sql_query.value(0).toInt();
                int i;
                i=id+1;
                  QString sqlStr = QString("INSERT INTO LOGIN(ID, USERNAME, USERPASSPORT) VALUES(%1, '%2', '%3');").arg(i).arg(ui->usrLineEdit->text()).arg(ui->textPassword->text());
                 //qDebug() << sqlStr;
                 sql_query.exec(sqlStr);
                 QMessageBox::warning(this, tr("恭喜！"), tr("注册成功！"),
                              QMessageBox::Yes);
                 LogininDialog a;
                 close();
                 a.exec();
             }
           else
           {
              QMessageBox::warning(this, tr("警告！"), tr("两次密码不一样！"), QMessageBox::Yes);
              // 清空内容并定位光标
              ui->textPassword->clear();
              ui->textPassword_2->clear();
              ui->textPassword->setFocus();
           }
        }
}

void NewLogininDialog::on_btnExit_clicked()
{
    accept();
}
