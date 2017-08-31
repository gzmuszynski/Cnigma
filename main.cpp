#include "cnigma.h"
#include <random>
#include <stdio.h>
#include <time.h>
#include <iostream>

// example usage of Cnigma class

int main(int argc, char *argv[])
{
    std::string str = argv[1];
    int seed;

    if(argc < 3)
    {
        srand(time(NULL));
        seed = (int)rand();
    }
    else
    {
        seed = atoi(argv[2]);
    }

    std::cout << "Starting string: " << str.c_str() << std::endl;

    Cnigma cypher(seed);
    cypher << str;

    std::cout << "Cyphered string: " << str.c_str() << std::endl;

    Cnigma decypher(seed);
    decypher << str;

    std::cout << "Decyphered string: " << str.c_str() << std::endl;

    return 0;
}
