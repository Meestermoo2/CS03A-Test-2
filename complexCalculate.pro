TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    mixednumber.cpp \
    complexnumber.cpp \
    fraction.cpp \
    friendoffraction.cpp \
    friendofmixednumber.cpp \
    friendofcomplexnumber.cpp \
    memories.cpp \
    friendofmemories.cpp

HEADERS += \
    fraction.h \
    mixednumber.h \
    complexnumber.h \
    memories.h
