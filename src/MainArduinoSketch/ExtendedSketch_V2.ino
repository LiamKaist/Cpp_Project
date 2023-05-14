//Includes
#include <WiFi_client.h>
#include <iostream>
#include <U8g2lib.h>
#include <Oled.hpp>
#include <list>
#include <Pump.hpp>
#include <WaterLevelSensor.h>

//Creating an instance of pump
Pump* pump1= new Pump(D8);
//Value to store the input of Pump
int volume;

//Creating instance of water level sensor

WaterLevelSensor * WLsensor = new WaterLevelSensor();


//Global variables
const char * SSID = "Liam";
const char *  password= "Liamliam";
using namespace std;
string incomingMessage;
const char * IP ="192.168.234.28";
string IPaddress = IP;
list<string> sentenceList;

// Set your Static IP address & set your Gateway IP address
IPAddress local_IP(192, 168, 234, 184);
IPAddress gateway(192, 168, 234, 1);
IPAddress subnet(255, 255, 255, 0);


//Socket Client
using namespace customwificlient;
CustomWiFiClient* client1 =new CustomWiFiClient(IPaddress,8080);
CustomWiFiClient* client2 =new CustomWiFiClient(IPaddress,8081);
//Oled display
Oled  oledDisplay(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  Serial.begin(115200);
  Serial.println();
  oledDisplay.begin();

  // Configures static IP address
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }
  
  Serial.print("Connecting to WiFi");
  Serial.print(SSID);
  WiFi.begin(SSID,password);

  Serial.println();
  Serial.print("Connecting");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println(".");
  }
  WLsensor->calibrate();
}

void loop() {
  client1->connectToHost();
  incomingMessage=client1->retrieveMessage();
  if (incomingMessage.size() == 3){
    volume = atoi(incomingMessage.c_str());
  }else{
    volume = atoi((incomingMessage.substr(0,3)).c_str());
  }
  string prefix = "Volume: ";
  oledDisplay<<(prefix + incomingMessage);
  oledDisplay.clearDisplay();
  if (volume < 400){
    pump1->dispenseLiquid(volume);
  }
  client2->connectToHost();
  incomingMessage=client2->retrieveMessage();
  oledDisplay<<incomingMessage;
  oledDisplay.clearDisplay();
  int percentage;
  percentage=WLsensor->getPercentage();
  if (percentage < 10){
    oledDisplay<<"Warning! WATERLEVELLOW";
  }
}