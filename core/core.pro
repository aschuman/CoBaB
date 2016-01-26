TEMPLATE = lib
TARGET = core
CONFIG += staticlib c++14
QT += widgets core
INCLUDEPATH = include

HEADERS += \
    include/Medium.h \
    include/MediumType.h \
    include/Photo.h \
    include/Serializable.h \
    include/SingleFrameVideo.h \
    include/Video.h

SOURCES += \
    src/main.cpp \
    src/Medium.cpp \
    src/Photo.cpp \
    src/SingleFrameVideo.cpp \
    src/Video.cpp
