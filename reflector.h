#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "module.h"

#include <QVector>



class Reflector : public Module
{
public:
    Reflector(int seed);

private:
    QVector<int> plugs;

    // Module interface
public:
    int operator ()(int value);
};

#endif // REFLECTOR_H
