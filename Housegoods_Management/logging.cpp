#include "logging.h"
#include "ui_logging.h"

Logging::Logging(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Logging)
{
    ui->setupUi(this);
    mainWindow = new MainWindow;
    model = new QSqlTableModel(this);
    model->setTable("student");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select(); //选取整个表的所有行

    //不显示name属性列,如果这时添加记录，则该属性的值添加不上
    // model->removeColumn(1);

    //ui->tableView->setModel(model);

    //使其不可编辑
    // ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Logging::~Logging()
{
    delete ui;
}

void Logging::on_pushButton_1_clicked()
{
    QString name = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    model->setTable("users");   //重新关联表
    model->setFilter(QString("user_name ='%1' and user_password = '%2'").arg(name).arg(password));
    if(model)
    {
        mainWindow->show();
        this->hide();
    }
}
