include(../compileSettings.pri)
TEMPLATE = lib
TARGET = core
CONFIG += staticlib
QT += widgets core multimedia
INCLUDEPATH += include interface
RESOURCES = ../application.qrc

unix{
res.commands = $(COPY_DIR) $$PWD/../resources $$OUT_PWD/../
first.depends = $(first) res
export(first.depends)
export(res.commands)
QMAKE_EXTRA_TARGETS += first res
}
win32{
PWD_WIN = $${PWD}
DESTDIR_WIN = $${OUT_PWD}
PWD_WIN ~= s,/,\,g
DESTDIR_WIN ~= s,/,\,g

res.commands = $(COPY_DIR) \"$${PWD_WIN}\..\resources\" \"$${DESTDIR_WIN}\..\resources\"
first.depends = $(first) res
export(first.depends)
export(res.commands)
QMAKE_EXTRA_TARGETS += first res
}

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
    interface/SearchAlgorithm.h \
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
    include/MediaModel.h \
    include/ParameterPageWidget.h \
    include/AnnotationDrawer.h \
    include/AnnotationGraphicsItemFactory.h \
    QJsonModel.h \
    QJsonItem.h \
    include/ClickableGraphicsRectItem.h \
    include/ClickableGraphicsPixmapItem.h \
    include/FeedbackEditor.h \
    include/DualFeedbackEditor.h \
    interface/SearchResultElementFeedback.h \
    include/FeedbackDelegate.h \
    include/SearchResultModel.h \
    include/ResultsPageWidget.h \
    include/SingleFrameVideoViewer.h \
    include/SearchManager.h \
    interface/AlgorithmList.h \
    include/CustomGraphicsView.h

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
    src/ConfirmationPageWidget.cpp \
    src/PhotoViewer.cpp \
    src/MediaModel.cpp \
    src/ParameterPageWidget.cpp \
    src/AnnotationDrawer.cpp \
    src/AnnotationGraphicsItemFactory.cpp \
    QJsonModel.cpp \
    QJsonItem.cpp \
    src/ClickableGraphicsRectItem.cpp \
    src/ClickableGraphicsPixmapItem.cpp \
    src/DualFeedbackEditor.cpp \
    src/FeedbackDelegate.cpp \
    src/ResultsPageWidget.cpp \
    src/SearchResultModel.cpp \
    src/SingleFrameVideoViewer.cpp \
    src/SearchManager.cpp \
    src/AlgorithmList.cpp \
    src/CustomGraphicsView.cpp

FORMS += \
    ui/LibraryPageWidget.ui \
    ui/MainWindow.ui \
    ui/ViewerPageWidget.ui \
    ui/ConfirmationPageWidget.ui \
    ui/ParameterPageWidget.ui \
    ui/ResultsPageWidget.ui
