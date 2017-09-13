#pragma once
#ifndef QR_H
#define QR_H

#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QtSql>
#include <QSqlQuery>

namespace Ui {
class QR;
}

class QR : public QFrame
{
    Q_OBJECT

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

public:
    explicit QR(QWidget *parent = 0);
    ~QR();

private:
    Ui::QR *ui;
    QSqlTableModel *model;
};

#endif // QR_H
