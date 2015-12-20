#-------------------------------------------------
#
# Project created by QtCreator 2015-12-18T21:18:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlayerPrototype
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    medium.cpp \
    mediaplayer.cpp

HEADERS  += mainwindow.h \
    medium.h \
    mediaplayer.h

FORMS    += \
    mediaplayer.ui \
    mainwindow.ui

CONFIG += c++14
