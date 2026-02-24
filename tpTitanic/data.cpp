#include "data.h"

QList<Passenger> Data::getListPassenger() const
{
    return listPassenger;
}

int Data::getPassengerClasse(int classe, int survie) const
{
    int nb=0;
    for(Passenger p: listPassenger){
        if(p.getClassBoat()==classe && p.getSurvived()==survie){
            nb++;
        }
    }
    return nb;

}

int Data::getPopulationClasse(int classe) const
{
    int nb=0;
    for(Passenger p: listPassenger){
        if(p.getClassBoat()==classe){
            nb++;
        }
    }
    return nb;
}

int Data::getPopulationAge(int age) const
{
    int nb=0;
    for(Passenger p: listPassenger){
        if(p.getAge()==age){
            nb++;
        }
    }
    return nb;
}



void Data::loadFile(QString nameFile)
{
    QFile file(nameFile);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Impossible d'ouvrir le fichier :" << nameFile;
        return;
    }
    QString i;
    int cBoat;
    int a;
    int s;
    int survi;
    QTextStream qts(&file);

    for (int i=0;i<5;i++){
        QString l = qts.readLine();
    }

    while (!qts.atEnd()) {
        qts >> i;
        qts >> cBoat;
        qts >> a;
        qts >> s;
        qts >> survi;
        Passenger p(i,cBoat,a,s,survi);
        listPassenger.append(p);
    }
    file.close();
    qDebug()<<"Nombre de passager :" << listPassenger.size();
}



Data::Data()
{

}
