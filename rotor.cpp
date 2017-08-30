#include "rotor.h"

Rotor::Rotor(int seed, Module *module): Module(module)
{
    qsrand(seed);

    QVector<int> available; // available char number vector stored for filling up switches table

    for(int i = 0; i < 95; i++)
    {
        switches2.push_back(i);
        available.push_back(i);
    }

    for(int i = 0; i < 95; i++)
    {
        int random = qrand % available.size();
        int value = available[random];
        available.remove(random);

        switches1.push_back(value);
        switches2[value] = i;
    }
}

int Rotor::operator ()(int value)
{
    value =     switches1[(value+offset) % 95];
    value = (*nextModule)(value);
    value =     switches2[(value+offset) % 95];

    return value;
}

void Rotor::operator++()
{
    offset++;
    if(offset >= 95)
    {
        offset = 0;
        (*nextModule)++;
    }
}
