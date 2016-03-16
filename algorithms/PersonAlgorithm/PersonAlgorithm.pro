QT += core

TARGET = $$qtLibraryTarget(PersonAlgorithm)

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
    PersonAlgorithm.cpp

HEADERS += \
    PersonAlgorithm.h

DISTFILES += \
    PersonAlgorithm.json
