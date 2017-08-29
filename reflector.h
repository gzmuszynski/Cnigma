#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "module.h"



class Reflector : public Module
{
public:
    Reflector();

    // Module interface
public:
    int forward();
    int backward();

    void setLeft(Module *module);
    void setRight(Module *module);
};

#endif // REFLECTOR_H
