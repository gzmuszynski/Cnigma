#include "cnigma.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    std::string str = "AAAAA";

    qDebug() << "starting string" << str.c_str();

    Cnigma cypher(20);
    cypher << str;

    qDebug() << "cyphered string" << str.c_str();

    Cnigma decypher(20);
    decypher << str;

    qDebug() << "decyphered string" << str.c_str();

    return 0;
}
