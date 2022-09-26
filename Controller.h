#ifndef UNTITLED57_CONTROLLER_H
#define UNTITLED57_CONTROLLER_H

#include "FieldView.h"
#include "Player.h"


class Controller{
    Player alex = Player();
    Field field = Field(&alex);
    FieldView fieldView = FieldView(&field);
public:
    Controller();

    Controller(int y, int x);

    void movement(int steps, std::string action);

    void printStartField();

    void level();

};

#endif
