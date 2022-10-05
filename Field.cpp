#include "Field.h"

Field::Field(int h, int w):h(h), w(w){
    prevCondition = Cell::Condition::available;

    field.resize(h);
    for (int i = 0; i < h; i++){
        field[i].resize(w);
        for (int j = 0; j < w; j++) {
            field[i][j] = Cell();
        }
    }

    srand(time(nullptr));
    int len = int(h * w * 2 / 10);
    for (int i = 0; i < len;  i++){
        field[rand() % h][rand() % w] = Cell(Cell::Condition::unavailable);
    }

    len = int(h * w / 10);
    for (int i = 0; i < len;  i++){
        field[rand() % h][rand() % w] = Cell(Cell::Condition::event);
    }
    field[0][0] = Cell(Cell::Condition::personStand);
    personX = 0;
    personY = 0;
}

Field::Field(const Field &other){
    this->h = other.h;
    this->w = other.w;
    this->field = other.field;
    this->personX = other.personX;
    this->personY = other.personY;
    this->prevCondition = other.prevCondition;
}


Field& Field::operator = (const Field &other){
    this->h = other.h;
    this->w = other.w;
    this->field = other.field;
    this->personX = other.personX;
    this->personY = other.personY;
    this->prevCondition = other.prevCondition;
    return *this;
}

Field::Field(Field&& other){
    this->h = other.h;
    this->w = other.w;
    this->field = std::move(other.field);
    this->personX = other.personX;
    this->personY = other.personY;
    this->prevCondition = other.prevCondition;
}

Field& Field::operator = (Field&& other){
    this->h = other.h;
    this->w = other.w;
    this->field = std::move(other.field);
    this->personX = other.personX;
    this->personY = other.personY;
    this->prevCondition = other.prevCondition;
    return *this;
}


int Field::getWidth() const{
    return w;
};

int Field::getHeight() const{
    return h;
};

std::vector<std::vector<Cell>> Field::getField(){
    return field;
}

bool Field::canMove(Action action){
    Cell::Condition nextCellCondition;
    switch(action){
        case right:{
            personX != (w - 1) ? nextCellCondition = field[personY][personX + 1].getCondition() : nextCellCondition = field[personY][0].getCondition();
            break;
        }
        case left:{
            personX != 0 ? nextCellCondition = field[personY][personX - 1].getCondition() : nextCellCondition = field[personY][w - 1].getCondition();
            break;
        }
        case down:{
            personY != (h - 1) ? nextCellCondition = field[personY + 1][personX].getCondition() : nextCellCondition = field[0][personX].getCondition();
            break;
        }
        case up:{
            personY != 0 ? nextCellCondition = field[personY - 1][personX].getCondition() : nextCellCondition = field[h - 1][personX].getCondition();
            break;
        }
    }

    if (nextCellCondition != Cell::Condition::unavailable){
        field[personY][personX].changeCondition(prevCondition);
        switch(action){
            case right:{
                personX != (w - 1) ? personX += 1 : personX = 0;
                break;
            }
            case left:{
                personX != 0 ? personX -= 1 : personX = w - 1;
                break;
            }
            case down:{
                personY != (h - 1) ? personY += 1 : personY = 0;
                break;
            }
            case up:{
                personY != 0 ? personY -= 1 :  personY = h - 1;
                break;
            }
        }
        prevCondition = field[personY][personX].getCondition();
        field[personY][personX].changeCondition(Cell::Condition::personStand);
        return true;
    }
    return false;
}