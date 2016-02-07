include(../compileSettings.pri)
TEMPLATE = app
TARGET = CoBaB
QT += widgets

unix {
LIBS += -L../core -lcore
INCLUDEPATH += ../core/include
}
win32 {
LIBS += -L../core/debug -lcore
INCLUDEPATH += ../core/include
}

SOURCES += \
    main.cpp

