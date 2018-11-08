#-------------------------------------------------
#
# Project created by QtCreator 2018-11-07T13:03:24
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtXmlProcessing
TEMPLATE = app
CCFLAG += -std=c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    xmlfilereader.cpp \
    widgetdataitem.cpp \
    widgetitemmodel.cpp

HEADERS  += mainwindow.h \
    xmlfilereader.h \
    widgetdataitem.h \
    widgetitemmodel.h

FORMS    += mainwindow.ui
