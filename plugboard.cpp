#include "plugboard.h"

Plugboard::Plugboard()
{
    qsrand(0);
    plugs = new int[95];

    QVector<int> available; // available char number vector stored for filling up switches table

    for(int i = 0; i < 95; i++)
    {
        plugs[i] = i;
        available[i] = i;
    }

    for(int i = 0; i < 0.4 * 95; i++)
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

int Plugboard::swap(int character)
{
    return plugs[character];
}

void Plugboard::forward(int character)
{
    right->forward(swap(character));
}

void Plugboard::backward(int character)
{
    left->backward(swap(character));
}
