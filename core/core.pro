include(../compileSettings.pri)
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
    include/Video.h \
    include/Dataset.h \
    include/Annotation.h \
    include/RectangleAnnotation.h \
    include/MainControl.h \
    include/MainWindow.h \
    include/Navigator.h \
    include/PageRegistration.h \
    include/PageStackFrame.h \
    include/PageType.h \
    include/PageWidget.h \
    include/SearchObject.h \
    include/SearchQuery.h

SOURCES += \
    src/main.cpp \
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
    src/PageWidget.cpp \
    src/SearchObject.cpp \
    src/SearchQuery.cpp

FORMS += \
    ui/mainwindow.ui
