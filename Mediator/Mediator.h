#ifndef UNTITLED57_MEDIATOR_H
#define UNTITLED57_MEDIATOR_H

#pragma once

#include "../Reader/ConsoleReader.h"
#include "../Controller/Controller.h"
#include "Output.h"
#include "../Reader/Reader.h"
#include "../Reader/NavigationReader.h"
#include "../Reader/FileNavigation.h"


class Mediator{
    Controller* controller;
    ConsoleReader reader;
    Reader* moveReader;
    NavigationReader* navigationReader;
    Output output;
    std::string str;
    std::string log;
    int print;
public:
    Mediator();
    void start();
    void makeVector(std::vector <std::string>& vec, std::string str);
    ~Mediator();
};

#endif
