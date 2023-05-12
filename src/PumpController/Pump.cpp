#include "Pump.hpp"



#include <Arduino.h>
#include <iostream>


//Instantiate the pump with its pin , set to OUTPUT Mode
Pump::Pump(uint8_t pin){
    pinMode(pin,OUTPUT);
    this->pin= pin;
}

//Basic signal testing 
void Pump::sendSignal(){
    digitalWrite(this->pin,HIGH);
    delay(1000);
    digitalWrite(this->pin,LOW);
}

void Pump::sendSignal(unsigned long durationMs){
    digitalWrite(this->pin,HIGH);
    delay(durationMs);
    digitalWrite(this->pin,LOW);
}

void Pump::dispenseLiquid(unsigned long volume){
    unsigned long computedDuration = volume*(7250/300);
    Pump::sendSignal(computedDuration);
}

