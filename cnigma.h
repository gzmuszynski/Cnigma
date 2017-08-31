#ifndef CNIGMA_H
#define CNIGMA_H
#define CHAR_NUM 95

#include <string>

class Plugboard;
class Rotor;
class Reflector;

class Cnigma
{
public:
    Cnigma();
    Cnigma(int seed);
    Cnigma(int seedPB, int seedR1, int seedR2, int seedR3, int seedRF);
    ~Cnigma();

    void setPlugboardSeed(int seed);
    void setRotor1Seed   (int seed);
    void setRotor2Seed   (int seed);
    void setRotor3Seed   (int seed);
    void setReflectorSeed(int seed);
    void operator<< (std::string &str);
private:
    Plugboard* plugboard = nullptr;
    Rotor*     rotor1    = nullptr;
    Rotor*     rotor2    = nullptr;
    Rotor*     rotor3    = nullptr;
    Reflector* reflector = nullptr;


};

#endif // CNIGMA_H
