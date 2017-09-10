#include "camaraget.h"
#include "ui_camaraget.h"

camaraGet::camaraGet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::camaraGet)
{
    ui->setupUi(this);

    cam     = NULL;
    timer   = new QTimer(this);
    imag    = new QImage();         // 初始化

    /*信号和槽*/
    connect(timer, SIGNAL(timeout()), this, SLOT(readFarme()));  // 时间到，读取当前摄像头信息
    connect(ui->open, SIGNAL(clicked()), this, SLOT(openCamara()));
    connect(ui->pic, SIGNAL(clicked()), this, SLOT(takingPictures()));
    connect(ui->closeCam, SIGNAL(clicked()), this, SLOT(closeCamara()));
}

/******************************
********* 打开摄像头 ***********
*******************************/
void camaraGet::openCamara()
{
    cam = cvCreateCameraCapture(0);//打开摄像头，从摄像头中获取视频

    timer->start(33);              // 开始计时，超时则发出timeout()信号
}

/*********************************
********* 读取摄像头信息 ***********
**********************************/
void camaraGet::readFarme()
{
    frame = cvQueryFrame(cam);// 从摄像头中抓取并返回每一帧
    // 将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。
    QImage image((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label上
}

/*************************
********* 拍照 ***********
**************************/
void camaraGet::takingPictures()
{
    frame = cvQueryFrame(cam);// 从摄像头中抓取并返回每一帧

    // 将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。
    QImage image((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888);

    ui->label_2->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label上
}

/*******************************
***关闭摄像头，释放资源，必须释放***
********************************/
void camaraGet::closeCamara()
{
    timer->stop();         // 停止读取数据。

    cvReleaseCapture(&cam);//释放内存；
}

camaraGet::~camaraGet()
{
    delete ui;
}
