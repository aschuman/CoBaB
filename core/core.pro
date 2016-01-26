TEMPLATE = lib
TARGET = core
CONFIG += staticlib c++14
QT += widgets core
INCLUDEPATH = include

HEADERS += \
    include/maincontrol.h \
    include/pagestackframe.h \
    include/pagetype.h \
    include/Medium.h \
    include/MediumType.h \
    include/Photo.h \
    include/Serializable.h \
    include/SingleFrameVideo.h \
    include/Video.h \
    include/pagewidget.h

SOURCES += \
    src/main.cpp \
    src/maincontrol.cpp \
    src/pagestackframe.cpp \
    src/Medium.cpp \
    src/Photo.cpp \
    src/SingleFrameVideo.cpp \
    src/Video.cpp \
    src/pagewidget.cpp
