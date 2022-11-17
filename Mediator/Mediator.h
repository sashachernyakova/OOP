#ifndef UNTITLED57_MEDIATOR_H
#define UNTITLED57_MEDIATOR_H

#pragma once

#include "../Reader/ConsoleReader.h"
#include "../Controller/Controller.h"
#include "Output.h"
#include "../Reader/Reader.h"
#include "../Reader/FileReader.h"

class Mediator{
    Controller* controller;
    ConsoleReader reader;
    Reader* moveReader;
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
