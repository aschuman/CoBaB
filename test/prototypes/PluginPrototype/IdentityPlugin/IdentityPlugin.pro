QT += core
QT -= gui

#TARGET = IdentityPlugin
TARGET = $$qtLibraryTarget(IdentityPlugin)

TEMPLATE = lib
CONFIG += plugin
INCLUDEPATH += ./..

SOURCES += \
    identityprinter.cpp

HEADERS += \
    identityprinter.h

DESTDIR = ../plugins

CONFIG += c++14
