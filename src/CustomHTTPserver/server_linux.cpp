#include "http_tcpServer_linux.h"
using namespace http;
using namespace std;

int main(int argc, char * argv[])
{
    if (argc > 3){
        cout<< "Too many arguments provided..." << endl;
    }else if (argc == 3){
        try
        {
            cout<< "Ouverture de deux serveurs aux ports donnés..." << endl;
            TcpServer server1 = TcpServer("0.0.0.0",atoi(argv[1]),1);
            cout<< "Ouverture du deuxieme serveur..." << endl;
            TcpServer server2 = TcpServer("0.0.0.0",atoi(argv[2]),2);
            //server.~TcpServer();
        }catch(HTTPerror err){
            cerr<< "Runtime problem" << endl;
        }
    }else{
        cout<< "Too few arguments provided..." << endl;
    }
    return 0;
}