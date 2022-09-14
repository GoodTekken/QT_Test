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

#include <unistd.h>

extern int f();
extern int add(int a,int b);


void *thfunc(void *arg)
{
    printf("in thrunc\n");
    return (void*)0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    pthread_t tidp;
    int ret;
    ret = pthread_create(&tidp,NULL,thfunc,NULL);
    if(ret)
    {
        printf("pthread_create failed:%d\n",ret);
        return -1;
    }
    sleep(1);
    printf("in main:thread id created\n");
    return a.exec();
}




