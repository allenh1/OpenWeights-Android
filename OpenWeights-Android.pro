#-------------------------------------------------
#
# Project created by QtCreator 2014-11-17T22:47:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenWeights-Android
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    showStats.cpp \
    DateSelector.cpp

HEADERS  += mainwindow.h \
    showStats.h \
    DateSelector.h \
    LogStruct.h

FORMS    += mainwindow.ui \
    ShowStats.ui \
    dateSelector.ui

CONFIG += mobility
MOBILITY = 

