TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    variadicparameters.cpp \
    template.cpp

    #configurer/src/configurer.cpp

HEADERS += \
    variadicparameters.h \
    template.h
#    configurer/include/configurer.h


