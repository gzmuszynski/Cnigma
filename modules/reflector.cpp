#include "reflector.h"
#include "cnigma.h"

Reflector::Reflector(int seed)
{
    srand(seed);

    std::vector<char> available; // available char number vector stored for filling up switches table

    for(char i = 0; i < CHAR_NUM; i++)
    {
        plugs.push_back(i);
        available.push_back(i);
    }

    while(available.size() > 1) // main loop for creating plug pairs
    {
        char random1 = rand() % available.size();
        char value1  = available[random1];
        available.erase(available.begin()+random1);

        char random2 = rand() % available.size();
        char value2  = available[random2];
        available.erase(available.begin()+random2);

        plugs[value1] = value2;
        plugs[value2] = value1;

    }
}

char Reflector::operator ()(char value)
{
    return plugs[value]; // reflect and swap value / return to previous module
}
