#include "http_tcpClient_linux.h"

string hello = "Hello from client";
namespace http
{
    
    TcpClient::TcpClient()
    {
        
        if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            cout << "\n Socket creation error \n";
            exit(-1);
        }
        serv_addr.sin_addr.s_addr=inet_addr("192.168.156.61"); //Address of my computer when connected to my wifi hotspot, may vary
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(8080);

        startConnection();
        clientMessage=retrieveMessage();

    }

    TcpClient::~TcpClient()
    {
        // closing the connected socket
        close(client_fd);
    }

    void TcpClient::startConnection()
    {
        if ((connect(client_fd, (struct sockaddr*)&serv_addr,sizeof(serv_addr)))< 0) {
        cout << "\nConnection Failed \n";
        exit(-1);
        }
    }

    string TcpClient::retrieveMessage()
    {
        ostringstream ss;
        char buffer[30000] = { 0 };
        write(client_fd, hello.c_str(), sizeof(hello));
        ss << "The message: ";
        while((valread = read(client_fd, buffer, 1024))>0)
        {
            string str = buffer;
            ss << str;
        }
        cout << ss.str() << endl;
        return ss.str();
    }
}
