include(../compileSettings.pri)
TEMPLATE = lib
TARGET = core
CONFIG += staticlib
QT += widgets core multimedia
INCLUDEPATH += include

INCLUDEPATH += ../interface/include
unix {
LIBS += -L../interface -linterface
}
win32 {
LIBS += -L../interface/debug -linterface
}

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
    include/AlgorithmList.h \
    include/AnnotationDrawer.h \
    include/AnnotationGraphicsItemFactory.h \
    include/Bookmark.h \
    include/BookmarkList.h \
    include/ClickableGraphicsPixmapItem.h \
    include/ClickableGraphicsRectItem.h \
    include/ConfigData.h \
    include/ConfirmationPageWidget.h \
    include/CustomGraphicsView.h \
    include/DatasetList.h \
    include/DatasetModel.h \
    include/DualFeedbackEditor.h \
    include/FeedbackDelegate.h \
    include/FeedbackEditor.h \
    include/Language.h \
    include/LibraryPageWidget.h \
    include/MainControl.h \
    include/MainWindow.h \
    include/MediaModel.h \
    include/Navigator.h \
    include/PageRegistration.h \
    include/PageStackFrame.h \
    include/PageType.h \
    include/PageWidget.h \
    include/ParameterPageWidget.h \
    include/PhotoViewer.h \
    include/QJsonItem.h \
    include/QJsonModel.h \
    include/ResultsPageWidget.h \
    include/SearchManager.h \
    include/SearchResultElementFeedback.h \
    include/SearchResultModel.h \
    include/SingleFrameVideoViewer.h \
    include/ViewerPageWidget.h

SOURCES += \
    src/AlgorithmList.cpp \
    src/AnnotationDrawer.cpp \
    src/AnnotationGraphicsItemFactory.cpp \
    src/Bookmark.cpp \
    src/BookmarkList.cpp \
    src/ClickableGraphicsPixmapItem.cpp \
    src/ClickableGraphicsRectItem.cpp \
    src/ConfigData.cpp \
    src/ConfirmationPageWidget.cpp \
    src/CustomGraphicsView.cpp \
    src/DatasetList.cpp \
    src/DatasetModel.cpp \
    src/DualFeedbackEditor.cpp \
    src/FeedbackDelegate.cpp \
    src/LibraryPageWidget.cpp \
    src/MainControl.cpp \
    src/MainWindow.cpp \
    src/MediaModel.cpp \
    src/Navigator.cpp \
    src/PageRegistration.cpp \
    src/PageStackFrame.cpp \
    src/ParameterPageWidget.cpp \
    src/PhotoViewer.cpp \
    src/QJsonItem.cpp \
    src/QJsonModel.cpp \
    src/ResultsPageWidget.cpp \
    src/SearchManager.cpp \
    src/SearchResultModel.cpp \
    src/SingleFrameVideoViewer.cpp \
    src/ViewerPageWidget.cpp

FORMS += \
    ui/ConfirmationPageWidget.ui \
    ui/LibraryPageWidget.ui \
    ui/MainWindow.ui \
    ui/ParameterPageWidget.ui \
    ui/ResultsPageWidget.ui \
    ui/ViewerPageWidget.ui
