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

typedef struct
{
    int n;
    char *str;
}MYSTRUCT;

void *thfunc(void *arg)
{
    MYSTRUCT *p = (MYSTRUCT*)arg;

    printf("in thrunc:n=%d,str=%s\n",p->n,p->str);
    return (void*)0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    pthread_t tidp;
    int ret;
    MYSTRUCT mystruct;
    mystruct.n = 110;
    mystruct.str ="hello world";
    ret = pthread_create(&tidp,NULL,thfunc,(void*)&mystruct);
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




