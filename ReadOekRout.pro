#TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt pthread
TEMPLATE=lib
CONFIG+= lib
LIBS +=  -lpthread -lcsv
SOURCES += \
        ReadOekRout.cpp \
      #  test.cpp \

HEADERS += \
        ReadOekRout.h \
        "csv-parser/include/csv.hpp" \


