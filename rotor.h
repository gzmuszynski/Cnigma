#ifndef ROTOR_H
#define ROTOR_H

#include "module.h"

#include <QVector>


class Rotor : public Module
{
public:
    Rotor();

private:
    int offset;
    QVector<int> switches;

    // Module interface
public:
    int forward();
    int backward();
};

#endif // ROTOR_H
