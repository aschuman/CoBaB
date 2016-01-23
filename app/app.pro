TEMPLATE = app
TARGET = CoBaB
CONFIG += c++14

LIBS += -L../core -lcore
INCLUDEPATH += ../core/include

SOURCES += \
    main.cpp
