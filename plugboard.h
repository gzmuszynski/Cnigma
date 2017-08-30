#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "module.h"

#include <QVector>



class Plugboard : public Module
{
public:
    Plugboard(int seed, Module *module);

private:
    QVector<int> plugs;

    // Module interface
public:
    int operator ()(int value);
};

#endif // PLUGBOARD_H
