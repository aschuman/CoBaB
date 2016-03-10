include(../compileSettings.pri)
TEMPLATE = app
TARGET = CoBaB
QT += widgets multimedia
INCLUDEPATH += ../core/include ../interface/include

unix {
LIBS += -L../core -lcore
LIBS += -L../interface -linterface
}
win32 {
LIBS += -L../core/debug -lcore
LIBS += -L../interface/debug -linterface
}

SOURCES += \
    main.cpp

