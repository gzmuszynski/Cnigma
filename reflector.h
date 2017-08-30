#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "module.h"



class Reflector : public Module
{
public:
    int* plugs;

    Reflector(int seed);


    // Module interface
public:
    int operator ()(int value);
};

#endif // REFLECTOR_H
