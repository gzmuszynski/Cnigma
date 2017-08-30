#include "reflector.h"

#include <QVector>

Reflector::Reflector(int seed)
{
    qsrand(seed);

    QVector<int> available; // available char number vector stored for filling up switches table

    for(int i = 0; i < 95; i++)
    {
        plugs.push_back(i);
        available.push_back(i);
    }

    while(available.size() > 1) // main loop for creating plug pairs
    {
        int random1 = qrand % available.size();
        int value1  = available[random1];
        available.remove(random1);

        int random2 = qrand % available.size();
        int value2  = available[random2];
        available.remove(random2);

        plugs[value1] = value2;
        plugs[value2] = value1;

    }
}

int Reflector::operator ()(int value)
{
    return plugs[value]; // reflect and swap value / return to previous module
}
