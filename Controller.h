#ifndef UNTITLED57_CONTROLLER_H
#define UNTITLED57_CONTROLLER_H

#include "FieldView.h"
#include "Player.h"
#include "Output.h"

class Controller{
    Player* alex;
    Field* field;
    FieldView* fieldView;
    Output output;
public:
    Controller(int y = 10, int x = 10);
    int changePlayerPosition (Field::Action action, int step);
    int movement(int steps, Field::Action action);
    void steps();
    bool isDirection(std::string direction);
    Field::Action getAction(std::string direction);
    ~Controller();
};

#endif
