#-------------------------------------------------
#
# Project created by QtCreator 2016-02-16T09:56:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RoderikBauhn-QT-notepadLight
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settingsform.cpp \
    qtföreläsning.cpp

HEADERS  += mainwindow.h \
    settingsform.h

FORMS    += mainwindow.ui \
    dialogsavebeforeclosing.ui \
    settingsform.ui

DISTFILES += \
    notesReadMe.txt
