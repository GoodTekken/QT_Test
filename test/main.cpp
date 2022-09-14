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

extern int f();
extern int add(int a,int b);

#define handle_error_en(en,msg) do {errno = en;perror(msg);exit(EXIT_FAILURE);} while(0)

static void *thread_start(void *arg)
{
    int i,s;
    pthread_attr_t gattr;

    s = pthread_getattr_np(pthread_self(),&gattr);
    if(s!=0)
        handle_error_en(s,"pthread_getattr_mp");

    printf("Thread's detachstate attributes:\n");

    s = pthread_attr_getdetachstate(&gattr,&i);

    if(s)
        handle_error_en(s,"pthread_attr_getdetachstate");

    printf("Detach state =%s\n",
           (i==PTHREAD_CREATE_DETACHED)?"PTHREAD_CREATE_DETACHED":
           (i==PTHREAD_CREATE_JOINABLE)?"PTHREAD_CREATE_JOINABLE":"???");

    pthread_detach(pthread_self());

    s = pthread_getattr_np(pthread_self(),&gattr);
    if(s!=0)
        handle_error_en(s,"pthread_getattr_mp");

    sleep(5);
    s = pthread_attr_getdetachstate(&gattr,&i);

    if(s)
        handle_error_en(s,"pthread_attr_getdetachstate");

    printf("after pthread_detach state =%s\n",
           (i==PTHREAD_CREATE_DETACHED)?"PTHREAD_CREATE_DETACHED":
           (i==PTHREAD_CREATE_JOINABLE)?"PTHREAD_CREATE_JOINABLE":"???");


    pthread_attr_destroy(&gattr);
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    pthread_t thr;
    int s;
    s = pthread_create(&thr,NULL,&thread_start,NULL);
    if(s!=0)
    {
        handle_error_en(s,"pthread_create failed");
        return 0;
    }

    sleep(2);
    pthread_exit(nullptr);

//    pthread_join(thr,NULL);
    return a.exec();
}




