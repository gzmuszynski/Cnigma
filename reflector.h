#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "module.h"



class Reflector : public Module
{
public:
    Reflector();

    // Module interface
public:
    void forward(int character);
    void backward(int character);
};

#endif // REFLECTOR_H
