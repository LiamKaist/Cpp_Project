#include "Sensor.hpp" // Différence entre "" et <> , le "" indique que le fichier a inclure est dans le même dossier
#include <iostream>
//Initialisation des constructeurs , des variables etc , il faut commencer par créer le .h ou on definit sans code l'ensemble des classes etc

int Sensor::sensorNbr=0;

Sensor::Sensor(){
    std::cout<< "In sensor constructor" << std::endl;
    Sensor::sensorNbr++;
}




