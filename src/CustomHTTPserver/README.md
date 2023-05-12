# HTTPerror
HTTPerror is a class used to throw errors while launching the server on the Linux deskstop (using the socket API).

# http_tcpServer_linux 
http_tcpServer_linux is a class used to create a server located at a specific IP address and port (Can be configured with parameters given to the constructor)

# server_linux.cpp and server_linux 
server_linux.cpp is the main file, used to launch the desired servers. server_linux is the executable resulting from the following command :
g++ -Wall server_linux.cpp http_tcpServer_linux.cpp HTTPerror.cpp -o server_linux
