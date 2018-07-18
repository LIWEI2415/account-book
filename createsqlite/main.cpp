#include "mainwindow.h"
#include <QApplication>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlError>
#include<QtSql/QSqlQuery>
#include<QDebug>
#include<QtSql>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );//第二个参数可以设置连接名字，这里为default

      db.setDatabaseName( "./testdatabase.db" );// 设置数据库名与路径, 此时是放在上一个目录
      //打开连接
      if( !db.open() )
      {
        qDebug() << db.lastError();
        qFatal( "Failed to connect." );
      }

      qDebug( "Connected!" );
      //各种操作
      QSqlQuery qry;
      else
        qDebug() << "Table created!";
        //删
      qry.prepare( "DELETE FROM names WHERE id = 6" );
        if( !qry.exec() )
          qDebug() << qry.lastError();
        else
          qDebug( "Deleted!" );

        qry.prepare( "DELETE FROM names WHERE firstname = 'Ralph'" );
        if( !qry.exec() )
          qDebug() << qry.lastError();
        else
          qDebug( "Deleted!" );

      db.close();


    return a.exec();
}
