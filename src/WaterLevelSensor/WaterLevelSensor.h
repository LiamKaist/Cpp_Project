#ifndef WATERLEVELSENSOR_H
#define WATERLEVELSENSOR_H

#include <Sensor.h>
#include <Wire.h>
#include <iostream>

class WaterLevelSensor : public Sensor {

    public :

        WaterLevelSensor();
        ~WaterLevelSensor();
        int getPercentage();
        void begin(TwoWire &I2Cpipe);
        
    private :
        void getLow8SectionValue();
        void getHigh12SectionValue();
        void retrieveData();
        unsigned long waterLevel;
        unsigned char * low_data;
        unsigned char * high_data;
        TwoWire dataBus;
};



#endif