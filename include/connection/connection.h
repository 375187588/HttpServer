#ifndef CONNECTION_H
#define CONNECTION_H

#include "request/requestMessage.h"
#include "response/responseMessage.h"

class connection
{
    public:
        /** Default constructor */
        connection(int client_FD){ this->client_FD=client_FD; }

        void handle();

    protected:

    private:
        int client_FD;
        char recv_Buff[1025];
        int recv_Cnt;
        std::string recv_Str;
        requestMessage reqstMsg;
        char send_Buff[1024];
        std::string send_Str;
        responseMessage respsMsg;
        std::stringstream sstream;
        std::ifstream reqstFile;

        void getReqst();
        void sendResps();
        void sendContent();
};

#endif // CONNECTION_H
