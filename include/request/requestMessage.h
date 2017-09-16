/**
 * 	Author 	@ Xiao Weicheng
 * 	Website	@ bestmind.space
 * 	Git 	@ github.com/XiaoWeicheng
 */

#ifndef REQUESTMESSAGE_H
#define REQUESTMESSAGE_H

#include "requestLine.h"
#include "requestHead.h"

class requestMessage
{
    public:
        /** Default constructor */
        requestMessage();
        /** Copy constructor
         *  \param other Object to copy from
         */
        requestMessage(const requestMessage& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        requestMessage& operator=(const requestMessage& other);

        /** Access reqstLine
         * \return The current value of reqstLine
         */
        requestLine GetreqstLine() { return reqstLine; }
        /** Set reqstLine
         * \param val New value to set
         */
        void SetreqstLine(requestLine val) { reqstLine = val; }
        /** Access reqstHead
         * \return The current value of reqstHead
         */
        requestHead GetreqstHead() { return reqstHead; }
        /** Set reqstHead
         * \param val New value to set
         */
        void SetreqstHead(requestHead val) { reqstHead = val; }

        /** input function*/
        friend std::istream& operator>>(std::istream &in,requestMessage& reqstMsg);
        /** output function*/
        friend std::ostream& operator<<(std::ostream &out,const requestMessage& reqstMsg);

    protected:

    private:
        requestLine reqstLine; //!< Member variable "reqstLine"
        requestHead reqstHead; //!< Member variable "reqstHead"
};

#endif // REQUESTMESSAGE_H
