#ifndef LOGGING_H
#define LOGGING_H

#include <QFrame>
#include <QSqlTableModel>
#include <mainwindow.h>
namespace Ui {
class Logging;
}

class Logging : public QFrame
{
    Q_OBJECT

public:
    explicit Logging(QWidget *parent = 0);
    ~Logging();

private slots:
    void on_pushButton_1_clicked();

private:
    QSqlTableModel *model;
    Ui::Logging *ui;
    MainWindow *mainWindow;
};

#endif // LOGGING_H
