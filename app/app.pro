TEMPLATE = app
TARGET = CoBaB
CONFIG += c++14
QT += widgets

LIBS += -L../core -lcore
INCLUDEPATH += ../core/include

SOURCES += \
    main.cpp
