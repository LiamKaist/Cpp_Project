
#ifndef ACTUATOR_H
#define ACTUATOR_H



class Actuator{

    private:

    //Attributs virtuels pas possibles 
    static int actuatorNbr; //Dénote le nombre total des actuators

    public:

    Actuator();
    ~Actuator();
    virtual void sendSignal()=0;
};


#endif