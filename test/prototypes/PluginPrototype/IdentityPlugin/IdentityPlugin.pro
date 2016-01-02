QT += core
QT -= gui

TARGET = IdentityPlugin
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    identityprinter.cpp

HEADERS += \
    identityprinter.h \
    concreteprinters.h

