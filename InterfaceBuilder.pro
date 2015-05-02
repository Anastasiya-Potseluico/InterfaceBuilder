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
    imagerecognizer.cpp \
    geometricalobjectscollector.cpp \
    abstractbutton.cpp \
    pushbutton.cpp \
    radiobutton.cpp \
    combobox.cpp \
    lineedit.cpp \
    testgeometricalobjectcollector.cpp \
    treewidgetview.cpp \
    treewidget.cpp \
    tablewidgetview.cpp \
    tablewidget.cpp \
    spinboxview.cpp \
    spinbox.cpp \
    radiobuttonview.cpp \
    pushbuttonview.cpp \
    progressbarview.cpp \
    progressbar.cpp \
    listwidgetview.cpp \
    listwidget.cpp \
    lineeditview.cpp \
    labelview.cpp \
    label.cpp \
    graphicsviewview.cpp \
    graphicsview.cpp \
    comboboxview.cpp \
    checkboxview.cpp \
    checkbox.cpp \
    calendarview.cpp \
    calendar.cpp \
    abstractwidgetview.cpp \
    abstractitemwidget.cpp \
    mainwindowcontainer.cpp \
    mainwindowview.cpp \
    cornergrabber.cpp \
    dialogsettings.cpp

HEADERS  += mainwindow.h \
    abstractwidget.h \
    imagerecognizer.h \
    geometricalobjectscollector.h \
    abstractbutton.h \
    pushbutton.h \
    radiobutton.h \
    combobox.h \
    lineedit.h \
    testgeometricalobjectcollector.h \
    ui_mainwindow.h \
    treewidgetview.h \
    treewidget.h \
    tablewidgetview.h \
    tablewidget.h \
    spinboxview.h \
    spinbox.h \
    radiobuttonview.h \
    pushbuttonview.h \
    progressbarview.h \
    progressbar.h \
    mainwindow.h \
    listwidgetview.h \
    listwidget.h \
    lineeditview.h \
    labelview.h \
    label.h \
    graphicsviewview.h \
    graphicsview.h \
    comboboxview.h \
    checkboxview.h \
    checkbox.h \
    calendarview.h \
    calendar.h \
    abstractwidgetview.h \
    abstractitemwidget.h \
    mainwindowcontainer.h \
    mainwindowview.h \
    cornergrabber.h \
    dialogsettings.h

FORMS    += mainwindow.ui \
    mainwindow.ui \
    dialogsettings.ui

CONFIG += uitools

INCLUDEPATH += C:\\opencv\\build\\include
LIBS += -LC:\\opencv-mingw\\bin
LIBS += -lopencv_core249 -lopencv_highgui249 -lopencv_imgproc249

OTHER_FILES +=
