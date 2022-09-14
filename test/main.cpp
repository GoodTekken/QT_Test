#include "MainWindow.h"

#include <QApplication>
#include <iostream>
#include <QCoreApplication>
#include <QtGlobal>
#include <QDebug>
#include <QWidget>


#include <QTimer>
#include <qdatetime.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle("Hello world!");
    w.setStyleSheet("background-image:url(:/res/liu.jpeg);border:1px solid black;");
//    w.setStyleSheet(QStringLiteral("background: blue"));
    return a.exec();
}




