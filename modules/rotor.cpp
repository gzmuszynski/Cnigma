#include "rotor.h"
#include "cnigma.h"

Rotor::Rotor(int seed, Module *module): Module(module)
{
    srand(seed);

    std::vector<char> available; // available char number vector stored for filling up switches table

    for(char i = 0; i < CHAR_NUM; i++)
    {
        switches2.push_back(i);
        available.push_back(i);
    }

    for(int i = 0; i < CHAR_NUM; i++)
    {
        char random = rand() % available.size();
        char value = available[random];
        available.erase(available.begin()+random);

        switches1.push_back(value);
        switches2[value] = i;
    }
}

Rotor::~Rotor()
{

}

char Rotor::operator ()(char value)
{
    //Take offset into account
    // add signal offset on rotor entry, and subtract on exit
    // %CHAR_NUM for array bounds check

    value =     (switches1[(value + offset) % CHAR_NUM] + CHAR_NUM - offset) % CHAR_NUM;
    value = (*nextModule)(value);
    value =     (switches2[(value + offset) % CHAR_NUM] + CHAR_NUM - offset) % CHAR_NUM;

    return value;
}

void Rotor::operator++(int)
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
    offset = ( value + CHAR_NUM ) % CHAR_NUM;
}
