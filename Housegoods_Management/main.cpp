#include "mainwindow.h"
#include "logging.h"
#include <QApplication>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!createConnection())
        return 1;

    Logging

    MainWindow w;
    w.show();

    return a.exec();
}
