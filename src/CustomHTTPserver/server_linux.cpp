#include "http_tcpServer_linux.h"
using namespace http;


int main()
{
    try
    {
        TcpServer server =TcpServer("0.0.0.0",8080);
    }catch(HTTPerror err){
        std::cerr<< "Runtime problem" << std::endl;
    }
    
    return 0;
}