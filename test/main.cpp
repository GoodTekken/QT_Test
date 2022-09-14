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
    char *str;
    str = (char*)(arg);
    printf("in thrunc:n=%s\n",str);
    return (void*)0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    pthread_t tidp;
    int ret;
    const char *str = "hello world";
    ret = pthread_create(&tidp,NULL,thfunc,(void*)str);
    if(ret)
    {
        printf("pthread_create failed:%d\n",ret);
        return -1;
    }
//    sleep(1);
    pthread_join(tidp,NULL); //wait for the child process
    printf("in main:thread id created\n");
    return a.exec();
}




