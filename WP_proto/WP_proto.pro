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


SOURCES +=	main.cpp\
			window/mainwindow.cpp \
			window/irrlichtwidget.cpp \
			window/glwidget.cpp \
			window/toolwidget.cpp \
			window/glwindow.cpp \
			model/model.cpp \
			model/tools.cpp \
			graphic/fire.cpp \
			graphic/myglpainter.cpp \
                        engine/gameengine.cpp \
    engine/gameclock.cpp

HEADERS  += window/mainwindow.h \
			window/irrlichtwidget.h \
			window/glwidget.h \
			window/toolwidget.h \
			window/glwindow.h \
			model/model.h \
			model/tools.h \
			graphic/fire.h \
			graphic/myglpainter.h \
                        engine/gameengine.h \
    engine/gameclock.h

FORMS    += window/mainwindow.ui \
            window/toolwidget.ui
