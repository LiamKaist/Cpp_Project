#include "WiFi_client.h"
#include <sstream>

namespace customwificlient
{
    CustomWiFiClient::CustomWiFiClient(std::string hostAddress,long hostPort)
    {
        this->IPaddress= hostAddress;
        this->port = hostPort;
        this->client = new WiFiClient();
    }

    CustomWiFiClient::~CustomWiFiClient()
    {
        ~WiFiClient();
    }


    void CustomWiFiClient::connectToHost()
    {
        this->client->connect((this->IPaddress).c_str(),this->port);
    }

    std::string CustomWiFiClient::retrieveMessage()
    {
        std::ostringstream ss;
        this->client->write(1); //To receive the message from my own server 
        char buf1[3]= {0};
        this->client->read(buf1,3);
        this->incomingSize = std::stoi(buf1);

        char buf[incomingSize]= {0};
        this->client->read(buf,incomingSize);
        ss << buf;
        return ss.str();
        
    }


}
