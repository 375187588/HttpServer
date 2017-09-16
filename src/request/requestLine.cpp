/**
 * 	Author 	@ Xiao Weicheng
 * 	Website	@ bestmind.space
 * 	Git 	@ github.com/XiaoWeicheng
 */

#include <bits/stdc++.h>

#include "request/requestLine.h"
#include "DefineAndStatic.h"

requestLine::requestLine()
{
    //ctor
}

requestLine::requestLine(const requestLine& other)
{
    method=other.method;
    uri=other.uri;
    version=other.version;
}

requestLine& requestLine::operator=(const requestLine& rhs)
{
    if(this==&rhs)return *this;
    method=rhs.method;
    uri=rhs.uri;
    version=rhs.version;
    return *this;
}

std::istream& operator>>(std::istream &in,requestLine& reqstLine)
{
    return in>>reqstLine.method>>reqstLine.uri>>reqstLine.version;
}

std::ostream& operator<<(std::ostream &out,const requestLine& reqstLine)
{
    return out<<reqstLine.method<<" "<<reqstLine.uri<<" "<<reqstLine.version;
}
