#ifndef CONNECTION_H
#define CONNECTION_H

#include <QApplication>
#include <QDialog>
#include <QSqlDatabase>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <QtSql>
#include <QSqlQuery>
#include <QTableView>
#include "mainwindow.h"
#include <QHBoxLayout>


static bool createConnection()
{
    /*QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    //QString dsn = QString::fromLocal8Bit("test");
    db.setDatabaseName("A");
    if(!db.open()) return false;
    QSqlQuery query;
    query.exec("create table student (id int primary key, name vchar)");
    query.exec("insert into student values (0,'刘明')");
    query.exec("insert into student values (1,'陈刚')");
    query.exec("insert into student values (2,'王红')");
    return true;*/

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    qDebug()<<"ODBC driver?"<<db.isValid();
    QString dsn = QString::fromLocal8Bit("test");
    db.setHostName("Alienware");
    db.setDatabaseName(dsn);
    db.setUserName("Jin");
    db.setPassword("qwer1234");
    if(!db.open())
    {
        qDebug()<<db.lastError().text();
        QMessageBox::critical(0, QObject::tr("Database error"), db.lastError().text());
        return false;
    }
    else
        qDebug()<<"database open success!";

    return true;
}

#endif // CONNECTION_H
