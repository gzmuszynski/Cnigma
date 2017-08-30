#include "plugboard.h"
#include "cnigma.h"

Plugboard::Plugboard(int seed, Module* module): Module(module)
{
    qsrand(seed);

    QVector<char> available; // available char number vector stored for filling up switches table

    for(char i = 0; i < CHAR_NUM; i++)
    {
        plugs.push_back(i);
        available.push_back(i);
    }

    for(char i = 0; i < 0.4 * CHAR_NUM; i++) // main loop for creating plug pairs
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

char Plugboard::operator ()(char value)
{
    value =         plugs[value]; // swaps character with corresponding plug, if character is plugged
    value = (*nextModule)(value); // jump to next module and expect returning value (forwards)
    value =         plugs[value]; // swaps character returning from prev step (backwards)

    (*nextModule)++;
    return value;
}
