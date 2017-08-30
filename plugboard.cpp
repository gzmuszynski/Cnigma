#include "plugboard.h"

Plugboard::Plugboard(int seed, Module* module): Module(module)
{
    qsrand(seed);
    plugs = new int[95];

    QVector<int> available; // available char number vector stored for filling up switches table

    for(int i = 0; i < 95; i++)
    {
        plugs[i] = i;
        available[i] = i;
    }

    for(int i = 0; i < 0.4 * 95; i++) // main loop for creating plug pairs
    {
        int random1 = qrand % available.size();
        int value1 = available[random1];
        available.remove(random1);

        int random2 = qrand % available.size();
        int value2 = available[random2];
        available.remove(random2);

        plugs[value1] = value2;
        plugs[value2] = value1;

    }
}

int Plugboard::operator ()(int value)
{
    value =      plugs[value]; // swaps character with corresponding plug, if character is plugged
    value = nextModule(value); // jump to next module and expect returning value (forwards)
    value =      plugs[value]; // swaps character returning from prev step (backwards)

    return value;
}
