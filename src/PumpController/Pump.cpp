#include <Pump.h>

Pump::Pump(){
    this->pin = 0;
}
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
    //Calculate the duration of the signal to send to the Pump in order to get <volume> millilitres... Approximately
    unsigned long computedDuration = volume*(7250/300);
    Pump::sendSignal(computedDuration);
}

