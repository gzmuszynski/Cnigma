#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "module.h"

#include <vector>



class Reflector : public Module
{
public:
    Reflector(int seed);

private:
    std::vector<char> plugs;

    // Module interface
public:
    char operator ()(char value);
};

#endif // REFLECTOR_H
