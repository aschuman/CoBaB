include(../compileSettings.pri)
TEMPLATE = lib
TARGET = interface
CONFIG += staticlib c++14
QT += core
INCLUDEPATH += include
RESOURCES = ../application.qrc

HEADERS += \
    include/Algorithm.h \
    include/Annotation.h \
    include/Configuration.h \
    include/DataPacket.h \
    include/Dataset.h \
    include/log.h \
    include/logger.h \
    include/Medium.h \
    include/Photo.h \
    include/RectangleAnnotation.h \
    include/SearchAlgorithm.h \
    include/SearchFeedback.h \
    include/SearchObject.h \
    include/SearchQuery.h \
    include/SearchResult.h \
    include/SearchResultElement.h \
    include/Serializable.h \
    include/SingleFrameVideo.h \
    include/Video.h

SOURCES += \
    src/Annotation.cpp \
    src/DataPacket.cpp \
    src/Dataset.cpp \
    src/log.cpp \
    src/Medium.cpp \
    src/Photo.cpp \
    src/RectangleAnnotation.cpp \
    src/SearchFeedback.cpp \
    src/SearchObject.cpp \
    src/SearchQuery.cpp \
    src/SearchResult.cpp \
    src/SearchResultElement.cpp \
    src/SingleFrameVideo.cpp \
    src/Video.cpp

