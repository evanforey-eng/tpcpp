#include "passenger.h"

QString Passenger::getIden() const
{
    return iden;
}

void Passenger::setIden(const QString &newIden)
{
    iden = newIden;
}

int Passenger::getClassBoat() const
{
    return classBoat;
}

void Passenger::setClassBoat(int newClassBoat)
{
    classBoat = newClassBoat;
}

int Passenger::getAge() const
{
    return age;
}

void Passenger::setAge(int newAge)
{
    age = newAge;
}

int Passenger::getSex() const
{
    return sex;
}

void Passenger::setSex(int newSex)
{
    sex = newSex;
}

int Passenger::getSurvived() const
{
    return survived;
}

void Passenger::setSurvived(int newSurvived)
{
    survived = newSurvived;
}

Passenger::Passenger(const QString &iden, int classBoat, int age, int sex, int survived) : iden(iden),
    classBoat(classBoat),
    age(age),
    sex(sex),
    survived(survived)
{}
