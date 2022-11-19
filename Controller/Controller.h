#ifndef UNTITLED57_CONTROLLER_H
#define UNTITLED57_CONTROLLER_H

#pragma once

#include "../Field/FieldView.h"
#include "../Player/Player.h"
#include "../Output/NoOutput.h"
#include "../Output/ConsoleOutput.h"
#include "../Output/FileOutput.h"
#include "../Output/FIleConsoleOutput.h"

class Controller{
    Player* alex;
    Field* field;
    FieldView* fieldView;
    std::string log;
    int pr;
    IObserver* o;
    ILog* l;
public:
    Controller(std::string log, int print, int y = 10, int x = 10);
    int changePlayerPosition (Field::Action action, int step);
    int movement(int steps, Field::Action action);
    void stop();
    void start();
    void errorH();
    void errorW();
    void errorD();
    void errorNumber();
    bool isDirection(std::string direction);
    void printField();
    Field::Action getAction(std::string direction);
    ~Controller();
};

#endif
