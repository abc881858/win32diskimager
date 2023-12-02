#ifndef WINVER
#define WINVER 0x0601
#endif

#include <QApplication>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <winioctl.h>
#include "disk.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QTranslator translator;
    translator.load(":/zh_cn.qm");

    QApplication app(argc, argv);
    app.setApplicationDisplayName("1.0");
    app.installTranslator(&translator);

    MainWindow* mainwindow = MainWindow::getInstance();
    mainwindow->show();
    return app.exec();
}
