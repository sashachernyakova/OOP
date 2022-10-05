#ifndef UNTITLED57_CONTROLLER_H
#define UNTITLED57_CONTROLLER_H


#include "FieldView.h"
#include "Player.h"


class Controller{
    Player* alex;
    Field* field;
    FieldView* fieldView;
public:

    Controller(int y = 10, int x = 10);

    void changePlayerPosition (Field::Action action, int step);

    void movement(int steps, Field::Action action);

    void steps();

    ~Controller();



};

#endif
