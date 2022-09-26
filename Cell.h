#ifndef UNTITLED57_CELL_H
#define UNTITLED57_CELL_H

#include <iostream>
#include "IEvent.h"
#include "Condition.h"

class Cell{
    bool onCell;
    Condition condition;
    IEvent* ev;

public:
    Cell(Condition condition = Condition::available, bool onCell = false);

    void changeEvent(IEvent* event);

    Condition getCondition();

    void stepOnCell();

    void stepFromCell();

    void changeCondition(Condition newCondition);

};

#endif
