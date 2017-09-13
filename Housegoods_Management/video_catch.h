#ifndef VIDEO_CATCH_H
#define VIDEO_CATCH_H

#include <opencv2/opencv.hpp>
#include <QFrame>

namespace Ui {
class video_catch;
}

class video_catch : public QFrame
{
    Q_OBJECT

public:
    explicit video_catch(QWidget *parent = 0);
    ~video_catch();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::video_catch *ui;
};

#endif // VIDEO_CATCH_H
