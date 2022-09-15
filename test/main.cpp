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

extern int f();
extern int add(int a,int b);

#define handle_error_en(en,msg) do {errno = en;perror(msg);exit(EXIT_FAILURE);} while(0)

static void *thread_start(void *arg)
{
    int i,res;
    size_t stack_size;
    pthread_attr_t gattr;

    res = pthread_getattr_np(pthread_self(),&gattr);
    if(res)
    {
        printf("pthread_getattr_np failed\n");
    }

    res = pthread_attr_getstacksize(&gattr,&stack_size);
    if(res)
    {
        printf("pthread_attr_getstacksize failed\n");
    }
    printf("Default stack size is %u byte; \n minimun is %u byte\n",stack_size,PTHREAD_STACK_MIN);

    pthread_attr_destroy(&gattr);
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    pthread_t thread_id;
    int s;
    s = pthread_create(&thread_id,NULL,&thread_start,NULL);
    if(s!=0)
    {
        printf("pthread_create failed\n");
        return 0;
    }
    pthread_join(thread_id,NULL);



    return a.exec();
}




