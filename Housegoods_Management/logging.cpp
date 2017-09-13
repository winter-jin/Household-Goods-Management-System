#include "logging.h"
#include "ui_logging.h"
#include "connection.h"

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
    //int flag =0
    QString name = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString sql = "SELECT * FROM users WHERE user_name='" + name + "'";
    QSqlQuery query(sql);
    while (query.next())
    {
        qDebug() << QString("Id:, Username: %1, Password: %2")
                        .arg(query.value("user_name").toString())
                        .arg(query.value("user_password").toString());
        QString na = query.value(1).toString();
        qDebug()<<na;
        qDebug()<<password;
        if(na==password)
        {
            mainWindow->show();
            this->hide();
        }
    }
}
