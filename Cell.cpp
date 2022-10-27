#include "Cell.h"

Cell::Cell(Cell::Condition condition, IEvent* ev):condition(condition),ev(ev){
}

Cell::Condition Cell::getCondition(){
    return condition;
}

IEvent* Cell::getEvent(){
    return ev;
};

Cell::Cell(const Cell &other){
    this->condition = other.condition;
    this->ev = nullptr;
};

Cell& Cell::operator = (const Cell &other){
    if (this->ev){
        delete this;
    }
    this->condition = other.condition;
    this->ev = nullptr;
    return *this;
};

Cell::Cell(Cell&& other){
    this->condition = other.condition;
    this->ev = nullptr;
};

Cell& Cell::operator = (Cell&& other){
    if (this->ev){
        delete this;
    }
    this->condition = other.condition;
    this->ev = nullptr;
    return *this;
};

void Cell::changeEvent(IEvent* event){
    if(ev){
        delete ev;
    }
    ev = event;
}

void Cell::changeCondition(Cell::Condition newCondition){
    condition = newCondition;
}

Cell::~Cell() {
    delete ev;
}


