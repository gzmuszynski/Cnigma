#include "reflector.h"
#include "cnigma.h"

#include <QVector>

Reflector::Reflector(int seed)
{
    qsrand(seed);

    QVector<char> available; // available char number vector stored for filling up switches table

    for(char i = 0; i < CHAR_NUM; i++)
    {
        plugs.push_back(i);
        available.push_back(i);
    }

    while(available.size() > 1) // main loop for creating plug pairs
    {
        char random1 = qrand % available.size();
        char value1  = available[random1];
        available.remove(random1);

        char random2 = qrand % available.size();
        char value2  = available[random2];
        available.remove(random2);

        plugs[value1] = value2;
        plugs[value2] = value1;

    }
}

char Reflector::operator ()(char value)
{
    return plugs[value]; // reflect and swap value / return to previous module
}
