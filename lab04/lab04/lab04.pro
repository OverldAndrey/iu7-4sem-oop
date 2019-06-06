#-------------------------------------------------
#
# Project created by QtCreator 2019-05-04T19:26:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab04
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
    scene.cpp \
    figure.cpp \
    camera.cpp \
    matrix.cpp \
    object.cpp \
    composite.cpp \
    point.cpp \
    abstractobject.cpp \
    basefigure.cpp \
    cameraiterator.cpp \
    objectiterator.cpp \
    pointconnection.cpp \
    framefigure.cpp \
    baseobjectiterator.cpp \
    pointiterator.cpp \
    mainprocess.cpp \
    basecommand.cpp \
    scenebuilder.cpp \
    baseparser.cpp \
    loadcommand.cpp \
    sceneloadmanager.cpp \
    simpleparser.cpp \
    scenedrawmanager.cpp \
    basescenemanager.cpp \
    baseprocessresult.cpp \
    drawcommand.cpp \
    drawresult.cpp \
    objectposition.cpp \
    scenetransformmanager.cpp \
    sceneobjectiterator.cpp \
    transformcommand.cpp \
    movecommand.cpp \
    scenemovemanager.cpp \
    scenescalemanager.cpp \
    scalecommand.cpp \
    rotatecommand.cpp \
    scenerotatemanager.cpp \
    savecommand.cpp \
    scenesavemanager.cpp \
    basesaveparser.cpp \
    simplesaveparser.cpp

HEADERS += \
        mainwindow.h \
    scene.h \
    figure.h \
    camera.h \
    matrix.h \
    object.h \
    composite.h \
    point.h \
    abstractobject.h \
    basefigure.h \
    cameraiterator.h \
    objectiterator.h \
    pointconnection.h \
    framefigure.h \
    baseobjectiterator.h \
    pointiterator.h \
    mainprocess.h \
    basecommand.h \
    scenebuilder.h \
    baseparser.h \
    loadcommand.h \
    sceneloadmanager.h \
    simpleparser.h \
    scenedrawmanager.h \
    basescenemanager.h \
    baseprocessresult.h \
    drawcommand.h \
    drawresult.h \
    objectposition.h \
    scenetransformmanager.h \
    sceneobjectiterator.h \
    transformcommand.h \
    movecommand.h \
    scenemovemanager.h \
    scenescalemanager.h \
    scalecommand.h \
    rotatecommand.h \
    scenerotatemanager.h \
    savecommand.h \
    scenesavemanager.h \
    basesaveparser.h \
    simplesaveparser.h

FORMS += \
        mainwindow.ui
