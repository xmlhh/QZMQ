#-------------------------------------------------
#
# Project created by QtCreator 2017-12-21T15:52:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QZmqClient
TEMPLATE = app


SOURCES += main.cpp\
        LeonWgt.cpp

HEADERS  += LeonWgt.h

FORMS    += LeonWgt.ui

RESOURCES += \
    res.qrc


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Lib/ -lQBGUILIB
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Lib/ -lQBGUILIBd

INCLUDEPATH += $$PWD/../Lib
DEPENDPATH += $$PWD/../Lib
