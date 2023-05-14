//Includes
#include <WiFi_client.h>
#include <iostream>
#include <U8g2lib.h>
#include <Oled.hpp>
#include <list>
#include <Pump.hpp>
#include <WaterLevelSensor.h>

using namespace std;
using namespace customwificlient;

//Variables Globales

int volume;
//Pour se connecter au Wifi
const char * SSID = "Liam";
const char *  password= "Liamliam";
//Pour le client Wifi
const char * IP ="192.168.234.28";
string IPaddress = IP;
string incomingMessage;

// Configuration pour la connexion Wifi

IPAddress local_IP(192, 168, 234, 184);
IPAddress gateway(192, 168, 234, 1);
IPAddress subnet(255, 255, 255, 0);

//Socket Client qui tourne sur l'ESP

CustomWiFiClient* client1 =new CustomWiFiClient(IPaddress,8080);
CustomWiFiClient* client2 =new CustomWiFiClient(IPaddress,8081);

//Creation d'une instance de Pump (Pompe)
Pump* pump1= new Pump(D8);

//Creation d'une instance de Pump water level sensor
WaterLevelSensor * WLsensor = new WaterLevelSensor();

//Creation d'une instance Oled
Oled  oledDisplay(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  Serial.begin(115200);
  // Configuration d'une addresse IP statique pour l'ESP8266
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }
  
  //Connexion au WiFi
  Serial.print("Connecting to WiFi");
  Serial.print(SSID);
  WiFi.begin(SSID,password);

  Serial.println();
  Serial.print("Connecting");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println(".");
  }
  //Mise en place du bus I2C
  Wire.begin();
  WLsensor->begin(Wire); //Wire est créé dans Wire.h
  WLsensor->calibrate();
  oledDisplay.begin();
  //Tentative de calibration du capteur de niveau d'eau lorsque le bac est vide
  WLsensor->calibrate();
}

void loop() {
  
  //Connexion au premier serveur qui contient la donnée renvoyée par ChatGPT
  client1->connectToHost();
  incomingMessage=client1->retrieveMessage();
  if (incomingMessage.size() == 3){
    volume = atoi(incomingMessage.c_str());
  }else{
    volume = atoi((incomingMessage.substr(0,3)).c_str());
  }
  
  //Affichage de la donnée en mL
  string prefix = "Volume: ";
  oledDisplay<<(prefix + incomingMessage);
  if (volume < 400){
    //Envoi de la commande à la pompe 
    pump1->dispenseLiquid(volume);
  }
  
  //Connexion au second serveur contenant la voix transcrite, qui est ensuite récupérée
  client2->connectToHost();
  incomingMessage=client2->retrieveMessage();
  oledDisplay<<incomingMessage;
  
  //Vérification du niveau d'eau après la commande
  int percentage;
  percentage=WLsensor->getPercentage();
  if (percentage < 10){
    oledDisplay<<"Warning! WATERLEVELLOW";
  }
}
