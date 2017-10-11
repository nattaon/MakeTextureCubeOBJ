#-------------------------------------------------
#
# Project created by QtCreator 2016-05-20T10:26:03
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-3dbpp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    fileedit.cpp \
    writeobjmtl.cpp \
    fileeditmultiple.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    fileedit.h \
    writeobjmtl.h \
    fileeditmultiple.h


FORMS    += mainwindow.ui
