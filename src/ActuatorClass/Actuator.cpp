#include "Actuator.h"
#include <iostream>

int Actuator::actuatorNbr=0;

Actuator::Actuator(){ //Definition du code à l'interieur du constructeur
    Actuator::actuatorNbr++;
}

Actuator::~Actuator(){
    Actuator::actuatorNbr--;
}