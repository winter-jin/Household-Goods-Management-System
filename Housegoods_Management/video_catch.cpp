#include "video_catch.h"
#include "ui_video_catch.h"

video_catch::video_catch(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::video_catch)
{
    ui->setupUi(this);
}

video_catch::~video_catch()
{
    delete ui;
}

void video_catch::on_pushButton_clicked()
{
    if (capture.isOpened())
        capture.release();     //decide if capture is already opened; if so,close it
    QString filename =QFileDialog::getOpenFileName(this,tr("Open Video File"),".",tr("Video Files(*.avi *.mp4 *.flv *.mkv)"));
    capture.open(filename.toLocal8Bit().data());
    if (capture.isOpened())
    {
        rate= capture.get(CV_CAP_PROP_FPS);
        capture >> frame;
        if (!frame.empty())
        {

            image = Mat2QImage(frame);
            ui->label->setPixmap(QPixmap::fromImage(image));
            timer = new QTimer(this);
            timer->setInterval(1000/rate);   //set timer match with FPS
            connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
            timer->start();
        }
    }
}

//open camera
void video_catch::on_pushButton_2_clicked()
{
    if (capture.isOpened())
        capture.release();     //decide if capture is already opened; if so,close it
    capture.open(0);           //open the default camera
    if (capture.isOpened())
    {
        rate= capture.get(CV_CAP_PROP_FPS);
        capture >> frame;
        if (!frame.empty())
        {

            image = Mat2QImage(frame);
            ui->label->setPixmap(QPixmap::fromImage(image));
            timer = new QTimer(this);
            timer->setInterval(1000/rate);   //set timer match with FPS
            connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
            timer->start();
        }
    }
}
