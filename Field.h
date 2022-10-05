#ifndef UNTITLED57_FIELD_H
#define UNTITLED57_FIELD_H

#include <iostream>
#include <vector>
#include "Cell.h"
#include "Player.h"

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

    std::vector<std::vector<Cell>> getField();

    bool canMove(Action action);

};

#endif
