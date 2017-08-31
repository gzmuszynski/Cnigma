#ifndef ROTOR_H
#define ROTOR_H

#include "module.h"

#include <vector>


class Rotor : public Module
{
public:
    Rotor(int seed, Module* module);
    ~Rotor();

private:
    char offset = 0;

    std::vector<char> switches1;
    std::vector<char> switches2;

    // Module interface
public:
    char  operator()(char value);
    void operator++(int);
    void operator= (char value);
};

#endif // ROTOR_H
