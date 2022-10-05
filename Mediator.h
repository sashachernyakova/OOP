#ifndef UNTITLED57_MEDIATOR_H
#define UNTITLED57_MEDIATOR_H

#include "CommandReader.h"
#include "Controller.h"


class Mediator{
    Controller* controller;
    CommandReader reader;
    std::string size1;
    std::string size2;
public:
    Mediator();
    ~Mediator();
};

#endif
