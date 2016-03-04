QT += core
#QT -= gui

TARGET = $$qtLibraryTarget(TestAlgorithm)

TEMPLATE = lib
CONFIG += plugin c++14
INCLUDEPATH += ../core/interface
DESTDIR = ../plugins

SOURCES += \
    TestAlgorithm.cpp

HEADERS += \
    TestAlgorithm.h

DISTFILES += \
    TestAlgorithm.json

