#include "viewForms.h"

void ViewForms::removeId()
{
    QStringList list;
    QString num =lineEdit_remove_number->text();
    list << num;

    DeleteForm controlDeleteForm(promo);
    controlDeleteForm.control(list);
}

void ViewForms::addEtu()
{
    QStringList list;
    QString num=lineEdit_add_number->text();
    QString fName =lineEdit_add_firstName->text();
    QString lName =lineEdit_add_lastName->text();
    QString bac = lineEdit_add_BAC->currentText();
    QString dep = lineEdit_add_department->currentText();
    list<<num;
    list<<fName;
    list<<lName;
    list<<bac;
    list<<dep;
    AddForm controlAddForm(promo);
    controlAddForm.control(list);
}

ViewForms::ViewForms(QLineEdit *lineEdit, Promotion *p) :lineEdit_remove_number(lineEdit), promo(p)
{
    promo->addObserver(this);
    lineEdit_add_number = nullptr;
    lineEdit_add_lastName= nullptr;
    lineEdit_add_firstName= nullptr;
    lineEdit_add_BAC= nullptr;
    lineEdit_add_department= nullptr;
}

ViewForms::ViewForms(QLineEdit *lineEdit_add_number, QLineEdit *lineEdit_add_lastName, QLineEdit *lineEdit_add_firstName, QComboBox *lineEdit_add_BAC, QComboBox *lineEdit_add_department, Promotion *p)
    :lineEdit_add_number(lineEdit_add_number),lineEdit_add_lastName(lineEdit_add_lastName),lineEdit_add_firstName(lineEdit_add_firstName),lineEdit_add_BAC(lineEdit_add_BAC), lineEdit_add_department(lineEdit_add_department),promo(p)
{
    lineEdit_remove_number = nullptr;
    promo->addObserver(this);
    init();
}

ViewForms::~ViewForms()
{
    qDebug()<< "[-]viewForms";
}

void ViewForms::update()
{
    if(lineEdit_add_number) lineEdit_add_number->clear();
    if(lineEdit_add_firstName) lineEdit_add_firstName->clear();
    if(lineEdit_add_lastName) lineEdit_add_lastName->clear();
    if(lineEdit_add_BAC) lineEdit_add_BAC->setCurrentIndex(0);
    if(lineEdit_add_department) lineEdit_add_department->setCurrentIndex(0);
    if(lineEdit_remove_number) lineEdit_remove_number->clear();
}

void ViewForms::init()
{    
    QStringList listBAC;
    listBAC << "S" << "ES" << "L" << "STI";
    lineEdit_add_BAC->addItems(listBAC);

    QStringList dep;
    QString s;
    for(int i=1;i<=96;i++){
        s= QString::number(i);;
        dep<<s;
    }

    lineEdit_add_department->addItems(dep);
}



