#TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt pthread
TEMPLATE=lib
CONFIG+= lib
LIBS +=  -lpthread -lcsv
SOURCES += \
        ReadOekRoute.cpp \
      #  test.cpp \

HEADERS += \
        ReadOekRoute.h \
        "csv-parser/include/csv.hpp" \


