#pragma once
#include <QList>
#include <QDebug>
#include <QFile>
#include "student.h"
#include "observer.h"
#include "erreurdialog.h"

/**
 * @brief Promotion manage the list of students
 * @author Fabrice Jaillet
*/
class Promotion : public Observable
{
private:
    QList<Student> students;

public:
    Promotion(QString filename);
    ~Promotion() { qDebug() << "[-] Promotion"; }

    void add(const Student&);
    void remove(const Student&);
    void remove(const QString &);

    Student find(QString) const;
    QList<int> getDep() const;
    QList<int> getBac() const;

    friend QDebug operator<<(QDebug os, const Promotion& dt);

    QStringList getList() const;


};

QDebug operator<<(QDebug os, const Promotion& dt);

