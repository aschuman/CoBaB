include(../compileSettings.pri)
TEMPLATE = lib
TARGET = core
CONFIG += staticlib
QT += widgets core
INCLUDEPATH = include interface

HEADERS += \
    interface/Medium.h \
    interface/MediumType.h \
    interface/Photo.h \
    interface/Serializable.h \
    interface/SingleFrameVideo.h \
    interface/Video.h \
    interface/Dataset.h \
    interface/Annotation.h \
    interface/RectangleAnnotation.h \
    include/MainControl.h \
    include/MainWindow.h \
    include/Navigator.h \
    include/PageRegistration.h \
    include/PageStackFrame.h \
    include/PageType.h \
    include/PageWidget.h \
    interface/SearchObject.h \
    interface/SearchQuery.h \
    include/DatasetList.h \
    interface/Algorithm.h \
    interface/DataPacket.h \
    interface/DataPacketType.h \
    interface/SearchResultElement.h \
    interface/SearchResult.h

SOURCES += \
    src/Medium.cpp \
    src/Photo.cpp \
    src/SingleFrameVideo.cpp \
    src/Video.cpp \
    src/Dataset.cpp \
    src/Annotation.cpp \
    src/RectangleAnnotation.cpp \
    src/MainControl.cpp \
    src/MainWindow.cpp \
    src/Navigator.cpp \
    src/PageRegistration.cpp \
    src/PageStackFrame.cpp \
    src/SearchObject.cpp \
    src/SearchQuery.cpp \
    src/DatasetList.cpp \
    src/DataPacket.cpp \
    src/SearchResultElement.cpp \
    src/SearchResult.cpp

FORMS += \
    ui/mainwindow.ui
