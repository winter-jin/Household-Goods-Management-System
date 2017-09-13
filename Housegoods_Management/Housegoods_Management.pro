#-------------------------------------------------
#
# Project created by QtCreator 2017-09-06T22:17:44
#
#-------------------------------------------------

QT       += core gui
QT       += sql

include(QZXing/QZXing.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Housegoods_Management
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        mainwindow.cpp \
    logging.cpp \
    main.cpp \
    qr.cpp

HEADERS += \
        mainwindow.h \
    connection.h \
    logging.h \
    qr.h \
    control.h

FORMS += \
        mainwindow.ui \
    logging.ui \
    qr.ui
