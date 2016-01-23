TEMPLATE = app
TARGET = test
CONFIG += c++14
CONFIG += testcase
QT += testlib
INCLUDEPATH += include

LIBS += -L../core -lcore
INCLUDEPATH += ../core/include

HEADERS += \

SOURCES += \
    src/main.cpp
