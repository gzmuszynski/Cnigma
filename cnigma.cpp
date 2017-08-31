#include "cnigma.h"
#include <vector>
#include "modules/plugboard.h"
#include "modules/reflector.h"
#include "modules/rotor.h"

Cnigma::Cnigma()
{
    reflector = new Reflector(0);
    rotor3    = new Rotor(0, reflector);
    rotor2    = new Rotor(0, rotor3);
    rotor1    = new Rotor(0, rotor2);
    plugboard = new Plugboard(0, rotor1);
}

Cnigma::Cnigma(int seed)
{
    qsrand(seed);
    reflector = new Reflector(qrand());
    rotor3    = new Rotor(qrand(), reflector);
    rotor2    = new Rotor(qrand(), rotor3);
    rotor1    = new Rotor(qrand(), rotor2);
    plugboard = new Plugboard(qrand(), rotor1);
}

Cnigma::Cnigma(int seedPB, int seedR1, int seedR2, int seedR3, int seedRF)
{
    reflector = new Reflector(seedRF);
    rotor3    = new Rotor(seedR3, reflector);
    rotor2    = new Rotor(seedR2, rotor3);
    rotor1    = new Rotor(seedR1, rotor2);
    plugboard = new Plugboard(seedPB, rotor1);
}

Cnigma::~Cnigma()
{
    if(plugboard != nullptr)
    {
        delete plugboard;
        plugboard = nullptr;
    }

    if(rotor1 != nullptr)
    {
        delete rotor1;
        rotor1 = nullptr;
    }

    if(rotor2 != nullptr)
    {
        delete rotor2;
        rotor2 = nullptr;
    }

    if(rotor3 != nullptr)
    {
        delete rotor3;
        rotor3 = nullptr;
    }

    if(reflector != nullptr)
    {
        delete reflector;
        reflector = nullptr;
    }

}

void Cnigma::setPlugboardSeed(int seed)
{
    plugboard = new Plugboard(seed, rotor1);
}

void Cnigma::setRotor1Seed(int seed)
{
    rotor1 = new Rotor(seed, rotor2);
}

void Cnigma::setRotor2Seed(int seed)
{
    rotor2 = new Rotor(seed, rotor3);}

void Cnigma::setRotor3Seed(int seed)
{
    rotor3 = new Rotor(seed, reflector);
}

void Cnigma::setReflectorSeed(int seed)
{
    reflector = new Reflector(seed);
}

void Cnigma::operator<<(std::string &str)
{
    if(plugboard != nullptr)
    {
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] >= 32 || str[i] < 127)
            {
                char ch = ((*plugboard)((char)(str[i]-32))+32);
                memset(&str[i], ch , 1);
            }
        }
    }
}
