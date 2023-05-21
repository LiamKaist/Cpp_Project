# Cpp_Projet
Github du Projet C++ (Liam CHRISMENT Johann COURAND)

## Présentation du projet. 

### Introduction. 

Notre projet consiste à concevoir un distributeur automatique d'eau qui permettra aux utilisateurs de s'hydrater facilement. Le système sera capable de recevoir des indications de l'utilisateur, telles que "Je suis assoiffé, cela fait depuis midi que je n'ai pas bu d'eau", et de délivrer une quantité d'eau adaptée à la demande de l'utilisateur.

Le système de distributeur automatique d'eau fonctionne de la manière suivante :

1/ L'utilisateur exprime son besoin en enregistrant sa voix via un téléphone portable.

2/ L'enregistrement vocal est envoyé à un ordinateur via une connexion Wi-Fi.

3/ Le système utilise le modèle linguistique OpenSource Whisper pour traiter l'enregistrement vocal et l'API OpenAI GPT pour interpréter le besoin de l'utilisateur en traduisant la voix en quantité d'eau à fournir.

4/ L'ordinateur communique la quantité d'eau nécessaire à la carte électronique ESP via une connexion Wi-Fi.

5/ La carte électronique traite l'information et fournit une commande à une pompe pour fournir l'eau dans un gobelet.

- Hardware : 

Carte ESP [Arduino] / Capteur de niveau [Grove] / Afficheur OLED [Grove] / Pompe à eau immergée [Lextronic] 

### Schéma de principe du système. 

![image](Schema_principe.png)

## Description technique. 

Le but principal de notre projet est de fournir un service à un utilisateur. Ce service consiste à fournir de l'eau ou un autre liquide à l'utilisateur, en fonction de ses envies. S'il dit qu'il meurt de soif, il se verra donner une grande quantité d'eau (dans le cas de notre projet , 300 mL est le max) , s'il n'a qu'une petite soif, il se verra donner que 100 mL, ou bien 200 mL si aucune envie précise ne se dégage. Si l'utilisateur ne demande pas d'eau, il ne recevra rien. 
Pour ce faire, nous avons utilisé l'API de ChatGPT, ainsi que des classes C++ pour simplifier le code dans le .ino et mieux visualiser les composantes du projet. De plus, il est nécessaire de transcrire la voix de l'utilisateur. En utilisant un modèle linguistique Open Source Whisper, on est parvenu à récupérer la voie pour la traiter à travers l'API chatGPT.
Nous avons utilisé un téléphone pour l'enregistrement de la voix comme il nous l'a été recommandé.

Ci-Dessous, vous trouverez les diagrammes de cas d'usage , de classes et de séquence
### Diagramme de cas d'utilisation. 

