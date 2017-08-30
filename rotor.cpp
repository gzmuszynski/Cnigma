#include "rotor.h"
#include "cnigma.h"

Rotor::Rotor(int seed, Module *module): Module(module)
{
    qsrand(seed);

    QVector<char> available; // available char number vector stored for filling up switches table

    for(char i = 0; i < CHAR_NUM; i++)
    {
        switches2.push_back(i);
        available.push_back(i);
    }

    for(int i = 0; i < CHAR_NUM; i++)
    {
        char random = qrand % available.size();
        char value = available[random];
        available.remove(random);

        switches1.push_back(value);
        switches2[value] = i;
    }
}

char Rotor::operator ()(char value)
{
    value =     switches1[(value+offset) % CHAR_NUM];
    value = (*nextModule)(value);
    value =     switches2[(value+offset) % CHAR_NUM];

    return value;
}

void Rotor::operator++()
{
    offset++;
    if(offset >= CHAR_NUM)
    {
        offset = 0;
        (*nextModule)++;
    }
}

void Rotor::operator=(char value)
{
    offset = qBound(0, value, CHAR_NUM);
}
