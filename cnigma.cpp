#include "cnigma.h"
#include <vector>
#include "modules/plugboard.h"
#include "modules/reflector.h"
#include "modules/rotor.h"

Cnigma::Cnigma() :
    reflector(0),
    rotor3   (0, reflector),
    rotor2   (0, rotor3),
    rotor1   (0, rotor2),
    plugboard(0, rotor1)
{

}

Cnigma::Cnigma(int seedPB, int seedR1, int seedR2, int seedR3, int seedRF) :
    reflector(seedRF),
    rotor3   (seedR3, reflector),
    rotor2   (seedR2, rotor3),
    rotor1   (seedR1, rotor2),
    plugboard(seedPB, rotor1)
{

}

void Cnigma::operator<<(char *str)
{
    if(plugboard != nullptr)
    {
        for(int i = 0; i < strlen(str); i++)
        {
            if(str[i] >= 32 || str[i] < 127)
            {
                memset(str+i,(plugboard(str[i]-32)+32),1);
            }
        }
    }
}
