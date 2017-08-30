#ifndef ROTOR_H
#define ROTOR_H

#include "module.h"

#include <QVector>


class Rotor : public Module
{
public:
    Rotor(int seed, Module* module);

private:
    char offset;

    QVector<char> switches1;
    QVector<char> switches2;

    // Module interface
public:
    char  operator()(char value);
    void operator++();
    void operator= (char value);
};

#endif // ROTOR_H
