#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable("student");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select(); //选取整个表的所有行

    //不显示name属性列,如果这时添加记录，则该属性的值添加不上
    // model->removeColumn(1);

    ui->tableView->setModel(model);

    //使其不可编辑
    // ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_1_clicked()
{
    QString name = ui->lineEdit->text();
    model->setTable(name);   //重新关联表
    model->select();   //这样才能再次显示整个表的内容
}

void MainWindow::on_pushButton_2_clicked()
{
    QString name = ui->lineEdit->text();
    //根据姓名进行筛选
    model->setFilter(QString("name = '%1'").arg(name));
    //显示结果
    model->select();
}

