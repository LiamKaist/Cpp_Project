#ifndef SENSOR_H
#define SENSOR_H

//Toujours mettre les ifndef etc 

class Sensor{

    private:

    //Attributs virtuels pas possibles 
    static int sensorNbr; //Dénote le nombre total des sensors

    public:

    Sensor();

    virtual void displayData()=0;
    virtual void retrieveData()=0;

};

#endif