#ifndef UNTITLED57_PLAYERFIELDOBSERVER_H
#define UNTITLED57_PLAYERFIELDOBSERVER_H

#pragma once

#include "IObservable.h"

class PlayerFieldObserver: public IObserver{
private:
    IObservable* object;
public:
    PlayerFieldObserver(IObservable* obj);
    void update(int m, IObserver::Logger l) override;
};

#endif
