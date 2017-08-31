#include "cnigma.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QVector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::string str = "AAAAA";

    qDebug() << "starting string" << str.c_str();

    Cnigma cypher(0,1,2,3,4);
    cypher << str;

    qDebug() << "cyphered string" << str.c_str();

    Cnigma decypher(0,1,2,3,4);
    decypher << str;

    qDebug() << "decyphered string" << str.c_str();
}

MainWindow::~MainWindow()
{
    delete ui;
}
