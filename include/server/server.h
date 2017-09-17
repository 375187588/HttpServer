#ifndef SERVER_H
#define SERVER_H

#include "request/requestMessage.h"
#include "response/responseMessage.h"
#include "net.h"

class server
{
    public:
        static server* getServer();

        void init();

        void run();

    protected:

    private:
        /** Default constructor */
        server();

        int server_FD; //!< Member variable "server_FD"
        int client_FD; //!< Member variable "client_FD"
        sockaddr_in server_Addr; //!< Member variable "server_Addr"
        sockaddr_in client_Addr; //!< Member variable "client_Addr"
        socklen_t client_Len; //!< Member variable "client_Len"
        int state_Msg; //!< Member variable "state_Msg"
        static server *serv;
};


#endif // SERVER_H
