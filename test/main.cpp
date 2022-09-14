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
    std::cout<<("sub thread is running\n");
    return (void*)0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    pthread_t thread_id;
    pthread_attr_t thread_attr;
    struct sched_param thread_param;
    size_t stack_size;
    int res;
    res = pthread_attr_init(&thread_attr);
    if(res)
    {
        printf("pthread_attr_init failed:%d\n",res);
    }

    res = pthread_attr_setdetachstate(&thread_attr,PTHREAD_CREATE_DETACHED);
    if(res)
    {
        printf("pthread_attr_setdetachedstate failed:%d\n",res);
    }


    res=pthread_create(&thread_id,&thread_attr,thfunc,NULL);
    if(res)
    {
        printf("pthread_create failed:%d\n",res);
    }

    printf("main thread will exit\n");

    sleep(1);
    return a.exec();
}




