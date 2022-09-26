#include "Field.h"

void Field::swap(Field& other){
    std::swap(vert, other.vert);
    std::swap(hor, other.hor);
    std::swap(field, other.field);
    std::swap(personX, other.personX);
    std::swap(personY, other.personY);
    std::swap(prevCondition, other.prevCondition);
};

Field::Field(Player* player, int vertic, int horizont):player(player), vert(vertic), hor(horizont){
    prevCondition = Condition::available;

    field.resize(vert);
    for (int i = 0; i < vert; i++){
        field[i].resize(hor);
    }

    for (int i = 0; i < vert; i++) {
        for (int j = 0; j < hor; j++) {
            field[i][j] = Cell();
        }
    }

    srand(time(nullptr));
    int len = int(vert * hor * 2 / 10);
    for (int i = 0; i < len;  i++){
        field[rand() % vert][rand() % hor] = Cell(Condition::unavailable);
    }

    len = int(vert * hor / 10);
    for (int i = 0; i < len;  i++){
        field[rand() % vert][rand() % hor] = Cell(Condition::event);
    }
    field[0][0] = Cell(Condition::personStand);
    field[0][0].stepOnCell();
    personX = 0;
    personY = 0;
}

Field::Field(const Field &other): vert(other.vert), hor(other.hor), field(other.field), personX(other.personX), personY(other.personY), prevCondition(other.prevCondition) {}


Field& Field::operator = (const Field &other){
    if (this != &other)
        Field(other).swap(*this);

    return *this;
}

Field::Field(Field&& other){
    this->swap(other);
}

Field& Field::operator = (Field&& other){
    if (this != &other)
        this->swap(other);
    return *this;
}


int Field::getGor() const{
    return hor;
};

int Field::getVert() const{
    return vert;
};

std::vector<std::vector<Cell>> Field::getField(){
    return field;
}

Field::Action Field::getAction(char firstLetter){
    switch(firstLetter){
        case 'r':{
            return right;
        }
        case 'l':{
            return left;
        }
        case 'u':{
            return up;
        }
        case 'd':{
            return down;
        }
        default:{
            break;
        }
    }
}


bool Field::canMove(Action action){
    Condition nextCellCondition;
    if(action == right){
        if (personX != (hor - 1)){
            nextCellCondition = field[personY][personX + 1].getCondition();
        } else{
            nextCellCondition = field[personY][0].getCondition();
        }
        if (nextCellCondition != Condition::unavailable){
            field[personY][personX].stepFromCell();
            field[personY][personX].changeCondition(prevCondition);
            if (personX != (hor - 1)){
                personX += 1;
            } else{
                personX = 0;
            }
            field[personY][personX].stepOnCell();
            prevCondition = field[personY][personX].getCondition();
            field[personY][personX].changeCondition(Condition::personStand);
            return true;
        }
        return false;

    } else if (action == left){
        if (personX != 0){
            nextCellCondition = field[personY][personX - 1].getCondition();
        } else{
            nextCellCondition = field[personY][hor - 1].getCondition();
        }
        if (nextCellCondition != Condition::unavailable){
            field[personY][personX].stepFromCell();
            field[personY][personX].changeCondition(prevCondition);
            if (personX != 0){
                personX -= 1;
            } else{
                personX = hor - 1;
            }
            field[personY][personX].stepOnCell();
            prevCondition = field[personY][personX].getCondition();
            field[personY][personX].changeCondition(Condition::personStand);
            return true;
        }
        return false;
    } else if (action == down){
        if (personY != (vert - 1)){
            nextCellCondition = field[personY + 1][personX].getCondition();
        } else{
            nextCellCondition = field[0][personX].getCondition();
        }
        if (nextCellCondition != Condition::unavailable){
            field[personY][personX].stepFromCell();
            field[personY][personX].changeCondition(prevCondition);
            if (personY != (vert - 1)){
                personY += 1;
            } else{
                personY = 0;
            }
            field[personY][personX].stepOnCell();
            prevCondition = field[personY][personX].getCondition();
            field[personY][personX].changeCondition(Condition::personStand);
            return true;
        }
        return false;
    } else {
        if (personY != 0) {
            nextCellCondition = field[personY - 1][personX].getCondition();
        } else {
            nextCellCondition = field[vert - 1][personX].getCondition();
        }
        if (nextCellCondition != Condition::unavailable) {
            field[personY][personX].stepFromCell();
            field[personY][personX].changeCondition(prevCondition);
            if (personY != 0){
                personY -= 1;
            } else{
                personY = vert - 1;
            }
            field[personY][personX].stepOnCell();
            prevCondition = field[personY][personX].getCondition();
            field[personY][personX].changeCondition(Condition::personStand);
            return true;
        }
        return false;
    }
}

void Field::changePlayerPosition (std::string action, int step){
    int counter;
    int flag = 0;
    switch(action[0]){
        case 'r': {
            counter = 0;
            while(counter < step){
                if (canMove(right)){
                    counter += 1;
                    (*player).plusStep();
                } else{
                    flag = 1;
                    std::cout << "The player have gone only "  << counter <<  " steps right. Next cell is unavailable.\n";
                    break;
                }
            }
            if (flag != 1) {
                std::cout << "The player have gone "  << step << " steps right\n";
            }
            break;
        }
        case 'l': {
            counter = 0;
            while(counter < step){
                if (canMove(left)){
                    counter += 1;
                    (*player).plusStep();
                } else{
                    flag = 1;
                    std::cout << "The player have gone only "  << counter << " steps left. Next cell is unavailable.\n";
                    break;
                }

            }
            if (flag != 1) {
                std::cout << "The player have gone " << step << " steps left\n";
            }
            break;
        }
        case 'u': {
            counter = 0;
            while(counter < step){
                if (canMove(up)){
                    counter += 1;
                    (*player).plusStep();
                } else{
                    flag = 1;
                    std::cout << "The player have gone only "  << counter << " steps up. Next cell is unavailable.\n";
                    break;
                }

            }
            if (flag != 1) {
                std::cout << "The player have gone " << step << " steps up\n";
            }
            break;
        }
        case 'd': {
            counter = 0;
            while(counter < step){
                if (canMove(down)){
                    counter += 1;
                    (*player).plusStep();
                } else{
                    flag = 1;
                    std::cout << "The player have gone only "  << counter << " steps down. Next cell is unavailable.\n";
                    break;
                }

            }
            if (flag != 1) {
                std::cout << "The player have gone " << step << " steps down\n";
            }
            break;
        }
    }

}


