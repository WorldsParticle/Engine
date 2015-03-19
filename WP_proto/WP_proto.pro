#-------------------------------------------------
#
# Project created by QtCreator 2015-03-18T14:52:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WP_proto
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    model.cpp \
    tabwidget.cpp \
    tools.cpp

HEADERS  += mainwindow.h \
    model.h \
    tabwidget.h \
    tools.h

FORMS    += mainwindow.ui \
    tabwidget.ui
