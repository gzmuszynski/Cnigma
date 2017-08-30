#ifndef ROTOR_H
#define ROTOR_H

#include "module.h"

#include <QVector>


class Rotor : public Module
{
public:
    Rotor(int seed, Module* module);

private:
    int offset;

    QVector<int> switches1;
    QVector<int> switches2;

    // Module interface
public:
    int  operator ()(int value);
    void operator++();
};

#endif // ROTOR_H
