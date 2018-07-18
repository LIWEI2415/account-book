#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include<QSound>
#include <QIcon>

QSound * sound;
int change=0;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonNewAccount_clicked()
{
    AddRecountDialog a;
    this->hide();
    a.show();
    a.exec();
    this->show();
}

void MainWindow::on_pushButton_7_clicked()
{
    AddRecountDialog b;
    this->hide();
    b.show();
    b.exec();
    this->show();
}

void MainWindow::on_ButtonFunctionOldthing_clicked()
{
    PasteRecordDialog a;
    this->hide();
    a.show();
    a.exec();
    this->show();
}

void MainWindow::on_pushButton_clicked()
{
    PasteRecordGettingDialog a;

    this->hide();

    a.show();
    a.exec();
    this->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    PasteRecordUsingDialog a;
    this->hide();

    a.show();
    a.exec();
    this->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    IncomeClassificationDialog a;
    this->hide();

    a.show();
    a.exec();
    this->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    ExpenditureBreakdownDialog a;
    this->hide();

    a.show();
    a.exec();
    this->show();
}

void MainWindow::on_ButtonFunctionMessage_clicked()
{
    GiveUserMessageDialog a;
    this->hide();
    a.show();
    a.exec();
    this->show();
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    //执行相关sql语句
        QSqlQuery sql_query;
        int EX=0;
        int IN=0;
        int Year=ui->calendarWidget->selectedDate().year();
        int Month=ui->calendarWidget->selectedDate().month();
        int Day=ui->calendarWidget->selectedDate().day();
        sql_query.exec("SELECT * FROM PEX;");
        while(sql_query.next())
        {
        int Y1 = sql_query.value(2).toInt();
        int M1 = sql_query.value(3).toInt();
        int D1 = sql_query.value(4).toInt();
        if(Y1==Year && Month==M1 && Day==D1)
          {

            EX = EX+sql_query.value(6).toInt();
          }
        }
        ui->label_4->clear();
        ui->label_4->setText(QString::number(EX));
        sql_query.exec("SELECT * FROM PIN;");
        while(sql_query.next())
        {
        int Y2 = sql_query.value(2).toInt();
        int M2 = sql_query.value(3).toInt();
        int D2 = sql_query.value(4).toInt();
        if(Y2==Year && Month==M2 && Day==D2)
          {
            IN =IN+ sql_query.value(6).toInt();
          }
        }
        ui->label_6->clear();
        ui->label_6->setText(QString::number(IN));


}

void MainWindow::receivelogin()
{
    this->show();
}


void MainWindow::on_pushButton_10_clicked()
{
    this->hide();
    emit dlgshow();
}

void MainWindow::on_pushButton_6_clicked()
{

        if(change==1){sound->stop();}
        sound = new QSound("../../untitled/1.wav");
        sound->play();
        change=1;

}

void MainWindow::on_pushButton_11_clicked()
{
      if(change==1){sound->stop();}
       sound = new QSound("../../untitled/2.wav");
       sound->play();
       change=1;

}

void MainWindow::on_pushButton_9_clicked()
{
      if(change==1){sound->stop();}
        sound = new QSound("../../untitled/3.wav");
        sound->play();
        change=1;

}

void MainWindow::on_pushButton_12_clicked()
{
    sound->stop();

}

void MainWindow::on_pushButton_13_clicked()
{
    //隐藏主窗口
        this->hide();

        //新建QSystemTrayIcon对象
        mSysTrayIcon = new QSystemTrayIcon(this);
        //新建托盘要显示的icon
        QIcon icon = QIcon("../../untitled/myapp.ico");
        //将icon设到QSystemTrayIcon对象中
        mSysTrayIcon->setIcon(icon);
        //当鼠标移动到托盘上的图标时，会显示此处设置的内容
        mSysTrayIcon->setToolTip(QObject::trUtf8("随手记"));
        //给QSystemTrayIcon添加槽函数
        connect(mSysTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));

        //建立托盘操作的菜单
        createActions();
        createMenu();
        //在系统托盘显示此对象
        mSysTrayIcon->show();
}

void MainWindow::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason){
    case QSystemTrayIcon::Trigger:
        mSysTrayIcon->showMessage(QObject::trUtf8("Message Title"),
                                  QObject::trUtf8("欢迎使用此程序"),
                                  QSystemTrayIcon::Information,
                                  1000);
        break;
    case QSystemTrayIcon::DoubleClick:
        this->show();
        break;
    default:
        break;
    }
}

void MainWindow::createActions()
{
    mShowMainAction = new QAction(QObject::trUtf8("显示主界面"),this);
    connect(mShowMainAction,SIGNAL(triggered()),this,SLOT(on_showMainAction()));

    mExitAppAction = new QAction(QObject::trUtf8("退出"),this);
    connect(mExitAppAction,SIGNAL(triggered()),this,SLOT(on_exitAppAction()));

}

void MainWindow::createMenu()
{
    mMenu = new QMenu(this);
    mMenu->addAction(mShowMainAction);

    mMenu->addSeparator();

    mMenu->addAction(mExitAppAction);

    mSysTrayIcon->setContextMenu(mMenu);
}

void MainWindow::on_showMainAction()
{
    this->show();
    mSysTrayIcon->hide();
}

void MainWindow::on_exitAppAction()
{
    exit(0);
}
