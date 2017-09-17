/**
 * 	Author 	@ Xiao Weicheng
 * 	Website	@ bestmind.space
 * 	Git 	@ github.com/XiaoWeicheng
 */

#include <bits/stdc++.h>

#include "DefineAndStatic.h"
#include "server/server.h"

using namespace std;

int main()
{
    server *httpServer;

    httpServer = server::getServer();

    httpServer->init();

    httpServer->run();

    return 0;
}
