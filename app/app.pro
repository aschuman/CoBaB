include(../compileSettings.pri)
TEMPLATE = app
TARGET = CoBaB
QT += widgets

unix {
LIBS += -L../core -lcore
INCLUDEPATH += ../core/include ../core/interface
}
win32 {
LIBS += -L../core/debug -lcore
INCLUDEPATH += ../core/include
INCLUDEPATH += ../core/include ../core/interface
}

SOURCES += \
    main.cpp

