#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "module.h"

#include <QVector>



class Reflector : public Module
{
public:
    Reflector(int seed);

private:
    QVector<char> plugs;

    // Module interface
public:
    char operator ()(char value);
};

#endif // REFLECTOR_H
