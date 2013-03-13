#-------------------------------------------------
#
# Project created by QtCreator 2013-03-13T11:21:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpringTable
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    mylistwidget.cpp \
    showtaskdialog.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    mylistwidget.h \
    showtaskdialog.h

FORMS    += mainwindow.ui \
    dialog.ui \
    showtaskdialog.ui
