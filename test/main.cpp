#include "MainWindow.h"

#include <QApplication>
#include <iostream>
#include <QCoreApplication>
#include <QtGlobal>
#include <QDebug>
#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QHostInfo>


#include <QTimer>
#include <qdatetime.h>

extern int f();
extern int add(int a,int b);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int age = f();
    QString str = QString::number(age);
    w.setWindowTitle("my age is " + str);
    qDebug()<<age;
    qDebug()<<add(11,5);

    return a.exec();
}




