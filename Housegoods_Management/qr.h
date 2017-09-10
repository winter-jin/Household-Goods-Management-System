#ifndef QR_H
#define QR_H

#include <QFrame>

namespace Ui {
class QR;
}

class QR : public QFrame
{
    Q_OBJECT

private slots:
    void on_pushButton_clicked();

public:
    explicit QR(QWidget *parent = 0);
    ~QR();

private:
    Ui::QR *ui;
};

#endif // QR_H
