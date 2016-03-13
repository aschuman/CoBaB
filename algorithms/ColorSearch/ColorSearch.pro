TEMPLATE = lib
TARGET = ColorSearch
DESTDIR = ../../plugins

QT += core
CONFIG += plugin

INCLUDEPATH += ../../interface/include

unix {
LIBS += -L../../interface -linterface
}
win32 {
LIBS += -L../../interface/debug -linterface
}

QMAKE_CXXFLAGS += -std=c++14

HEADERS += ColorSearch.h \
           ColorHistogram.h
SOURCES += ColorSearch.cpp \
           ColorHistogram.cpp
