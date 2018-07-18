#include "mainwindow.h"
#include <QApplication>
#include"loginindialog.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>
#include"quanjubianliang.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //创建一个SQLite数据库连接
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../../untitled/data.db");
    //打开数据库
    if(!db.open()) return false;

    MainWindow w;
    LogininDialog dlg;
    dlg.show();
    //信号与槽之间关联
    QObject::connect(&dlg,SIGNAL(showmainwindow()),&w,SLOT(receivelogin()));
    QObject::connect(&w,SIGNAL(dlgshow()),&dlg,SLOT(receiveshow()));
    return a.exec();
}
