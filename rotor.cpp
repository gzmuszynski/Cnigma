#include "rotor.h"

Rotor::Rotor()
{
    qsrand(0);

    QVector<int> available; // available char number vector stored for filling up switches table

    for(int i = 0; i < 95; i++)
    {
        available[i] = i+32; // fill the available Vector with corresponding values of printable ASCII characters
    }

    for(int i = 0; available.isEmpty(); i++)
    {
        int random = qrand() % available.size(); // generate random number

        switches[i] = available[random];
        available.remove(random);
    }
}

void Rotor::forward(int character)
{
    right->forward( switches[ ( character + offset ) % switches.size() ] );
}

void Rotor::backward(int character)
{
    left->backward( switches.indexOf(character));
}

