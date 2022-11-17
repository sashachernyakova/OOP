#ifndef UNTITLED57_MEDIATOR_H
#define UNTITLED57_MEDIATOR_H

#pragma once

#include "../Reader/CommandReader.h"
#include "../Controller/Controller.h"
#include "Output.h"

class Mediator{
    Controller* controller;
    CommandReader reader;
    std::string txt1;
    std::string txt2;
    std::string log;
    int print;
    Output output;
public:
    Mediator();
    ~Mediator();
};

#endif
