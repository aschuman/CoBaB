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
    iprinter.h \
    greeting.h \
    list.h

CONFIG += c++14
