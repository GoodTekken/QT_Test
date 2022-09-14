#include "MainWindow.h"

#include <QApplication>
#include <iostream>
#include <QCoreApplication>
#include <QtGlobal>
#include <QDebug>
#include <QWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(250,150);
    w.show();
    w.setWindowTitle("Hello world!");

    QWidget *widget = new QWidget;
    widget->resize(250,150);
    widget->show();
    widget->setWindowTitle("widget");
    return a.exec();
}



