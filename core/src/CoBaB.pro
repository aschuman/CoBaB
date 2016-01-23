QT += core
QT += gui

TARGET = CoBaB
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    AlgorithmList.cpp \
    Annotation.cpp \
    Bookmark.cpp \
    BookmarkList.cpp \
    ConfigData.cpp \
    DataPacket.cpp \
    Dataset.cpp \
    DatasetList.cpp \
    Medium.cpp \
    Photo.cpp \
    RectangleAnnotation.cpp \
    SearchFeedback.cpp \
    SearchObject.cpp \
    SearchQuery.cpp \
    SearchResult.cpp \
    SearchResultElement.cpp \
    SingleFrameVideo.cpp \
    TestAlgorithm.cpp \
    Video.cpp

HEADERS += \
    ../../include/Algorithm.h \
    ../../include/AlgorithmList.h \
    ../../include/Annotation.h \
    ../../include/AnnotationType.h \
    ../../include/Bookmark.h \
    ../../include/BookmarkList.h \
    ../../include/ConfigData.h \
    ../../include/DataPacket.h \
    ../../include/DataPacketType.h \
    ../../include/Dataset.h \
    ../../include/DatasetList.h \
    ../../include/DatasetType.h \
    ../../include/FeedbackType.h \
    ../../include/Language.h \
    ../../include/Medium.h \
    ../../include/MediumType.h \
    ../../include/Photo.h \
    ../../include/RectangleAnnotation.h \
    ../../include/SearchAlgorithm.h \
    ../../include/SearchFeedback.h \
    ../../include/SearchObject.h \
    ../../include/SearchQuery.h \
    ../../include/SearchResult.h \
    ../../include/SearchResultElement.h \
    ../../include/Serializable.h \
    ../../include/SingleFrameVideo.h \
    ../../include/TestAlgorithm.h \
    ../../include/Video.h \
    ../../include/CoBaB.h

