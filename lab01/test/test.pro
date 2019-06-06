#-------------------------------------------------
#
# Project created by QtCreator 2019-03-16T16:43:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    transform.cpp \
    matrix.cpp \
    data.cpp \
    process.cpp \
    drawing.cpp \
    error.cpp \
    file_wrap.cpp \
    figure.cpp \
    canvas_wrap.cpp \
    string_wrap.cpp

HEADERS += \
        mainwindow.h \
    transform.h \
    figure.h \
    matrix.h \
    data.h \
    const.h \
    drawing.h \
    process.h \
    error.h \
    file_wrap.h \
    canvas_wrap.h \
    string_wrap.h

FORMS += \
        mainwindow.ui
