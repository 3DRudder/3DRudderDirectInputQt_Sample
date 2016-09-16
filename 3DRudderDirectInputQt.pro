#-------------------------------------------------
#
# Project created by QtCreator 2016-08-11T09:49:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3DRudderDirectInputQt
TEMPLATE = app


SOURCES += main.cpp\
        maindialog.cpp

HEADERS  += maindialog.h

FORMS    += maindialog.ui

win32: LIBS += -ldinput8
win32: LIBS += -ldxguid
