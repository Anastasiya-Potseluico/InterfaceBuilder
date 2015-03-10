#-------------------------------------------------
#
# Project created by QtCreator 2015-02-04T19:10:17
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

TARGET = InterfaceBuilder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    abstractwidget.cpp \
    psdparser.cpp \
    imagerecognizer.cpp \
    geometricalobjectscollector.cpp \
    abstractbutton.cpp \
    pushbutton.cpp \
    radiobutton.cpp \
    combobox.cpp \
    lineedit.cpp \
    testgeometricalobjectcollector.cpp

HEADERS  += mainwindow.h \
    abstractwidget.h \
    psdparser.h \
    imagerecognizer.h \
    geometricalobjectscollector.h \
    abstractbutton.h \
    pushbutton.h \
    radiobutton.h \
    combobox.h \
    lineedit.h \
    testgeometricalobjectcollector.h

FORMS    += mainwindow.ui

CONFIG += uitools

INCLUDEPATH += C:\\opencv\\build\\include
LIBS += -LC:\\opencv-mingw\\bin
LIBS += -lopencv_core249 -lopencv_highgui249 -lopencv_imgproc249
