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

HEADERS += \
    include/NavigatorTester.h \
    include/PageStackframeTester.h \
    include/PageWidgetMock.h \
    include/PageRegistrationTester.h \
    include/SingleFrameVideoTester.h

SOURCES += \
    src/main.cpp \
    src/NavigatorTester.cpp \
    src/PageRegistrationTester.cpp \
    src/PageStackframeTester.cpp \
    src/PageWidgetMock.cpp \
    src/SingleFrameVideoTester.cpp
