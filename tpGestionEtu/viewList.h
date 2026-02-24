#pragma once

#include <QObject>
#include <QListWidget>
#include "abstractcontroller.h"

/**
 * @brief Class to manage the QListWidget
 * @author Adrien Peytavie
*/
class ViewList : public QObject,Observer
{
    Q_OBJECT
    Promotion* promo;
    QListWidget* list;
private slots :
    void remove();


public:
    ViewList(Promotion* promo,QListWidget* listWidget);
    ~ViewList();
    void update();
};

