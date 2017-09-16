/**
 * 	Author 	@ Xiao Weicheng
 * 	Website	@ bestmind.space
 * 	Git 	@ github.com/XiaoWeicheng
 */

#include <bits/stdc++.h>
#include <DefineAndStatic.h>
#include "staticDate.h"

using namespace std;

staticDate* staticDate::sd=NULL;

staticDate* staticDate::getsDate()
{
    if(sd==NULL)
        sd=new staticDate();
    return sd;
}

void staticDate::initMIME()
{
    Method.insert("GET");
    Method.insert("HEAD");

    StatusMsg[200]="OK";
    StatusMsg[404]="Not Found";
    StatusMsg[501]="Not Implemented";

    MIME["js"]="application/javascript";
    MIME["json"]="application/json";
    MIME["pdf"]="application/pdf";
    MIME["xml"]="application/xml";
    MIME["zip"]="application/zip";
    MIME["gzip"]="application/gzip";
    MIME["mp4"]="application/mp4";
    MIME["mp3"]="audio/mpeg";
    MIME["ogg"]="application/ogg";
    MIME["wma"]="audio/x-ms-wma";
    MIME["wave"]="audio/vnd.wave";
    MIME["jpe"]="image/jpeg";
    MIME["jpeg"]="image/jpeg";
    MIME["jpg"]="image/jpeg";
    MIME["png"]="image/png";
    MIME["svg"]="image/svg+xml";
    MIME["gif"]="image/gif";
    MIME["webp"]="image/webp";
    MIME["ico"]="image/vnd.microsoft.icon";
    MIME["css"]="text/css";
    MIME["csv"]="text/csv";
    MIME["html"]="text/html";
    MIME["text"]="text/plain";
    MIME["wmv"]="video/x-ms-wmv";
    MIME["mov"]="video/quicktime";
    MIME["mkv"]="video/x-matroska";
}
