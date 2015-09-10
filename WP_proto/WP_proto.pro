#-------------------------------------------------
#
# Project created by QtCreator 2015-03-18T14:52:18
#
#-------------------------------------------------

QT       += core gui opengl
CONFIG   += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WP_proto
TEMPLATE = app

#DEFINES += "USING_IRRLICHT"
#LIBS += -LD:\SDK\irrlicht-1.8.1\lib\Win64-visualStudio -lIrrlicht  <- local
#INCLUDEPATH += D:\SDK\irrlicht-1.8.1\include                       <- local


SOURCES += main.cpp\
        mainwindow.cpp \
    model.cpp \
    tools.cpp \
    irrlichtwidget.cpp \
    view.cpp \
    scene.cpp \
    glwidget.cpp \
    toolwidget.cpp \
    fire.cpp

HEADERS  += mainwindow.h \
    model.h \
    tools.h \
    irrlichtwidget.h \
    view.h \
    scene.h \
    glwidget.h \
    toolwidget.h \
    fire.h

FORMS    += mainwindow.ui \
    toolwidget.ui
