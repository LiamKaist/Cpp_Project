#ifndef HTTP_TCPSERVER_LINUX
#define HTTP_TCPSERVER_LINUX

#include <sys/socket.h>
#include <arpa/inet.h>
#include "HTTPerror.h"
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <iostream>

namespace http
{
    class TcpServer
    {
    public: 
        TcpServer(std::string ip_address, int port);
        ~TcpServer();
        

    private:
        std::string m_ip_address;
        int m_port;
        int m_socket;
        int new_socket;
        long m_incomingMessage;
        struct sockaddr_in m_socketAddress;
        unsigned int m_socketAddress_len;
        std::string m_serverMessage;

        int startServer();
        void closeServer();
        void startListen();
        void acceptConnection();
        void readIncoming();
        std::string buildResponse();
        void sendResponse();
        

    };
} //Namespace http

#endif