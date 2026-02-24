#include "promotion.h"



/**
 * @brief Constructor of the Promotion Class to manage the List of student
 * @param filename, path to the data CSV file
*/
Promotion::Promotion(QString filename)
{
    qDebug() << "[+] Promotion";

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Impossible d'ouvrir le fichier :" << filename;
        return;
    }

    QTextStream qts(&file);

    while (!qts.atEnd() )
    {
         QString line = qts.readLine();
         QStringList list = line.split(";");


         QString cardID = list[0];
         QString firstname = list[1];
         QString lastname = list[2];
         QString department = list[3];
         QString bac = list[4];

         students.append(Student(cardID,firstname,lastname,bac,department));
    }
    file.close();
    qDebug()<<"Nombre d'etudiant :" << students.size();



}


/**
 * @brief Function to add a student to the promotion list
 * @param etu The current student
*/
void Promotion::add(const Student &etu)
{
    for(Student s : students){
        if(s.getCardID()== etu.getCardID()){
            ErreurDialog dlg("Le numéro d'étudiant existe déja");
            dlg.exec();
            return;
        }
    }
    students.append(etu);
    notifyObserver();
}

/**
 * @brief Function to remove a specific student
 * @param listText the student text as in the view list
*/
void Promotion::remove(const QString& listText)
{
    int cpt=0;
    for(Student s : students){
        if(s.getText()==listText) {
            students.removeAt(cpt);
            qDebug()<<"[-]Etudiant supprimé";
            notifyObserver();
            return;
        }
        cpt++;
    }
}

/**
 * @brief Function to remove a specific student
 * @param etu The student to remove
*/
void Promotion::remove(const Student &etu)
{
    int cpt=0;
    for(Student s : students){
        if(s.getCardID() == etu.getCardID()) {
           students.removeAt(cpt);
           qDebug()<<"[-]Etudiant supprimé";
           notifyObserver();
           return;
        }
        cpt++;
    }
}

/**
 * @brief Search the student according to his ID Card
 * @param cardID ID card of the student
 * @return Student
*/
Student Promotion::find(QString cardID) const
{
    for(Student s : students){
        if(s.getCardID()==cardID){
            return s;
        }
    }
    ErreurDialog dlg("Erreur l'étudiant n'existe pas");
    dlg.exec();
    return Student();
}

 QList<int> Promotion::getDep() const
{
    int tabRegion[96]={0};
    for(Student s : students){
        int index = s.getDepartment().toInt()-1;

        if (index >= 0 && index < 96) {
            tabRegion[index]++;
        }
    }

    QList<int> list;
    for (int i = 0; i < 96; ++i) {
        list.append(tabRegion[i]);
    }

    return list;
 }

 QList<int> Promotion::getBac() const
 {
     int bacCount[4] = {0}; // [0] -> Bac S, [1] -> Bac ES, [2] -> Bac L, [3] -> Bac STI

        for (const Student& s : students) {
            QString bac = s.getBac();
            if (bac == "S") {
                bacCount[0]++;
            } else if (bac == "ES") {
                bacCount[1]++;
            } else if (bac == "L") {
                bacCount[2]++;
            } else if (bac == "STI") {
                bacCount[3]++;
            }
        }

        QList<int> bacList;
        for (int i = 0; i < 4; ++i) {
            bacList.append(bacCount[i]);
        }

        return bacList;
}


QStringList Promotion::getList() const
{
    QStringList list;
        for (const Student& student : students) {

            list << student.getText();
        }
        return list;
}

/**
 * @brief Print the student information
*/
QDebug operator<<(QDebug  os, const Promotion& dt)
{
    for (const Student& student : dt.students)
    {
        os << student << "\n";
    }

    return os;
}
