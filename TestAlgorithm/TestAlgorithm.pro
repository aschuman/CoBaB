QT += core
#QT -= gui

TARGET = $$qtLibraryTarget(TestAlgorithm)

TEMPLATE = lib
CONFIG += plugin c++14
INCLUDEPATH += ../core/interface
DESTDIR = ../plugins

unix {
LIBS += -L../core -lcore
}
win32 {
LIBS += -L../core/debug -lcore
}

SOURCES += \
    TestAlgorithm.cpp

HEADERS += \
    TestAlgorithm.h

DISTFILES += \
    TestAlgorithm.json

