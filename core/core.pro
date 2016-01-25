TEMPLATE = lib
TARGET = core
CONFIG += staticlib c++14
QT += widgets core
INCLUDEPATH = include

HEADERS += \
    include/Algorithm.h \
    include/AlgorithmList.h \
    include/Annotation.h \
    include/AnnotationType.h \
    include/Bookmark.h \
    include/BookmarkList.h \
    include/CoBaB.h \
    include/ConfigData.h \
    include/DataPacket.h \
    include/DataPacketType.h \
    include/Dataset.h \
    include/DatasetList.h \
    include/DatasetType.h \
    include/FeedbackType.h \
    include/Language.h \
    include/Medium.h \
    include/MediumType.h \
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
    include/TestAlgorithm.h \
    include/Video.h

SOURCES += \
    src/AlgorithmList.cpp \
    src/Annotation.cpp \
    src/Bookmark.cpp \
    src/BookmarkList.cpp \
    src/ConfigData.cpp \
    src/DataPacket.cpp \
    src/Dataset.cpp \
    src/DatasetList.cpp \
    src/main.cpp \
    src/Medium.cpp \
    src/Photo.cpp \
    src/RectangleAnnotation.cpp \
    src/SearchFeedback.cpp \
    src/SearchObject.cpp \
    src/SearchQuery.cpp \
    src/SearchResult.cpp \
    src/SearchResultElement.cpp \
    src/SingleFrameVideo.cpp \
    src/TestAlgorithm.cpp \
    src/Video.cpp
