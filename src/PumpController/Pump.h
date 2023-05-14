#ifndef PUMP_H
#define PUMP_H

#include <Actuator.h>
#include <stdint.h>
#include <Arduino.h>
#include <iostream>

class Pump:public Actuator{

    private:
    uint8_t pin;
    void sendSignal(unsigned long durationMs);

    public:
    Pump();
    Pump(uint8_t);
    void sendSignal();
    void dispenseLiquid(unsigned long volume);
};

#endif