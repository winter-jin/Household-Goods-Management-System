#include "qr.h"
#include "ui_qr.h"
#include <QZXing.h>
#include <mainwindow.h>

QR::QR(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::QR)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    camera = new QCamera(this);
    viewfinder=new QCameraViewfinder(this);
    imageCapture=new QCameraImageCapture(camera);
    //mainWindow = new MainWindow;
    model->setTable("student");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select(); //选取整个表的所有行
    ui->tableView->setModel(model);
    ui->ImageView->addWidget(viewfinder);
    ui->ImageCapture->setScaledContents(true);
    camera->setViewfinder(viewfinder);
    camera->start();
    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(displayImage(int,QImage)));
    connect(ui->buttonCapture, SIGNAL(clicked()), this, SLOT(captureImage()));
    connect(ui->buttonSave, SIGNAL(clicked()), this, SLOT(saveImage()));
    //connect(ui->buttonQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

QR::~QR()
{
    delete ui;
}


void QR::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    QImage imageToDecode(name);
    QZXing decoder;
    enum DecoderFormat {
        DecoderFormat_None = 0,
        DecoderFormat_Aztec = 1 << 1,
        DecoderFormat_CODABAR = 1 << 2,
        DecoderFormat_CODE_39 = 1 << 3,
        DecoderFormat_CODE_93 = 1 << 4,
        DecoderFormat_CODE_128 = 1 << 5,
        DecoderFormat_DATA_MATRIX = 1 << 6,
        DecoderFormat_EAN_8 = 1 << 7,
        DecoderFormat_EAN_13 = 1 << 8,
        DecoderFormat_ITF = 1 << 9,
        DecoderFormat_MAXICODE = 1 << 10,
        DecoderFormat_PDF_417 = 1 << 11,
        DecoderFormat_QR_CODE = 1 << 12,
        DecoderFormat_RSS_14 = 1 << 13,
        DecoderFormat_RSS_EXPANDED = 1 << 14,
        DecoderFormat_UPC_A = 1 << 15,
        DecoderFormat_UPC_E = 1 << 16,
        DecoderFormat_UPC_EAN_EXTENSION = 1 << 17,
        DecoderFormat_CODE_128_GS1 = 1 << 18
    } ;
    decoder.setDecoder( DecoderFormat_QR_CODE | DecoderFormat_EAN_13 );
    QString result = decoder.decodeImage(imageToDecode);
    ui->textEdit->setText(result);
    qDebug()<< result;
}

void QR::on_pushButton_2_clicked()
{
    model->setTable("goods");   //重新关联表
    model->select();   //这样才能再次显示整个表的内容
    int rowNum = model->rowCount(); //获得表的行数
    model->insertRow(rowNum); //添加一行
}

void QR::on_pushButton_3_clicked()
{
    //获取选中的行
    int curRow = ui->tableView->currentIndex().row();
    //删除该行
    model->removeRow(curRow);
    int ok = QMessageBox::warning(this,tr("删除当前行!"),
                                  tr("你确定删除当前行吗？"),
                                  QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No)
    {
        model->revertAll(); //如果不删除，则撤销
    }
    else model->submitAll(); //否则提交，在数据库中删除该行
}

void QR::on_pushButton_4_clicked()
{
    model->database().transaction(); //开始事务操作
    if (model->submitAll()) {
        model->database().commit(); //提交
    } else {
        model->database().rollback(); //回滚
        QMessageBox::warning(this, tr("tableModel"),
                             tr("数据库错误: %1")
                             .arg(model->lastError().text()));
    }
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
}

void QR::on_pushButton_5_clicked()
{
    model->setTable("goods");   //重新关联表
    model->select();   //这样才能再次显示整个表的内容
}

void QR::on_pushButton_6_clicked()
{
    class MainWindow *mainWindow2;
    mainWindow2 = new MainWindow;
    mainWindow2->show();
    this->hide();
}

void QR::captureImage()
{
    //ui->statusBar->showMessage(tr("capturing..."), 1000);
    imageCapture->capture();
    //ui->ImageView->setPixmap(imageCapture);
}

void QR::displayImage(int , QImage image)
{
    ui->ImageCapture->setPixmap(QPixmap::fromImage(image));
    //ui->statusBar->showMessage(tr("capture OK!"), 5000);
}

void QR::saveImage()
{
QString fileName=QFileDialog::getSaveFileName(this, tr("save file"), QDir::homePath(), tr("jpegfile(*.jpg)"));
if(fileName.isEmpty()) {
//ui->statusBar->showMessage(tr("save cancel"), 5000);
return;
}
const QPixmap* pixmap=ui->ImageCapture->pixmap();
if(pixmap) {
pixmap->save(fileName);
//ui->statusBar->showMessage(tr("save OK"), 5000);
}
}
