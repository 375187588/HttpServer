/**
 * 	Author 	@ Xiao Weicheng
 * 	Website	@ bestmind.space
 * 	Git 	@ github.com/XiaoWeicheng
 */

#include <bits/stdc++.h>

#include "request/requestMessage.h"
#include "DefineAndStatic.h"

requestMessage::requestMessage()
{
    //ctor
}

requestMessage::requestMessage(const requestMessage& other)
{
    reqstLine=other.reqstLine;
    reqstHead=other.reqstHead;
}

requestMessage& requestMessage::operator=(const requestMessage& rhs)
{
    if (this == &rhs) return *this;
    reqstLine=rhs.reqstLine;
    reqstHead=rhs.reqstHead;
    return *this;
}

std::istream& operator>>(std::istream &in,requestMessage& reqstMsg)
{
    return in>>reqstMsg.reqstLine>>reqstMsg.reqstHead;
}

std::ostream& operator<<(std::ostream &out,const requestMessage& reqstMsg)
{
    return out<<reqstMsg.reqstLine<<std::endl<<reqstMsg.reqstHead;
}
