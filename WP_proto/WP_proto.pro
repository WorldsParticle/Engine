#-------------------------------------------------
#
# Project created by QtCreator 2015-03-18T14:52:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WP_proto
TEMPLATE = app

LIBS += -LD:\SDK\irrlicht-1.8.1\lib\Win64-visualStudio -lIrrlicht
INCLUDEPATH += D:\SDK\irrlicht-1.8.1\include


SOURCES += main.cpp\
        mainwindow.cpp \
    model.cpp \
    tabwidget.cpp \
    tools.cpp \
    irrlichtwidget.cpp

HEADERS  += mainwindow.h \
    model.h \
    tabwidget.h \
    tools.h \
    irrlichtwidget.h

FORMS    += mainwindow.ui \
    tabwidget.ui
