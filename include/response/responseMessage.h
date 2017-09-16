/**
 * 	Author 	@ Xiao Weicheng
 * 	Website	@ bestmind.space
 * 	Git 	@ github.com/XiaoWeicheng
 */

#ifndef RESPONSEMESSAGE_H
#define RESPONSEMESSAGE_H

#include "response/responseLine.h"
#include "response/responseHead.h"
#include "request/requestMessage.h"

class responseMessage
{
    public:
        /** Default constructor */
        responseMessage();
        /** Copy constructor
         *  \param other Object to copy from
         */
         responseMessage(const responseMessage& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        responseMessage& operator=(const responseMessage& other);


        friend std::ostream& operator<<(std::ostream &out,const responseMessage& respsMsg);

        std::string& GetfilePath(){ return filePath; }

        void init(requestMessage& reqstMsg);

    protected:

    private:
        responseLine respsLine; //!< Member variable "respsLine"
        responseHead respsHead; //!< Member variable "respsHead"
        std::string filePath;
};

#endif // responseMessage_H
