#-------------------------------------------------
#
# Project created by QtCreator 2015-01-19T12:29:56
#
#-------------------------------------------------

QT       += core widgets opengl

QT       -= gui

TARGET = Qt-OpenGL-Minimal_2D
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += -lGL

SOURCES += main.cpp \
    DrawingSurface.cpp

HEADERS += \
    DrawingSurface.h
