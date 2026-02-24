#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H

#include "promotion.h"
#include "erreurdialog.h"
#include <QStringList>

class AbstractController
{
protected :
    Promotion* promo;
public:
    AbstractController();
    virtual void control(QStringList list) = 0;
};


class AddForm : public AbstractController{

public:
    AddForm(Promotion* p);
    void control(QStringList list) override;

};

class DeleteForm : public AbstractController{

public:
    DeleteForm(Promotion* p);
    void control(QStringList list) override;

};

class DeleteList : public AbstractController{

public:
    DeleteList(Promotion* p);
    void control(QStringList list) override;

};


#endif // ABSTRACTCONTROLLER_H
