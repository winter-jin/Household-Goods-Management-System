#pragma once
#ifndef QR_H
#define QR_H

#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QtSql>
#include <QSqlQuery>
#include <QMainWindow>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include <qtimer>
#include <QImage>
#include <QPixmap>


#include <QMainWindow>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QFileDialog>

using namespace cv;

namespace Ui {
class QR;
}

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;

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
    void captureImage();
    void displayImage(int,QImage);
    void saveImage();

public:
    explicit QR(QWidget *parent = 0);
    ~QR();

private:
    Ui::QR *ui;
    QSqlTableModel *model;

    QCamera *camera;
    QCameraViewfinder *viewfinder;
    QCameraImageCapture *imageCapture;
};

#endif // QR_H
