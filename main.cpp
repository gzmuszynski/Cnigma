#include "cnigma.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    std::string str = "AAAAA";

    qDebug() << "starting string" << str.c_str();

    Cnigma cypher(0,1,2,3,4);
    cypher << str;

    qDebug() << "cyphered string" << str.c_str();

    Cnigma decypher(0,1,2,3,4);
    decypher << str;

    qDebug() << "decyphered string" << str.c_str();

    return 0;
}
