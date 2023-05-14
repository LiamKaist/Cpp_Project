# Cpp_Projet
Github du Projet C++ (Liam CHRISMENT Johann COURAND)

## Présentation du projet. 

### Introduction. 

Notre projet consiste à concevoir un distributeur automatique d'eau qui permettra aux utilisateurs de s'hydrater facilement. Le système sera capable de recevoir des indications de l'utilisateur, telles que "Je suis assoiffé, cela fait depuis midi que je n'ai pas bu d'eau", et de délivrer une quantité d'eau adaptée à la demande de l'utilisateur.

Le système de distributeur automatique d'eau fonctionne de la manière suivante :

1/ L'utilisateur exprime son besoin en enregistrant sa voix via un téléphone portable.

2/ L'enregistrement vocal est envoyé à un ordinateur via une connexion Wi-Fi.

3/ Le système utilise l'API OpenAI GPT pour traiter l'enregistrement vocal et interpréter le besoin de l'utilisateur en traduisant la voix en quantité d'eau à fournir.

4/ L'ordinateur communique la quantité d'eau nécessaire à la carte électronique ESP via une connexion Wi-Fi.

5/ La carte électronique traite l'information et fournit une commande à une pompe pour fournir l'eau dans un gobelet.

### Schéma de principe du système. 

![Alt text](/home/courand/Bureau/CPP/Schema_principe.png "Optional title")

## Description technique. 

### Diagramme de cas d'utilisation. 

### Diagramme de classe. 

### Description des classes. 

- ```SENSOR CLASS```

Le fichier ```Sensor.hpp``` contient la déclaration de la classe Sensor, avec deux méthodes virtuelles pures, ```displayData()```et ```retrieveData()```, ainsi qu'un attribut statique ```sensorNbr```, qui compte le nombre total de capteurs créés.

Le fichier ```Sensor.cpp``` définit le constructeur qui incrémente l'attribut sensorNbr et affiche un message à la console. Il inclut également le fichier header Sensor.hpp qui permet de référencer la classe Sensor et ses méthodes.

### Diagramme de séquence. 
