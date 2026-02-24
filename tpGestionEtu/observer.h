#pragma once
#include <QList>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};

class Observable {
protected:
    QList<Observer*> observers;
public:
    virtual ~Observable() = default;
    void addObserver(Observer* observer) { observers.append(observer); }
    void removeObserver(Observer* observer) { observers.removeAll(observer); }
    void notifyObserver() const {
        for(Observer* observer : observers){
            observer->update();
        }
    }
};
