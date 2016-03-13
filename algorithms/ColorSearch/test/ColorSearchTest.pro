TEMPLATE = app
TARGET   = testColorSearch

QT += core testlib
CONFIG += debug

QMAKE_CXXFLAGS += -std=c++14

INCLUDEPATH += ../ \
               ../../../interface/include
LIBS        += -L../../../plugins -lColorSearch
#LIBS        += -L../../../interface -linterface

HEADERS += ColorSearchTest.h
SOURCES += ColorSearchTest.cpp
