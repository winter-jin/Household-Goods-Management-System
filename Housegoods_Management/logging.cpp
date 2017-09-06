#include "logging.h"
#include "ui_logging.h"

Logging::Logging(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Logging)
{
    ui->setupUi(this);
}

Logging::~Logging()
{
    delete ui;
}
