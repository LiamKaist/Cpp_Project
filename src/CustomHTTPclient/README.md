A test arduino sketch is called WifiConnectComputer (On Liam's computer).
Idea is to run a client on the nodeMCU that will retrieve data from the socket server on the Linux Ubuntu 22.04 jammy jellyfish computer.
Problem is I use sockets.. However this library is non existant on the MCU , in arduino. (Well, I found something worth investigating now!)
To solve this, there is a WifiClient in the ESP library which handles the WiFi client on the ESP8266. Luckily...

C:\Users\liamc\AppData\Local\Arduino15\packages\esp8266\hardware\esp8266\3.1.1\libraries\ESP8266WiFi\src (Path on my computer, for future reference)
