#include <iostream>
#include <vector>
#include "Cell.h"
#include "Player.h"

class Field{
    Player* player;
    int vert;
    int hor;
    std::vector<std::vector<Cell>> field;
    int personX;
    int personY;
    Condition prevCondition;
    void swap(Field& other);
public:
    enum Action{
        right,
        left,
        up,
        down
    };

    Field(Player* player, int vertic = 10, int horizont = 10);

    Field(const Field &other);

    Field& operator = (const Field &other);

    Field(Field&& other);

    Field& operator = (Field&& other);

    int getGor() const;

    int getVert() const;

    std::vector<std::vector<Cell>> getField();

    Action getAction(char firstLetter);

    bool canMove(Action action);

    void changePlayerPosition (std::string action, int step);
};