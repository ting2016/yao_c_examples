TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    variadicparameters.cpp \
    streamlogger.cpp \
    ostreamoverride.cpp \
    templatetest2.inc \
    templatetest1.cpp \
    graphic.cpp \
    functionpointer.cpp \
    definetest.cpp \
    singleton.cpp \
    hashtest.cpp \
    maptest.cpp \
    threadtest.cpp \
    functortest.cpp \
    algorithmtest.cpp
    #configurer/src/configurer.cpp

HEADERS += \
    variadicparameters.h \
    streamlogger.h \
    ostreamoverride.h \
    templatetest2.h \
    templatetest1.h \
    graphic.h \
    functionpointer.h \
    definetest.h \
    version.h \
    singleton.h \
    hashtest.h \
    maptest.h \
    fix_array.h \
    threadtest.h \
    functortest.h \
    algorithmtest.h
#    configurer/include/configurer.h

LIBS += -lpthread
