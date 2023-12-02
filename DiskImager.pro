QT = core gui widgets

CONFIG += c++17

HEADERS += disk.h \
           mainwindow.h \
           droppablelineedit.h \
           elapsedtimer.h

SOURCES += disk.cpp \
           main.cpp \
           mainwindow.cpp \
           droppablelineedit.cpp \
           elapsedtimer.cpp

FORMS += mainwindow.ui

RESOURCES += res.qrc

TRANSLATIONS = zh_cn.ts

RC_ICONS = images/Win32DiskImager.ico

VERSION = 1.0
VERSTR = '\\"$${VERSION}\\"'
DEFINES += VER=\"$${VERSTR}\"
DEFINES += WINVER=0x0601
DEFINES += _WIN32_WINNT=0x0601
QMAKE_TARGET_PRODUCT = "Win32 Image Writer"
QMAKE_TARGET_DESCRIPTION = "Image Writer for Windows to write USB and SD images"
QMAKE_TARGET_COPYRIGHT = "Copyright (C) 2009-2017 Windows ImageWriter Team"

QMAKE_LFLAGS += /MANIFESTUAC:\"level=\'requireAdministrator\' uiAccess=\'false\'\"
