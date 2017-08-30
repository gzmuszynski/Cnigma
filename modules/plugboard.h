#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "module.h"

#include <QVector>



class Plugboard : public Module
{
public:
    Plugboard(int seed, Module *module);

private:
    QVector<char> plugs;

    // Module interface
public:
    char operator ()(char value);
};

#endif // PLUGBOARD_H
