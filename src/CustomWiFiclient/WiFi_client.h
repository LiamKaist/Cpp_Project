#ifndef WIFICLIENT_H
#define WIFICLIENT_H

#include <ESP8266WiFi.h>
#include <iostream>

namespace customwificlient 
{
    class CustomWiFiClient:public WiFiClient
    {
        public:

            CustomWiFiClient(std::string hostAddress,long hostPort); //IPaddress and port initialized here
            ~CustomWiFiClient();
            std::string IPaddress;
            void connectToHost();
            std::string retrieveMessage();

        private:

            
            long port;
            std::string incomingMessage;
            int incomingSize;
            char * buf; //Buffer to retrieve messages
    };
}
























#endif