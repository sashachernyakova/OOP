#ifndef UNTITLED57_GAMEOBSERVER_H
#define UNTITLED57_GAMEOBSERVER_H

#pragma once

#include "IObservable.h"

class GameObserver: public IObserver{
private:
    IObservable* object;
    ILog* pr;
public:
    GameObserver(IObservable* obj, ILog* l);
    void update(int m, IObserver::Logger l) override;
};

#endif
