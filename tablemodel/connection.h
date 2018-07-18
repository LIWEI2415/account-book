#ifndef CONNECTION_H
#define CONNECTION_H

#include<QSqlDatabase>
#include<QSqlQuery>
static bool createConnection()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    if(!db.open())return false;
    QSqlQuery query;
    query.exec("create table student(id int primary key,name vchar");
    query.exec("insert into student value(0,'李明')");
    query.exec("insert into student value(1,'刘强')");
    query.exec("insert into student value(2,'王红')");
    return true;
}
#endif // CONNECTION_H
