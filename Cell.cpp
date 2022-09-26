#include "Cell.h"

Cell::Cell(Condition condition, bool onCell):condition(condition), onCell(onCell){
};

void Cell::changeEvent(IEvent* event){
    ev = event;
}


Condition Cell::getCondition(){
    return condition;
}

void Cell::stepOnCell(){
    onCell = true;
}

void Cell::stepFromCell(){
    onCell = false;
}

void Cell::changeCondition(Condition newCondition){
    condition = newCondition;
}

