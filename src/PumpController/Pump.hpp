#ifndef PUMP_H
#define PUMP_H

#include "Actuator.hpp"
#include <stdint.h>


class Pump:public Actuator{

    private:
    uint8_t pin;
    double duration;
    unsigned long previousMillis;
    unsigned long interval;
    unsigned long currentMillis;

  
    public:

    Pump();
    Pump(uint8_t);

    void sendSignal();

    void activatePump();



};





#endif