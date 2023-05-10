#include "Pump.hpp"



#include <Arduino.h>
#include <iostream>


Pump::Pump(){

}


//Instantiate the pump with its pin , set to OUTPUT Mode
Pump::Pump(uint8_t pin){
    pinMode(pin,OUTPUT);
    this->pin= pin;
    this->previousMillis=0UL;
    this->interval = 7250UL;
}

void Pump::sendSignal(){

    std::cout<<"In sendSignal()";
    digitalWrite(this->pin,HIGH);

    this->previousMillis=millis();
    while(millis() < this->previousMillis + this->interval){yield();} //Yield is used to reset the watchdog timer, it could be possible to change the watchdog timer's threshold}


    digitalWrite(this->pin,LOW);
    
    //More timing precision using millis()
    this->previousMillis=millis();
    while(millis() < this->previousMillis + this->interval){yield();}

}

