#include "MainWindow.h"

#include <QApplication>
#include <iostream>
#include <QCoreApplication>
#include <QtGlobal>
#include <QDebug>

typedef struct Header
{
    int channel;
    int type;
}Headr;

typedef struct Msg
{
    Header header;
    char content[128];
    friend QDebug operator << (QDebug os,Msg msg)
    {
        os<<"("<< " channel:"<<msg.header.channel<<" type:"<<msg.header.type<<" content:"<<msg.content<<" )";
        return os;
    }
}Msg;

typedef struct PeerMsg
{
    PeerMsg(const int &ip,const int &por)
    {
        ipV4 = ip;
        port = por;
    }

    int ipV4;
    int port;
    friend QDebug operator << (QDebug os,PeerMsg msg)
    {
        os<<"( "<<" ipV4:"<<QString::number(msg.ipV4)<< "port:"<<QString::number(msg.port)<<" )";
        return os;
    }
}PeerMsg;


int main(int argc, char *argv[])
{
    Msg msg;
    msg.header.channel =1001;
    msg.header.type = 1;
    strcpy(msg.content,"ABCDEFG");
    qDebug()<<msg;           //return (  channel: 1001  type: 1  content: ABCDEFG  )

    QByteArray array;
    array.append((char*)&msg,sizeof(msg));
    Msg *getMsg = (Msg*)array.data();
    qDebug()<<*getMsg;      //return (  channel: 1001  type: 1  content: ABCDEFG  )

    QByteArray totalByte;
    PeerMsg peerMsg(123456,10086);

    totalByte.append((char*)&peerMsg,sizeof(PeerMsg));
    totalByte.append(array,array.size());

    PeerMsg *getByte = (PeerMsg*)totalByte.data();
    qDebug()<<*getByte;  //return (   ipV4: "123456" port: "10086"  )

    QByteArray contentmsg = totalByte.right(totalByte.size()-sizeof(*getByte));
    Msg *getMsg2 = (Msg*)contentmsg.data();
    qDebug()<<*getMsg2;  //return (  channel: 1001  type: 1  content: ABCDEFG  )

    return 0;
}

//void test()
//{
//    puts("Hello World1\n");
//    printf("Hello World2\n");
//    std::cout<<"Hello World3\n";
//    qDebug()<<"Hello World4\n";
//}

//    QApplication a(argc, argv);
//    test();
//    MainWindow w;
//    w.show();
//    return a.exec();
