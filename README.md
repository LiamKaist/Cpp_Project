# Cpp_Project
Github du Projet C++ (Liam CHRISMENT Johann COURAND)
.ino yet to be provided

# Use Case Diagram

![UseCaseDiagram1](https://github.com/LiamKaist/Cpp_Project/assets/117256858/57f7fe4b-f626-441f-aa5b-1b589a4abd32)

Le but principal de notre projet est de fournir un service à un utilisateur. Ce service consiste à fournir de l'eau ou un autre liquide à l'utilisateur, en fonction de ses envies. S'il dit qu'il meurt de soif, il se verra donner une grande quantité d'eau (dans le cas de notre projet , 300 mL est le max) , s'il n'a qu'une petite soif, il se verra donner que 100 mL, ou bien 200 mL si aucune envie précise ne se dégage. Si l'utilisateur ne demande pas d'eau, il ne recevra rien. 
Pour ce faire, nous avons utilisé l'API de ChatGPT, ainsi que des classes C++ pour simplifier le code dans le .ino et mieux visualiser les composantes du projet. De plus, il est nécessaire de transcrire la voix de l'utilisateur. En utilisant un modèle linguistique Open Source Whisper, on est parvenu à récupérer la voie pour la traiter à travers l'API chatGPT.
Nous avons utilisé un téléphone pour l'enregistrement de la voix comme il nous l'a été recommandé.


# Class Diagram

![ClassDiagram](https://github.com/LiamKaist/Cpp_Project/assets/117256858/d41fe4f9-1c6c-45c7-9e2b-9e00dedf8be4)

La classe U8G2 est une classe récupérée auprès des fournisseurs du module Oled, cette classe fournit un ensemble de méthodes utiles à l'utilisation de l'afficheur.
# Sequence Diagram

![SequenceDiagram1](https://github.com/LiamKaist/Cpp_Project/assets/117256858/bee845cb-7b2b-40ea-8026-5f20b72d2f88)

Voici un diagramme de sequence de la fonction basique de notre projet, qui est de permettre à l'ESP8266 de récupérer un volume de liquide (eau, café , peu importe ...) sur un serveur (lui-même écrit en C++) qui contient la valeur récupérée après le traitement de la voix de la personne qui réclame une boisson. Cette valeur est alors récupérée et une commande est envoyée à la pompe. L'affichage Oled affiche également le volume de liquide à verser.

Il y a d'autres fonctionnalités , par exemple ce qu'à dit l'utilisateur peut être affiché à l'écran après avoir été entièrement récupéré auprès d'un second serveur qui dispose de la transcription.

Il y a aussi un niveau d'eau permettant d'alerter à l'utilisateur ou les personnes en charge de la maintenance qu'il n'y a pas assez de liquide pour faire fonctionner le dispositif
