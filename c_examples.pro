TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    variadicparameters.cpp \
    streamlogger.cpp \
    templatetest2.inc \
    templatetest1.cpp \
    graphic.cpp \
    functionpointer.cpp \
    definetest.cpp \
    version.cpp \
    singleton.cpp \
    hashtest.cpp \
    maptest.cpp \
    threadtest.cpp \
    functortest.cpp \
    algorithmtest.cpp \
    randomtest.cpp \
    chronotest.cpp \
    malicious.cpp \
    lambdatest.cpp \
    foo.cpp \
    exceptiontest.cpp \
    bar.cpp \
    fileio.cpp \
    ctor_test.cpp \
    simpletree.cpp \
    functionaltest.cpp \
    initializer_list_test.cpp \
    signaltest.cpp
    #configurer/src/configurer.cpp

HEADERS += todo.h \
    variadicparameters.h \
    streamlogger.h \
    templatetest2.h \
    templatetest1.h \
    graphic.h \
    functionpointer.h \
    definetest.h \
    version.h \
    singleton.h \
    hashtest.h \
    maptest.h \
    threadtest.h \
    functortest.h \
    algorithmtest.h \
    randomtest.h \
    chronotest.h \
    malicious.h \
    lambdatest.h \
    foo.h \
    exceptiontest.h \
    bar.h \
    fileio.h \
    stltest.h \
    namespace.h \
    ctortest.h \
    simpletree.h \
    functionaltest.h \
    initializer_list_test.h \
    signaltest.h
#    configurer/include/configurer.h

LIBS += -lpthread -lrt
