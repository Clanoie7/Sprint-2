TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dsstring.cpp \
    tweet.cpp \
    run.cpp

HEADERS += \
    dsvector.h \
    catch.h \
    dsstring.h \
    tweet.h \
    run.h
