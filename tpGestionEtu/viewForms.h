#pragma once

#include <QObject>
#include <QLineEdit>
#include <QComboBox>
#include "abstractcontroller.h"

class ViewForms : public QObject,Observer
{
    Q_OBJECT
    QLineEdit* lineEdit_remove_number;
    QLineEdit* lineEdit_add_number;
    QLineEdit* lineEdit_add_lastName;
    QLineEdit* lineEdit_add_firstName;
    QComboBox* lineEdit_add_BAC;
    QComboBox* lineEdit_add_department;
    Promotion* promo;
private slots :
    void removeId();
    void addEtu();

public:
    ViewForms(QLineEdit* lineEdit,Promotion* p);
    ViewForms(QLineEdit* lineEdit_add_number,QLineEdit* lineEdit_add_lastName,QLineEdit* lineEdit_add_firstName,QComboBox* lineEdit_add_BAC,QComboBox* lineEdit_add_department, Promotion* p);
    ~ViewForms();
    void update();
    void init();
};

