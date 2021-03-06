#-------------------------------------------------
#
# Project created by QtCreator 2013-10-24T13:50:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WikiParser
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
        mainwindow.cpp \
    datagenerator.cpp \
    controller.cpp \
    resultwriter.cpp \
    filereader.cpp

HEADERS  += mainwindow.h \
    datagenerator.h \
    worker_thread.h \
    controller.h \
    resultwriter.h \
    filereader.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
