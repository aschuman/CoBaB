include(../compileSettings.pri)
TEMPLATE = lib
TARGET = core
CONFIG += staticlib
QT += widgets core
INCLUDEPATH += include interface
RESOURCES = ../application.qrc

HEADERS += \
    interface/Medium.h \
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
    include/SearchAlgorithm.h \
    include/TestAlgorithm.h \
    include/SearchFeedback.h \
    include/Bookmark.h \
    include/BookmarkList.h \
    interface/DataPacket.h \
    interface/SearchResultElement.h \
    interface/SearchResult.h \
    include/LibraryPageWidget.h \
    include/ViewerPageWidget.h \
    interface/Configuration.h \
    interface/logger.h \
    interface/log.h \
    include/ConfigData.h \
    include/DatasetModel.h \
    include/ConfirmationPageWidget.h \
    include/PhotoViewer.h \
    include/MediaModel.h

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
    src/SearchFeedback.cpp \
    src/DatasetList.cpp \
    src/DataPacket.cpp \
    src/SearchResultElement.cpp \
    src/SearchResult.cpp \
    src/LibraryPageWidget.cpp \
    src/ViewerPageWidget.cpp \
    src/Bookmark.cpp \
    src/BookmarkList.cpp \
    src/log.cpp \
    src/ConfigData.cpp \
    src/DatasetModel.cpp \
    src/TestAlgorithm.cpp \
    src/ConfirmationPageWidget.cpp \
    src/PhotoViewer.cpp \
    src/MediaModel.cpp

FORMS += \
    ui/LibraryPageWidget.ui \
    ui/MainWindow.ui \
    ui/ViewerPageWidget.ui \
    ui/ConfirmationPageWidget.ui \
    ui/PhotoViewer.ui
