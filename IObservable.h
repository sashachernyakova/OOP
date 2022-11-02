#ifndef UNTITLED57_IOBSERVABLE_H
#define UNTITLED57_IOBSERVABLE_H

#pragma once

#include "IObserver.h"

class IObservable {
public:
    virtual void addObserver(IObserver *o) = 0;
    virtual void removeObserver(IObserver *o) = 0;
    virtual void notify(int m, IObserver::Logger l) = 0;
};

#endif
