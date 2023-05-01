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
            
            void connectToHost();
            std::string retrieveMessage();

        private:

            std::string IPaddress;
            long port;
            std::string incomingMessage;
            int incomingSize;
            WiFiClient * client;
    };
}
























#endif