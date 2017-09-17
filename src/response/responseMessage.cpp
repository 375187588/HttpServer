/**
 * 	Author 	@ Xiao Weicheng
 * 	Website	@ bestmind.space
 * 	Git 	@ github.com/XiaoWeicheng
 */

#include <bits/stdc++.h>
#include <ctime>

#include "response/responseMessage.h"
#include "staticData.h"
#include "DefineAndStatic.h"
#include "net.h"

responseMessage::responseMessage()
{

}

responseMessage::responseMessage(const responseMessage& other)
{
    respsLine=other.respsLine;
    respsHead=other.respsHead;
    filePath=other.filePath;
}

responseMessage& responseMessage::operator=(const responseMessage& rhs)
{
    if(this==&rhs)return *this;
    respsLine=rhs.respsLine;
    respsHead=rhs.respsHead;
    filePath=rhs.filePath;
    return *this;
}

void responseMessage::init(requestMessage& reqstMsg)
{
    respsLine.Setversion(reqstMsg.GetreqstLine().Getversion());

    filePath=WEB_ROOT+reqstMsg.GetreqstLine().Geturi();

    if(staticData::getsData()->Method.count(reqstMsg.GetreqstLine().Getmethod().c_str())>0)
    {
        respsLine.SetstatusCode(501);
        respsLine.Setstatus("Not Implemented");
    }
    else
    {
        if(filePath.rfind('/')==filePath.length()-1) filePath+="index.html";
        if(access(filePath.c_str(),F_OK)==-1)
            respsLine.SetstatusCode(404),respsLine.Setstatus(staticData::getsData()->StatusMsg[404]),filePath="";
        else
            respsLine.SetstatusCode(200),respsLine.Setstatus(staticData::getsData()->StatusMsg[200]);
    }

    char date[40];
    time_t rawtime;
    struct tm * ptm;
    time ( &rawtime );
    ptm = gmtime ( &rawtime );
    strftime(date,40,"%a,%d%b%Y%TGMT",ptm);
    respsHead.Setdate(date);

    respsHead.Setconnection(reqstMsg.GetreqstHead().Getconnection());
    std::string ftype=filePath.substr(filePath.rfind('.')+1);

    respsHead.Setcontent_Type(staticData::getsData()->MIME[ftype]);
    if(respsLine.GetstatusCode()==200)
    {
        std::ifstream reqstFile(filePath,std::ifstream::binary);

        reqstFile.seekg(0,reqstFile.end);
        respsHead.Setcontent_Length(reqstFile.tellg());
        reqstFile.close();
    }
}

std::ostream& operator<<(std::ostream &out,const responseMessage& respsMsg)
{
    return out<<respsMsg.respsLine<<std::endl<<respsMsg.respsHead<<std::endl;
}
