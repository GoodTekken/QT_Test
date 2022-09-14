#include "MainWindow.h"

#include <QApplication>
#include <iostream>
#include <QCoreApplication>
#include <QtGlobal>
#include <QDebug>


int main(int argc, char *argv[])
{
    char g ='g';

    char han = '汉';

    qDebug()<<g;
    qDebug()<<han;

    return 0;
}
//        QApplication a(argc, argv);
//        MainWindow w;
//        w.show();
//        return a.exec();


