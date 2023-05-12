#include "http_tcpServer_linux.h"
#include <fstream>
#include <sstream> //FOr the osstream 



namespace http
{
    TcpServer::TcpServer(std::string ip_address, int port ,int choice)
    :m_ip_address(ip_address),m_port(port),m_socket(),m_incomingMessage()
    ,m_socketAddress(),m_socketAddress_len(sizeof(m_socketAddress))
    ,m_serverMessage(buildResponse(choice))
    {
        //Initializing the sockaddr object
        m_socketAddress.sin_family = AF_INET; 
        m_socketAddress.sin_port = htons(m_port);
        m_socketAddress.sin_addr.s_addr = inet_addr(m_ip_address.c_str());
        

        startServer();
        startListen();
        acceptConnection();
        readIncoming();
        sendResponse();
    }

    TcpServer::~TcpServer()
    {
        closeServer();
    }

    int TcpServer::startServer()
    {
        this->m_socket= socket(AF_INET,SOCK_STREAM,0);
        if (m_socket < 0)
        {
            HTTPerror error(1); //Throwing an exception defined in HTTPerror
            throw(error);
        }

        if (bind(m_socket,(sockaddr *)&m_socketAddress,m_socketAddress_len)<0)
        {
            HTTPerror error(2);
            throw(error);
        }
        
        
        return 0;
    }

    void TcpServer::closeServer()
    {
        close(this->m_socket); //from unistd
        close(this->new_socket); 
        exit(0);
    }

    void TcpServer::startListen()
    {
        if (listen(this->m_socket, 20) < 0)
        {
            HTTPerror error(3);
            throw(error);
        }

        std::cout<< "Listening on :" << inet_ntoa(m_socketAddress.sin_addr) << "PORT:" << ntohs(m_socketAddress.sin_port) << "\n";

    }

    void TcpServer::acceptConnection()
    {
        this->new_socket= accept(m_socket,(sockaddr *)&m_socketAddress, &m_socketAddress_len);
        if (this->new_socket < 0)
        {
            HTTPerror error(4);
            throw(error);
        }
    }

    void TcpServer::readIncoming()
    {
        const int BUFFER_SIZE = 30720;
        char buffer[BUFFER_SIZE] = {0};
        int bytesReceived;
        bytesReceived = read(this->new_socket, buffer, BUFFER_SIZE);
        if (bytesReceived < 0)
        {
            HTTPerror error(5);
            throw(error);
        }
    }


    std::string TcpServer::buildResponse(int choice)
    {
        /*std::string htmlFile = "<!DOCTYPE html><html lang=\"en\"><body><h1> HOME </h1><p> Hello from your Server :) </p></body></html>";
        std::ostringstream ss;
        ss << "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: " << htmlFile.size() << "\n\n"
           << htmlFile;

        return ss.str();*/
        std::ifstream myFile_Handler;
        std::ostringstream ss;
        std::string myLine;

        if (choice == 1){ //To get the volume requested
            myFile_Handler.open("../MP4Transfer/Finalfile.txt");
            if(myFile_Handler.is_open())
            {
            // Keep reading the file
            while(getline(myFile_Handler, myLine))
            {
                // print the line on the standard output
                ss << myLine << std::endl;
            }
            // File Close
            myFile_Handler.close();
            }
            else
            {
                HTTPerror error(7);
                throw(error);
            }
        } else if (choice == 2) { // TO get the text from chatGPT
            myFile_Handler.open("../MP4Transfer/file.txt");
            if(myFile_Handler.is_open())
            {
            // Keep reading the file
            while(getline(myFile_Handler, myLine))
            {
                // print the line on the standard output
                ss << myLine << std::endl;
            }
            // File Close
            myFile_Handler.close();
            }
            else
            {
                HTTPerror error(7);
                throw(error);
            }
        } else {
            HTTPerror error(7);
            throw(error);
        }
        return ss.str();
    }




    void TcpServer::sendResponse()
    {
        long bytesSent;
        std::string size = std::to_string(m_serverMessage.size());
        bytesSent =  write(new_socket, (size).c_str(), 3);
        bytesSent = write(new_socket, m_serverMessage.c_str(), m_serverMessage.size());
        if (bytesSent == m_serverMessage.size())
        {
            std::cout<< "Server response sent to client";
        }
        else
        {
            HTTPerror error(6);
            throw(error);
        }
    }
    
} // namespace http

//g++ -Wall server_linux.cpp http_tcpServer_linux.cpp HTTPerror.cpp -o server_linux THis is to compile the code

