#include "viewList.h"

#include <QListWidget>

void ViewList::remove()
{
    QList<QListWidgetItem*> item = list->selectedItems();
    QStringList listStringSelected;

    for(QListWidgetItem* w : item){
    listStringSelected.append(w->text());
    }
    DeleteList controlDelete(promo);
    controlDelete.control(listStringSelected);
}


ViewList::ViewList(Promotion *promo, QListWidget *listWidget): promo(promo),list(listWidget)
{
    promo->addObserver(this);
    ViewList::update();
}

ViewList::~ViewList()
{
    qDebug()<< "[-]viewList";
}

void ViewList::update()
{
    list->clear();
    list->addItems(promo->getList());
}

