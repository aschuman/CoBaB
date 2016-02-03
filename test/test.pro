include(../compileSettings.pri)
TEMPLATE = app
TARGET = test
CONFIG += c++14
CONFIG += testcase
QT += testlib
INCLUDEPATH += include

unix {
LIBS += -L../core -lcore
INCLUDEPATH += ../core/include
}
win32 {
LIBS += -L../core/debug -lcore
INCLUDEPATH += ../core/include
}

HEADERS += \
    include/pagestackframetester.h \
    include/pagewidgetmock.h

SOURCES += \
    src/main.cpp \
    src/pagestackframetester.cpp \
    src/pagewidgetmock.cpp
