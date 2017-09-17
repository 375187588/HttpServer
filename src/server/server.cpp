/**
 * 	Author 	@ Xiao Weicheng
 * 	Website	@ bestmind.space
 * 	Git 	@ github.com/XiaoWeicheng
 */
#include <bits/stdc++.h>
#include <thread>

#include "server/server.h"
#include "request/requestMessage.h"
#include "DefineAndStatic.h"
#include "connection/connection.h"

using namespace std;

server* server::serv=NULL;

server::server()
{
    //ctor
}

server* server::getServer()
{
    if(serv==NULL) serv=new server();
    return serv;
}

void server::init()
{
    if(access(WEB_ROOT,F_OK)==-1)
        mkdir(WEB_ROOT,S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);

    server_FD=socket(AF_INET,SOCK_STREAM,0);
    if(server_FD<0)
    {
        cerr<<"Create socket failed"<<endl;
        return ;
    }

    bzero(&server_Addr,sizeof server_Addr);
    server_Addr.sin_family=AF_INET;
    server_Addr.sin_addr.s_addr=htonl(INADDR_ANY);
    server_Addr.sin_port=htons(HTTP_PORT);

    state_Msg=bind(server_FD,(sockaddr*)&server_Addr,sizeof server_Addr);
    if(state_Msg<0)
    {
        cerr<<"Bind failed"<<endl;
        return ;
    }
}

void server::run()
{
    state_Msg=listen(server_FD,1024);
    if(state_Msg<0)
    {
        cerr<<"Listen failed"<<endl;
        return ;
    }
    client_Len=sizeof(sockaddr);
    while(1)
    {
        client_FD=accept(server_FD,(sockaddr*)&client_Addr,&client_Len);
        if(client_FD<0)
        {
            cerr<<"Accept failed"<<endl;
            return ;
        }
        else
        {
            connection conn(client_FD);
            //conn.handle();
            thread(&connection::handle,ref(conn)).join();
        }
    }
    close(server_FD);
}

