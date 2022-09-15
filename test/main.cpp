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

static void on_signal_term(int sig)
{
    std::cout<<"sub thread will exit"<<std::endl;
    pthread_exit(NULL);
}

void *thrfunc(void *arg)
{
//    signal(SIGQUIT,on_signal_term);
    int tm = 50;
    while(tm>48)
    {
        std::cout<<"thrfunc--left:"<<tm<<"s--"<<std::endl;
        sleep(1);
        tm--;
    }
    return(void*)0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    pthread_t pid;
    int res;

    res = pthread_create(&pid,NULL,thrfunc,NULL);
    sleep(5);

    int kill_rc = pthread_kill(pid,0);
    if(kill_rc == ESRCH)
    {
        std::cout<<"the specified thread did not exist or already quit\n";
    }
    else if(kill_rc== EINVAL)
    {
        std::cout<<"siganl is invaid\n";

    }
    else
    {
        std::cout<<"the specified thread is alive\n";
    }

    return a.exec();
}




