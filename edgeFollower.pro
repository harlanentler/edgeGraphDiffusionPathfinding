#-------------------------------------------------
#
# Project created by QtCreator 2015-02-11T00:59:04
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = edgeGraph
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    coord.cpp \
    diffuser.cpp \
    vdata.cpp \
    master.cpp \
    entity.cpp

HEADERS += \
    coord.h \
    vertex.h \
    edge.h \
    graph.h \
    diffuser.h \
    vdata.h \
    master.h \
    entity.h
