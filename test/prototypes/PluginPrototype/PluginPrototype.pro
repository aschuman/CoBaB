QT += core
QT -= gui

TARGET = PluginPrototype
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    application.cpp \
    greeting.cpp \
    list.cpp

HEADERS += \
    application.h \
    greeting.h \
    list.h \
    printer.h \
    iprinter.h

CONFIG += c++14

DESTDIR = ..
