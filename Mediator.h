#ifndef UNTITLED57_MEDIATOR_H
#define UNTITLED57_MEDIATOR_H

#pragma once

#include "CommandReader.h"
#include "Controller.h"
#include "Output.h"

class Mediator{
    Controller* controller;
    CommandReader reader;
    std::string txt1;
    std::string txt2;
    int txt3;
    Output output;
public:
    Mediator();
    ~Mediator();
};

#endif
