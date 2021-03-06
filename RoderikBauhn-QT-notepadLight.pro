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
    legal.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    settingsform.h \
    engine.h \
    legal.h \
    about.h

FORMS    += mainwindow.ui \
    dialogsavebeforeclosing.ui \
    settingsform.ui \
    legal.ui \
    about.ui

DISTFILES += \
    notesReadMe.txt \
    qtföreläsning.txt \
    laboration-RedInfo.pdf \
    bin+lib/libgcc_s_dw2-1.dll \
    bin+lib/libstdc++-6.dll \
    bin+lib/libwinpthread-1.dll \
    bin+lib/Qt5Gui.dll \
    bin+lib/Qt5Widgets.dll \
    bin+lib/RoderikBauhn-QT-notepadLight.exe \
    dv1497-qt-projekt-red.odp \
    classDiagram.qmodel \
    bin+lib/windows/libgcc_s_dw2-1.dll \
    bin+lib/windows/libstdc++-6.dll \
    bin+lib/windows/libwinpthread-1.dll \
    bin+lib/windows/Qt5Core.dll \
    bin+lib/windows/Qt5Gui.dll \
    bin+lib/windows/Qt5Widgets.dll \
    bin+lib/windows/RoderikBauhn-QT-notepadLight.exe \
    bin+lib/linux/RoderikBauhn-QT-notepadLight

RESOURCES += \
    resourcesshitty.qrc
