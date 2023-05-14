#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>


class Sensor{

    private:

    //Attributs virtuels pas possibles 
    static int sensorNbr; //Dénote le nombre total des sensors

    public:

    Sensor();
    ~Sensor();

    virtual void retrieveData()=0;

};

#endif