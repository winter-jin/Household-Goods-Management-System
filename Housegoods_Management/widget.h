#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
     QLabel *userNameLabel;
     QLabel *passWordLabel;
     QLineEdit *userNameLineEdit;
     QLineEdit *passWordLineEdit;
     QPushButton *login;
private slots:
     void slotLogin();

//signals:
    //void showmain();  //显示主界面

//private:
  //  Ui::widget *ui;
//};

#endif // WIDGET_H
