#-------------------------------------------------
#
# Project created by QtCreator 2015-12-12T21:27:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NavigationPrototype
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    libraryview.cpp \
    datasetview.cpp \
    navigator.cpp

HEADERS  += mainwindow.h \
    libraryview.h \
    datasetview.h \
    navigator.h

FORMS    += mainwindow.ui \
    libraryview.ui \
    datasetview.ui

CONFIG += c++14
