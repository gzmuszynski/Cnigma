#ifndef CNIGMA_H
#define CNIGMA_H
#define CHAR_NUM 95

class Plugboard;
class Rotor;
class Reflector;

class Cnigma
{
public:
    Cnigma();
    Cnigma(int seedPB, int seedR1, int seedR2, int seedR3, int seedRF);
    ~Cnigma();

    void operator<< (char* str);
private:
    Plugboard* plugboard = nullptr;
    Rotor*     rotor1    = nullptr;
    Rotor*     rotor2    = nullptr;
    Rotor*     rotor3    = nullptr;
    Reflector* reflector = nullptr;


};

#endif // CNIGMA_H