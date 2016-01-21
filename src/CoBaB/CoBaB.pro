QT += core
QT -= gui

TARGET = CoBaB
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Model/AlgorithmList.cpp \
    Model/Annotation.cpp \
    Model/Bookmark.cpp \
    Model/BookmarkIO.cpp \
    Model/BookmarkList.cpp \
    Model/ConfigData.cpp \
    Model/DataPacket.cpp \
    Model/Dataset.cpp \
    Model/DatasetList.cpp \
    Model/DatasetParseType.cpp \
    Model/DualFeedback.cpp \
    Model/ExtendedFeedback.cpp \
    Model/FaceAnnotation.cpp \
    Model/Medium.cpp \
    Model/PersonAnnotation.cpp \
    Model/Photo.cpp \
    Model/RectangleAnnotation.cpp \
    Model/SearchFeedback.cpp \
    Model/SearchObject.cpp \
    Model/SearchQuery.cpp \
    Model/SearchResult.cpp \
    Model/SearchResultElement.cpp \
    Model/SearchResultIO.cpp \
    Model/SingleFrameVideo.cpp \
    Model/TestAlgorithm.cpp \
    Model/Video.cpp

HEADERS += \
    Model/Algorithm.h \
    Model/AlgorithmList.h \
    Model/Annotation.h \
    Model/AnnotationType.h \
    Model/Bookmark.h \
    Model/BookmarkIO.h \
    Model/BookmarkList.h \
    Model/ConfigData.h \
    Model/DataPacket.h \
    Model/DataPacketType.h \
    Model/Dataset.h \
    Model/DatasetList.h \
    Model/DatasetParseType.h \
    Model/DatasetType.h \
    Model/DualFeedback.h \
    Model/ExtendedFeedback.h \
    Model/FaceAnnotation.h \
    Model/Feedback.h \
    Model/FeedbackType.h \
    Model/Language.h \
    Model/Medium.h \
    Model/MediumType.h \
    Model/PersonAnnotation.h \
    Model/Photo.h \
    Model/RectangleAnnotation.h \
    Model/SearchAlgorithm.h \
    Model/SearchFeedback.h \
    Model/SearchObject.h \
    Model/SearchQuery.h \
    Model/SearchResult.h \
    Model/SearchResultElement.h \
    Model/SearchResultIO.h \
    Model/Serializable.h \
    Model/SingleFrameVideo.h \
    Model/TestAlgorithm.h \
    Model/Video.h

