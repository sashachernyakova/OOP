#ifndef UNTITLED57_MEDIATOR_H
#define UNTITLED57_MEDIATOR_H

#include "CommandReader.h"
#include "Output.h"
#include "Controller.h"

class Mediator{
    Controller* controller;
    CommandReader reader;
    Output output;
    std::string txt1;
    std::string txt2;
public:
    Mediator();
    ~Mediator();
};

#endif
