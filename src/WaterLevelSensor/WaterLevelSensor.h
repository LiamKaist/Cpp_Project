#ifndef WATERLEVELSENSOR_H
#define WATERLEVELSENSOR_H

#include <Sensor.hpp>
#include <Wire.h>
#include <iostream>


class WaterLevelSensor : public Sensor {

    public :

        WaterLevelSensor();
        void displayData();
        int getPercentage();
        void calibrate();
        
    private :
        void getLow8SectionValue();
        void getHigh12SectionValue();
        void retrieveData();
        unsigned long waterLevel;
        unsigned char low_data[8];
        unsigned char high_data[12];
};



#endif