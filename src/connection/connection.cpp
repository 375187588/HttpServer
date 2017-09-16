/**
 * 	Author 	@ Xiao Weicheng
 * 	Website	@ bestmind.space
 * 	Git 	@ github.com/XiaoWeicheng
 */
#include <bits/stdc++.h>

#include "DefineAndStatic.h"
#include "net.h"
#include "connection/connection.h"

using namespace std;

void connection::handle()
{
    recv_Cnt=0;
    while(1)
    {
        recv_Cnt=read(client_FD,recv_Buff,1024);
        if(recv_Cnt>0)
        {
            recv_Str.append(recv_Buff,recv_Cnt);
        }
        if(recv_Cnt<1024&&recv_Str.length())
        {
            getReqst();
            cout<<"Requset:"<<endl<<reqstMsg;
            respsMsg.init(reqstMsg);
            cout<<"Response:"<<endl<<respsMsg;
            sendResps();
            sendContent();
            close(client_FD);
            break;
        }
    }
}

void connection::getReqst()
{
    sstream.str(recv_Str);
    sstream>>reqstMsg;
}

void connection::sendResps()
{
    sstream.str("");
    sstream<<respsMsg;
    send_Str=sstream.str();
    write(client_FD,send_Str.c_str(),send_Str.length());
}

void connection::sendContent()
{
    reqstFile.open(respsMsg.GetfilePath(),ios::binary);
    if(reqstFile&&reqstFile.good())
    {
        while(!(reqstFile.eof()))
        {
            reqstFile.read(send_Buff,1024);
            if(reqstFile)
                write(client_FD,send_Buff,1024);
            else
                write(client_FD,send_Buff,reqstFile.gcount());
            cout<<send_Buff;
        }
        cout<<endl;
        reqstFile.close();
    }
}
