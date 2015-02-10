#-------------------------------------------------
#
# Project created by QtCreator 2015-02-04T19:10:17
#
#-------------------------------------------------

QT       += core gui

TARGET = InterfaceBuilder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    abstractwidget.cpp \
    psdparser.cpp \
    imagerecognizer.cpp

HEADERS  += mainwindow.h \
    abstractwidget.h \
    psdparser.h \
    imagerecognizer.h

FORMS    += mainwindow.ui

CONFIG += uitools

INCLUDEPATH += C:\\opencv\\build\\include
LIBS += -LC:\\opencv-mingw\\bin
LIBS += -lopencv_core249 -lopencv_highgui249 -lopencv_imgproc249
