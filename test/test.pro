include(../compileSettings.pri)
TEMPLATE = app
TARGET = test
CONFIG += testcase
QT += testlib core widgets
INCLUDEPATH += include

unix {
LIBS += -L../core -lcore
INCLUDEPATH += ../core/include \
    ../core/interface
}
win32 {
LIBS += -L../core/debug -lcore
INCLUDEPATH += ../core/include \
    ../core/interface
}

unix{
testdata.commands = $(COPY_DIR) $$PWD/testdata $$OUT_PWD
first.depends = $(first) testdata
export(first.depends)
export(testdata.commands)
QMAKE_EXTRA_TARGETS += first testdata
}
win32{
PWD_WIN = $${PWD}
DESTDIR_WIN = $${OUT_PWD}
PWD_WIN ~= s,/,\,g
DESTDIR_WIN ~= s,/,\,g

testdata.commands = $(COPY_DIR) \"$${PWD_WIN}\testdata\" \"$${DESTDIR_WIN}\testdata\"
first.depends = $(first) testdata
export(first.depends)
export(testdata.commands)
QMAKE_EXTRA_TARGETS += first testdata
}

HEADERS += \
    include/NavigatorTester.h \
    include/PageStackframeTester.h \
    include/PageWidgetMock.h \
    include/PageRegistrationTester.h \
    include/SingleFrameVideoTester.h \
    include/DatasetTester.h \
    include/DatasetListTester.h \
    include/ConfigDataTester.h \
    include/DataPacketTester.h \
    include/SearchObjectTester.h \
    include/SearchQueryTester.h \
    include/SearchResultTester.h \
    include/SearchResultElementTester.h \
    include/AnnotationTester.h \
    include/RectangleAnnotationTester.h \
    include/BookmarkTester.h \
    include/BookmarkListTester.h \
    include/TestAlgorithmTester.h \
    include/SearchFeedbackTester.h

SOURCES += \
    src/main.cpp \
    src/NavigatorTester.cpp \
    src/PageRegistrationTester.cpp \
    src/PageStackframeTester.cpp \
    src/PageWidgetMock.cpp \
    src/SingleFrameVideoTester.cpp \
    src/DatasetTester.cpp \
    src/DatasetListTester.cpp \
    src/ConfigDataTester.cpp \
    src/DataPacketTester.cpp \
    src/SearchObjectTester.cpp \
    src/SearchQueryTester.cpp \
    src/SearchResultTester.cpp \
    src/SearchResultElementTester.cpp \
    src/AnnotationTester.cpp \
    src/RectangleAnnotationTester.cpp \
    src/SearchFeedbackTester.cpp \
    src/BookmarkTester.cpp \
    src/BookmarkListTester.cpp \
    src/TestAlgorithmTester.cpp


