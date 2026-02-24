#ifndef PASSENGER_H
#define PASSENGER_H

#include <QString>

class Passenger
{
    QString iden;
    int classBoat;
    int age;
    int sex;
    int survived;
public:
    Passenger(const QString &iden, int classBoat, int age, int sex, int survived);
    QString getIden() const;
    void setIden(const QString &newIden);
    int getClassBoat() const;
    void setClassBoat(int newClassBoat);
    int getAge() const;
    void setAge(int newAge);
    int getSex() const;
    void setSex(int newSex);
    int getSurvived() const;
    void setSurvived(int newSurvived);
};

#endif // PASSENGER_H
