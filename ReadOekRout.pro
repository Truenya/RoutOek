TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt pthread
#TEMPLATE=lib
#CONFIG+= staticlib
LIBS +=  -lpthread
SOURCES += \
        ReadOekRout.cpp \
        ReadOekRout.h \
        test.cpp

