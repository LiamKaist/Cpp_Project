#ifndef HTTPERROR_H
#define HTTPERROR_H

class HTTPerror 
{
public:
    int cause; //Integer indicating the origin of the error
    HTTPerror(int c);
};





#endif