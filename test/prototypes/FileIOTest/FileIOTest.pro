QT += core
QT -= gui
QT += widgets

TARGET = FileIOTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    searchresultio.cpp \
    searchresult.cpp

HEADERS += \
    searchresultio.h \
    searchresult.h

