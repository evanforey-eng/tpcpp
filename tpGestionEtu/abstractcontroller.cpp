#include "abstractcontroller.h"

AbstractController::AbstractController()
{

}

DeleteList::DeleteList(Promotion *p)
{
    promo=p;
}

void DeleteList::control(QStringList list)
{
    for(QString s : list){
        promo->remove(s);
    }
}

DeleteForm::DeleteForm(Promotion *p)
{
    promo=p;
}

void DeleteForm::control(QStringList list)
{
    QString s = list[0];
    Student etu = promo->find(s);
    promo->remove(etu);
}

AddForm::AddForm(Promotion *p)
{
    promo=p;
}

void AddForm::control(QStringList list)
{
    if(list[0].isEmpty() || list[1].isEmpty() || list[2].isEmpty() || list[3].isEmpty() || list[4].isEmpty()){
        ErreurDialog dlg("Tous les champs doivent être remplis !");
        dlg.exec();
        return;
    }
    Student etu(list[0],list[1],list[2],list[3],list[4]);
    promo->add(etu);
}
