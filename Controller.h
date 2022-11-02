#ifndef UNTITLED57_CONTROLLER_H
#define UNTITLED57_CONTROLLER_H

#pragma once

#include "FieldView.h"
#include "Player.h"

class Controller{
    Player* alex;
    Field* field;
    FieldView* fieldView;
    int log;
    IObserver* o;
public:
    Controller(int log, int y = 10, int x = 10);
    int changePlayerPosition (Field::Action action, int step);
    int movement(int steps, Field::Action action);
    void steps();
    void stop();
    void start();
    void errorH();
    void errorW();
    void errorD();
    void errorNumber();
    bool isDirection(std::string direction);
    Field::Action getAction(std::string direction);
    ~Controller();
};

#endif
