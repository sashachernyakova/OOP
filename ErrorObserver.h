#ifndef UNTITLED57_ERROROBSERVER_H
#define UNTITLED57_ERROROBSERVER_H

#pragma once

#include "IObservable.h"

class ErrorObserver: public IObserver{
private:
    IObservable* object;
    ILog* pr;
public:
    ErrorObserver(IObservable* obj, ILog* p);
    void update(int m, IObserver::Logger l) override;
};


#endif
