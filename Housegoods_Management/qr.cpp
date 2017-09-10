#include "qr.h"
#include "ui_qr.h"
#include <QZXing.h>

QR::QR(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::QR)
{
    ui->setupUi(this);
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
    qDebug()<< result;
}
