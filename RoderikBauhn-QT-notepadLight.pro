#-------------------------------------------------
#
# Project created by QtCreator 2016-02-16T09:56:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
TARGET = RoderikBauhn-QT-notepadLight
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settingsform.cpp \
    engine.cpp \
    legal.cpp

HEADERS  += mainwindow.h \
    settingsform.h \
    engine.h \
    legal.h

FORMS    += mainwindow.ui \
    dialogsavebeforeclosing.ui \
    settingsform.ui \
    legal.ui

DISTFILES += \
    notesReadMe.txt \
    qtföreläsning.txt \
    laboration-RedInfo.pdf \
    bin+lib/RoderikBauhn-QT-notepadLight \
    bin+lib/libgcc_s_dw2-1.dll \
    bin+lib/libstdc++-6.dll \
    bin+lib/libwinpthread-1.dll \
    bin+lib/Qt5Core.dll \
    bin+lib/Qt5Gui.dll \
    bin+lib/Qt5Widgets.dll \
    bin+lib/RoderikBauhn-QT-notepadLight.exe \
    dv1497-qt-projekt-red.odp \
    classDiagram.qmodel

RESOURCES += \
    resourcesshitty.qrc