![UseCaseDiagram1](https://github.com/LiamKaist/Cpp_Project/assets/117256858/57f7fe4b-f626-441f-aa5b-1b589a4abd32)

### Diagramme de classe. 
![image](https://github.com/LiamKaist/Cpp_Project/assets/117256858/e1b2e698-7b17-41bf-90df-cdffe4aef0a8)

La classe U8G2 est une classe récupérée auprès des fournisseurs du module Oled, cette classe fournit un ensemble de méthodes utiles à l'utilisation de l'afficheur.
La classe ESP8266WifiClient est une classe fournie avec le core de l'ESP8266.

### Description des classes. 

- ```SENSOR```

La classe Sensor est déclarée dans le fichier Sensor.h et a un attribut statique :

```static int sensorNbr``` : le nombre total de capteurs créés jusqu'à présent.

La classe Sensor est une classe abstraite, elle a une méthode virtuelle pure non implémentée :

```virtual void retrieveData()=0``` : récupère les données du capteur.

La classe Sensor a un constructeur par défaut, ```Sensor()```, qui incrémente la variable statique sensorNbr chaque fois qu'un objet Sensor est créé.

- ```ACTUATOR```

La classe Actuator est déclarée dans le fichier Actuator.h et a un attribut statique :

```static int actuatorNbr``` : le nombre total d'actionneurs créés jusqu'à présent.

La classe Actuator est une classe abstraite, ce qui signifie qu'elle a une méthode virtuelle pure non implémentée :

```virtual void sendSignal()=0``` : envoie un signal à l'actionneur.

La classe Actuator a un constructeur par défaut, ```Actuator()```, qui incrémente la variable statique actuatorNbr chaque fois qu'un objet Actuator est créé.

- ```PUMP```

La classe Pump est déclarée dans le fichier Pump.h avec les attributs suivants :

```uint8_t pin```: le numéro de la broche à laquelle la pompe est connectée.

```double duration```: la durée d'exécution de la pompe.

La classe a deux constructeurs, ```Pump()``` et ```Pump(uint8_t pin)```, ainsi qu'une méthode ```void sendSignal()```.

La méthode ```void sendSignal()``` envoie un signal à la pompe en utilisant la broche spécifiée, envoie des signaux HIGH et LOW pour l'activer et la désactiver, respectivement, et utilise le ```timer millis()``` pour contrôler le temps d'exécution de la pompe.

La méthode ```void dispenseLiquid()``` envoie un signal à la pompe pour remplir un verre d'un volume spécifié en paramètre.

- ```CUSTOMWIFICLIENT```

La classe CustomWiFiClient contient plusieurs attributs privés, à savoir :

```IPaddress``` : une chaîne de caractères représentant l'adresse IP du serveur distant.

```port``` : un entier représentant le port utilisé pour la connexion.

incomingMessage : une chaîne de caractères contenant le dernier message reçu du serveur distant.

incomingSize : un entier représentant la taille du dernier message reçu.

buf : un pointeur vers un tableau de caractères qui est utilisé pour stocker temporairement les données reçues du serveur distant.

Le constructeur de la classe prend en entrée l'adresse IP et le port du serveur distant, et initialise les attributs correspondants. Il crée également un tableau de caractères de taille 3, qui sera utilisé comme buffer pour stocker les données reçues du serveur.

La méthode connectToHost() permet de se connecter au serveur distant en utilisant l'adresse IP et le port spécifiés. Elle effectue une boucle tant que la connexion n'est pas établie, et une fois celle-ci établie, elle envoie un message de confirmation. Si la boucle est répétée un plus d'un certain nombre de fois, alors le bouclage s'arrête et la chaine de caractère "ServerTimeout" sera envoyée lors de l'appel de retrieveMessage().

La méthode retrieveMessage() permet de récupérer les données envoyées par le serveur distant. Elle lit le buffer de réception et le stocke dans un nouveau tableau de caractères de taille égale à incomingSize, qui est ensuite converti en une chaîne de caractères et retourné. Si aucune donnée n'est disponible, la méthode renvoie une chaîne de caractères "ServerTimeout".

- ```CustomHTTPserver```
Cette classe utilisée sur l'ordinateur portable pour mettre à disposition de l'ESP les données utiles. Elle reprend les principes de l'API Socket et utilise un mecanisme d'exceptions. Le nom HTTPserver a été choisi car il devait être concu en respectant les normes HTTP , cependant cela n'a plus été le cas.
### Diagramme de séquence. 

![SequenceDiagram1](https://github.com/LiamKaist/Cpp_Project/assets/117256858/bee845cb-7b2b-40ea-8026-5f20b72d2f88)

Voici un diagramme de sequence de la fonction basique de notre projet, qui est de permettre à l'ESP8266 de récupérer un volume de liquide (eau, café , peu importe ...) sur un serveur (lui-même écrit en C++) qui contient la valeur récupérée après le traitement de la voix de la personne qui réclame une boisson. Cette valeur est alors récupérée et une commande est envoyée à la pompe. L'affichage Oled affiche également le volume de liquide à verser.

Il y a d'autres fonctionnalités , par exemple ce qu'à dit l'utilisateur peut être affiché à l'écran après avoir été entièrement récupéré auprès d'un second serveur qui dispose de la transcription.

Il y a aussi un niveau d'eau permettant d'alerter à l'utilisateur ou les personnes en charge de la maintenance qu'il n'y a pas assez de liquide pour faire fonctionner le dispositif
