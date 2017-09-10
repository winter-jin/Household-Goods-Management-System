#include "widget.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("登录界面"));
    userNameLabel = new QLabel(tr("用户名："));
    passWordLabel = new QLabel(tr("密  码："));
    userNameLineEdit = new QLineEdit;
    passWordLineEdit = new QLineEdit;
    passWordLineEdit->setEchoMode(QLineEdit::Password);
    login = new QPushButton(tr("登录"));
    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(userNameLabel,0,0);
    mainLayout->addWidget(passWordLabel,1,0);
    mainLayout->addWidget(userNameLineEdit,0,1);
    mainLayout->addWidget(passWordLineEdit,1,1);

    QHBoxLayout *hBoxLayout = new QHBoxLayout;
    mainLayout->addLayout(hBoxLayout,2,0,1,2);
    hBoxLayout->addStretch();
    hBoxLayout->addWidget(login);
    connect(login,SIGNAL(clicked()),this,SLOT(slotLogin()));
    connect(passWordLineEdit,SIGNAL(returnPressed()),this,SLOT(slotLogin()));

}


Widget::~Widget()
{
      delete ui;
}
//MainWindow m;
void Widget::slotLogin(){
     qDebug() << "输入用户名：" << userNameLineEdit->text();       //输出调试信息
     qDebug() << "输入密码：" << passWordLineEdit->text();
     if (userNameLineEdit->text().operator ==("user") && passWordLineEdit->text().operator ==("1234567890"))
    {
          qDebug() << "登录成功！";
          QMessageBox::information(this,tr("登录提示"),tr("登录成功"));
          //m.show();
         // this->hide();
        //  emit showmain();

     }
     else
     {
          qDebug() << "用户名或密码错误！";
          QMessageBox::information(this,tr("登录提示"),tr("用户名或密码错误！"));

     }
}
