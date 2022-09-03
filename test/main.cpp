#include "MainWindow.h"

#include <QApplication>
#include <iostream>
#include <QCoreApplication>
#include <QtGlobal>
#include <QDebug>


int main(int argc, char *argv[])
{
    //indexOf() forward search
    //int indexof(const QByteArray &ba, int from = 0)
    QByteArray x("sticky question");
    QByteArray y("sti");
    qDebug()<<x.indexOf(y);    //return 0
    qDebug()<<x.indexOf(y,1);  //return 10
    qDebug()<<x.indexOf(y,10); //return 10
    qDebug()<<x.indexOf(y,11); //return -1

    //lastIndexOf() backward search
    //int lastIndecOf(const QByteArray &ba int from = -1)
    x = ("sticky question");
    y = ("s");
    qDebug()<<x.lastIndexOf(y);    //return 10
    qDebug()<<x.lastIndexOf(y,1);  //return 0
    qDebug()<<x.lastIndexOf(y,10); //return 10
    qDebug()<<x.lastIndexOf(y,11); //return 10

    //insert()
    //QByteArray & insert(int i, const QByteArray &ba)
    QByteArray ba("Meal");
    ba.insert(1,QByteArray("ontr"));
    qDebug()<<ba.data();   //return Montreal

    return 0;
}
//        QApplication a(argc, argv);
//        MainWindow w;
//        w.show();
//        return a.exec();


