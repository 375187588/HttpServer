/**
 * 	Author 	@ Xiao Weicheng
 * 	Website	@ bestmind.space
 * 	Git 	@ github.com/XiaoWeicheng
 */

#include <bits/stdc++.h>

#include "response/responseLine.h"
#include "DefineAndStatic.h"

responseLine::responseLine()
{

}
responseLine::responseLine(const responseLine& other)
{
    version=other.version;
    statusCode=other.statusCode;
    status=other.status;
}

responseLine& responseLine::operator=(const responseLine& rhs)
{
    if (this == &rhs) return *this;
    version=rhs.version;
    statusCode=rhs.statusCode;
    status=rhs.status;
    return *this;
}

std::ostream& operator<<(std::ostream &out,const responseLine& respsLine)
{
    return out<<respsLine.version<<" "<<respsLine.statusCode<<" "<<respsLine.status;
}
