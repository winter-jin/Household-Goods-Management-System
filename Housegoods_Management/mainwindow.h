#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qr.h"
#include <QApplication>
#include <QDialog>
#include <QSqlDatabase>
#include <QStringList>
#include <QDebug>
#include <QMessageBox>
#include <QtSql>
#include <QSqlQuery>
#include <QTableView>
#include <QHBoxLayout>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    QR *qr;
    QSqlTableModel *model;
};

#endif // MAINWINDOW_H
