TEMPLATE = app
CONFIG += console c++14
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
    algorithmtest.cpp \
    randomtest.cpp \
    puretest.cpp \
    chronotest.cpp \
    malicious.cpp \
    lambdatest.cpp \
    foo.cpp \
    yaostl.cpp \
    exceptiontest.cpp \
    bar.cpp
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
    algorithmtest.h \
    randomtest.h \
    puretest.h \
    chronotest.h \
    malicious.h \
    lambdatest.h \
    yaostl.h \
    foo.h \
    exceptiontest.h \
    bar.h
#    configurer/include/configurer.h

LIBS += -lpthread
