/**
 * 	Author 	@ Xiao Weicheng
 * 	Website	@ bestmind.space
 * 	Git 	@ github.com/XiaoWeicheng
 */

#include <bits/stdc++.h>

#include "request/requestHead.h"
#include "DefineAndStatic.h"

requestHead::requestHead()
{
    //ctor
}

requestHead::requestHead(const requestHead& other)
{
    host=other.host;
    user_Agent=other.user_Agent;
    accept=other.accept;
    accept_Encoding=other.accept_Encoding;
    accept_Language=other.accept_Language;
    connection=other.connection;
}

requestHead& requestHead::operator=(const requestHead& rhs)
{
    if (this == &rhs) return *this;
    host=rhs.host;
    user_Agent=rhs.user_Agent;
    accept=rhs.accept;
    accept_Encoding=rhs.accept_Encoding;
    accept_Language=rhs.accept_Language;
    connection=rhs.connection;
    return *this;
}

std::istream& operator>>(std::istream &in,requestHead& reqstHead)
{
    char tmpC;
    std::string tmpStr;
    while(in)
    {
        in>>tmpStr;
        if(tmpStr==HOST)
        {
            in.get(tmpC);
            getline(in,reqstHead.host);
        }
        else if(tmpStr==UA)
        {
            in.get(tmpC);
            getline(in,reqstHead.user_Agent);
        }
        else if(tmpStr==AC)
        {
            in.get(tmpC);
            getline(in,reqstHead.accept);
        }
        else if(tmpStr==ACE)
        {
            in.get(tmpC);
            getline(in,reqstHead.accept_Encoding);
        }
        else if(tmpStr==ACL)
        {
            in.get(tmpC);
            getline(in,reqstHead.accept_Language);
        }
        else if(tmpStr==CONN)
        {
            in.get(tmpC);
            getline(in,reqstHead.connection);
        }
        else
        {
            getline(in,tmpStr);
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream &out,const requestHead& reqstHead)
{
    return out<<HOST<<" "<<reqstHead.host<<std::endl
        <<UA<<" "<<reqstHead.user_Agent<<std::endl
        <<AC<<" "<<reqstHead.accept<<std::endl
        <<ACE<<" "<<reqstHead.accept_Encoding<<std::endl
        <<ACL<<" "<<reqstHead.accept_Language<<std::endl
        <<CONN<<" "<<reqstHead.connection<<std::endl;
}
