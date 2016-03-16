QT += core
#QT -= gui

TARGET = $$qtLibraryTarget(TestAlgorithm)

TEMPLATE = lib
CONFIG += plugin c++14
INCLUDEPATH += ../../interface/include
DESTDIR = ../../plugins

unix {
LIBS += -L../../interface -linterface
}
win32 {
LIBS += -L../../interface/debug -linterface
}

SOURCES += \
    TestAlgorithm.cpp

HEADERS += \
    TestAlgorithm.h

DISTFILES += \
    TestAlgorithm.json

