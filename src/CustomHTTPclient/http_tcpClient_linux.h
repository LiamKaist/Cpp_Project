#ifndef HTTP_TCPCLIENT_H
#define HTTP_TCPCLIENT_H
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream> //FOr the osstream 

using namespace std;
namespace http
{
    class TcpClient
    {
    public:
        TcpClient();
        ~TcpClient();

    private:

        struct sockaddr_in serv_addr;
        int valread;
        int client_fd;
        string clientMessage;
        void startConnection();
        string retrieveMessage();
    };
}




#endif