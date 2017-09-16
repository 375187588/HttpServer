/**
 * 	Author 	@ Xiao Weicheng
 * 	Website	@ bestmind.space
 * 	Git 	@ github.com/XiaoWeicheng
 */

#include <bits/stdc++.h>

#include "response/responseHead.h"
#include "DefineAndStatic.h"

responseHead::responseHead()
{
    content_Length=0;
}

responseHead::responseHead(const responseHead& other)
{
    date=other.date;
    content_Length=other.content_Length;
    content_Type=other.content_Type;
    connection=other.connection;
}

std::string responseHead::server="MyHttpServer";

responseHead& responseHead::operator=(const responseHead& rhs)
{
    if(this==&rhs)return *this;
    date=rhs.date;
    content_Length=rhs.content_Length;
    content_Type=rhs.content_Type;
    connection=rhs.connection;
    return *this;
}

std::ostream& operator<<(std::ostream &out,const responseHead& respsHead)
{
    out<<DATE<<" "<<respsHead.date<<std::endl
        <<SERV<<" "<<respsHead.server<<std::endl
        <<CONN<<" "<<respsHead.connection<<std::endl;
    if(respsHead.content_Length)
        out<<CNTL<<" "<<respsHead.content_Length<<std::endl;
    if(respsHead.content_Type.length())
        out<<CNTT<<" "<<respsHead.content_Type<<std::endl;
    return out;
}
