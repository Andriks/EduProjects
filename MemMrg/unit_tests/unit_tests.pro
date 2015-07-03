TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


INCLUDEPATH += c:\boost\include\boost-1_58\
LIBS += c:\boost\lib\

SOURCES += \
    test_memmrg.cpp \
    ../memmrg.cpp

HEADERS += \
    ../memmrg.h

