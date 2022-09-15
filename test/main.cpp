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
#include <errno.h>
#include <limits.h>
#include <sched.h>
#include <signal.h>

extern int f();
extern int add(int a,int b);

#define handle_error_en(en,msg) do {errno = en;perror(msg);exit(EXIT_FAILURE);} while(0)
#define PTHREAD_NUM 2

void mycleanfunc(void *arg)
{
    printf("mycleanfunc:%d\n",*((int *)arg));
}

void *thrfunc1(void *arg)
{
    int m = 1,n=2;
    printf("thrfunc1 comes\n");
    pthread_cleanup_push(mycleanfunc,&m);
    pthread_cleanup_push(mycleanfunc,&n);
    pthread_cleanup_pop(1);
    return (void *)0;
    pthread_cleanup_pop(0);
}

void *thrfunc2(void *arg)
{
    int m =2;
    printf("thrfunc2 comes\n");
    pthread_cleanup_push(mycleanfunc,&m);
    return(void *)0;
    pthread_cleanup_pop(0);
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    pthread_t pid1,pid2;
    int res;

    res=pthread_create(&pid1,NULL,thrfunc1,NULL);
    if(res)
    {
        printf("pthread_create failed:%d\n",strerror(res));
        exit(1);
    }
    pthread_join(pid1,NULL);

//    res=pthread_create(&pid2,NULL,thrfunc2,NULL);
//    if(res)
//    {
//        printf("pthread_create failed:%d\n",strerror(res));
//        exit(1);
//    }
//    pthread_join(pid2,NULL);


    return a.exec();
}




