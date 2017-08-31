#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "module.h"

#include <vector>



class Plugboard : public Module
{
public:
    Plugboard(int seed, Module *module);

private:
    std::vector<char> plugs;

    // Module interface
public:
    char operator ()(char value);
};

#endif // PLUGBOARD_H
