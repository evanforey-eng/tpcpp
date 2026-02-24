#ifndef DATA_H
#define DATA_H

#include "passenger.h"

#include <QList>
#include <QFile>
#include <QTextStream>
#include <QDebug>
class Data
{
    QList<Passenger> listPassenger;

public:
    void loadFile(QString nameFile);
    Data();

    QList<Passenger> getListPassenger() const;

    int getPassengerClasse(int classe,int survie) const;
    int getPopulationClasse(int classe) const;
    int getPopulationAge(int age) const;
};

#endif // DATA_H
