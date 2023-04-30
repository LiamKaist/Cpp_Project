#include "HTTPerror.h"
#include <iostream>

HTTPerror::HTTPerror(int c)
{
    switch (c)
    {
    case 1:
        std::cout<< "Socket issue"<< std::endl;
        this->cause=1;
        break;
    
    case 2:
        std::cout<< "Bind issue"<< std::endl;
        this->cause=2;
        break;

    case 3:
        std::cout<< "Listen issue"<< std::endl;
        this->cause=2;
        break;

    case 4:
        std::cout<< "Accept issue"<< std::endl;
        this->cause=2;
        break;

    case 5:
        std::cout<< "Read Issue"<< std::endl;
        this->cause=2;
        break;

    case 6:
        std::cout<< "Sending failed" << std::endl;
        this->cause=2;
        break;
    
    case 7:
        std::cout<< "File cannot be opened" << std::endl;
        this->cause=2;
        break;
    
    default:
        break;
    }

}