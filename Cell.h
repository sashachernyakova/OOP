#ifndef UNTITLED57_CELL_H
#define UNTITLED57_CELL_H

#pragma once

#include <iostream>
#include "IEvent.h"

class Cell{
public:
    enum Condition{
        available,
        unavailable,
        personStand,
        eventP,
        eventF
    };

    Cell(Condition condition = Condition::available, IEvent* ev = nullptr);

    Cell(const Cell &other);

    Cell& operator = (const Cell &other);

    Cell(Cell&& other);

    Cell& operator = (Cell&& other);

    Condition getCondition();

    IEvent* getEvent();

    void changeEvent(IEvent* event);

    void changeCondition(Condition newCondition);

    ~Cell();
private:
    IEvent* ev;
    Cell::Condition condition;
};

#endif
