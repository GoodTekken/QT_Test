#include "MainWindow.h"

#include <QApplication>
#include <iostream>
#include <QCoreApplication>
#include <QtGlobal>
#include <QDebug>


int main(int argc, char *argv[])
{
    QStringList list;
    list<<"Bill Murray"<<"John Doe"<<"Bill Clinton";
    QStringList result;
    result = list.filter("Bill");
    qDebug()<<result;   //("Bill Murray", "Bill Clinton")

    result = list.filter("bill",Qt::CaseInsensitive);
    qDebug()<<result;  //("Bill Murray", "Bill Clinton")
    return 0;
}
//        QApplication a(argc, argv);
//        MainWindow w;
//        w.show();
//        return a.exec();


