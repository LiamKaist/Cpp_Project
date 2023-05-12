#include "WiFi_client.h"
#include <sstream>

namespace customwificlient
{
    
    CustomWiFiClient::CustomWiFiClient(std::string hostAddress,long hostPort): WiFiClient()
    {
       
        this->IPaddress= hostAddress;
        this->port = hostPort;
        this->buf = new char[3];
        
    }

    CustomWiFiClient::~CustomWiFiClient()
    {
        ~WiFiClient();
    }


    void CustomWiFiClient::connectToHost()
    {
        while(WiFiClient::connect(IPaddress.c_str(),port) == false)
        { Serial.println("Waiting...");}
        
        WiFiClient::write(1);
            
    }

    std::string CustomWiFiClient::retrieveMessage() {

        
        // Waiting for message availability
        unsigned long previousMillis = millis();
        while((!WiFiClient::available()) && (millis()-previousMillis < 3000) )
        {
            delay(3000);
        }
        if (WiFiClient::available()){
            WiFiClient::read(buf, 3);
            this->incomingSize = std::stoi(buf);
            char* new_buf = new char[incomingSize];
            memset(new_buf, 0, incomingSize); // initialize new buffer to all zeros
            WiFiClient::read(new_buf, incomingSize);
            std::string message(new_buf, incomingSize);
            delete[] buf; // delete old buffer after allocating new one
            buf = new_buf;
            return message;
        }else{
            return "ServerTimeOut";
        }
    }


}
