include(../compileSettings.pri)
TEMPLATE = app
TARGET = test
CONFIG += c++14 testcase
QT += testlib core widgets
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
    include/pageregistrationtester.h \
    include/pagewidgetmock.h

SOURCES += \
    src/main.cpp \
    src/pagestackframetester.cpp \
    src/pageregistrationtester.cpp \
    src/pagewidgetmock.cpp
