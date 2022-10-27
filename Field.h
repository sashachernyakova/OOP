#ifndef UNTITLED57_FIELD_H
#define UNTITLED57_FIELD_H

#include <iostream>
#include <vector>
#include "Cell.h"
#include "Player.h"
#include "Trap.h"
#include "Treasure.h"
#include "Enemy.h"
#include "UnavailableFrame.h"
#include "FromStart.h"

class Field{
    int h;
    int w;
    std::vector<std::vector<Cell>> field;
    int personX;
    int personY;
    Cell::Condition prevCondition;
public:
    enum Action{
        right,
        left,
        up,
        down
    };

    Field(int h = 10, int w = 10);
    Field(const Field &other);
    Field& operator = (const Field &other);
    Field(Field&& other);
    Field& operator = (Field&& other);
    int getWidth() const;
    int getHeight() const;
    Cell* getPersonCell();
    std::vector<std::vector<Cell>> getField();
    Cell::Condition getPrevCondition() const;
    bool canMove(Action action);
    void changePrevCondition(Cell::Condition condition);
    void makeFrame();
    void setPersonToStart();
};

#endif
