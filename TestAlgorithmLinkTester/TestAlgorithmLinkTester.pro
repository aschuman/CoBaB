TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += main.cpp

LIBS += ../plugins/libTestAlgorithm.so \
    ../core/libcore.a

