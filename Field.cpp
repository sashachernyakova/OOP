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

    mp.emplace(IObserver::win, 0);
    mp.emplace(IObserver::lose, 0);
    mp.emplace(IObserver::stopGame, 0);
    mp.emplace(IObserver::gameStart, 0);
    mp.emplace(IObserver::health, 100);
    mp.emplace(IObserver::experience, 0);
    mp.emplace(IObserver::experience, 0);
    mp.emplace(IObserver::treasure, 0);
    mp.emplace(IObserver::someSteps, 0);
    mp.emplace(IObserver::allSteps, 0);
    mp.emplace(IObserver::errorHeight, 0);
    mp.emplace(IObserver::errorWidth, 0);
    mp.emplace(IObserver::errorDirection, 0);
    mp.emplace(IObserver::errorStartNumber, 0);

    field[1][1] = Cell(Cell::Condition::unavailable);
    field[3][0] = Cell(Cell::Condition::unavailable);
    field[3][4] = Cell(Cell::Condition::unavailable);
    field[3][7] = Cell(Cell::Condition::unavailable);
    field[5][1] = Cell(Cell::Condition::unavailable);
    field[6][5] = Cell(Cell::Condition::unavailable);
    field[8][8] = Cell(Cell::Condition::unavailable);


    field[0][8].changeCondition(Cell::Condition::eventP);
    field[6][2].changeCondition(Cell::Condition::eventP);
    field[8][4].changeCondition(Cell::Condition::eventP);
    field[4][6].changeCondition(Cell::Condition::eventP);
    field[4][8].changeCondition(Cell::Condition::eventP);
    field[1][4].changeCondition(Cell::Condition::eventP);
    field[1][7].changeCondition(Cell::Condition::eventP);
    field[3][1].changeCondition(Cell::Condition::eventP);
    field[5][3].changeCondition(Cell::Condition::eventP);
    field[8][1].changeCondition(Cell::Condition::eventP);
    field[5][8].changeCondition(Cell::Condition::eventP);
    field[0][6].changeCondition(Cell::Condition::eventF);
    field[2][1].changeCondition(Cell::Condition::eventF);
    field[6][7].changeCondition(Cell::Condition::eventF);

    field[0][8].changeEvent(new Trap());
    field[6][2].changeEvent(new Trap());
    field[8][4].changeEvent(new Trap());
    field[4][6].changeEvent(new Enemy());
    field[4][8].changeEvent(new Enemy());
    field[1][4].changeEvent(new Enemy());
    field[1][7].changeEvent(new Treasure());
    field[3][1].changeEvent(new Treasure());
    field[5][3].changeEvent(new Treasure());
    field[8][1].changeEvent(new Treasure());
    field[5][8].changeEvent(new Treasure());
    field[0][6].changeEvent(new UnavailableFrame());
    field[2][1].changeEvent(new FromStart());
    field[6][7].changeEvent(new FromStart());

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

Cell* Field::getPersonCell(){
    return &(field[personY][personX]);
};


std::vector<std::vector<Cell>> Field::getField(){
    return field;
}

Cell::Condition Field::getPrevCondition() const{
    return prevCondition;
};

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

void Field::changePrevCondition(Cell::Condition condition) {
    prevCondition = condition;
}

void Field::makeFrame() {
    for(int i = 0; i< h; i++){
        field[i][w-1].changeCondition(Cell::Condition::unavailable);
    }
    for(int i = 0; i< w-1; i++){
        field[h-1][i].changeCondition(Cell::Condition::unavailable);
    }
    for(int i = 0; i< h-1; i++){
        field[i][0].changeCondition(Cell::Condition::unavailable);
    }
}

void Field::setPersonToStart() {
    field[personY][personX].changeCondition(prevCondition);
    field[0][0].changeCondition(Cell::Condition::personStand);
    personX = 0;
    personY = 0;
    prevCondition = Cell::available;
}

void Field::addObserver(IObserver *o) {
    observers.push_back(o);
}

void Field::removeObserver(IObserver *o) {
    observers.erase(remove(observers.begin(), observers.end(), o), observers.end());
}

void Field::notify(int m, IObserver::Logger l) {
    for(auto o: observers){
        o->update(m, l);
    }
}

std::map<IObserver::Logger, int>& Field::getMap(){
    return mp;
}

void Field::stopGame() {
    notify(mp[IObserver::stopGame], IObserver::stopGame);
}

void Field::gameStart() {
    notify(mp[IObserver::gameStart], IObserver::gameStart);
}

void Field::errorHeight() {
    notify(mp[IObserver::errorHeight], IObserver::errorHeight);
}

void Field::errorWidth() {
    notify(mp[IObserver::errorWidth], IObserver::errorWidth);
}

void Field::errorDirection() {
    notify(mp[IObserver::errorDirection], IObserver::errorDirection);
}

void Field::errorStartNumber() {
    notify(mp[IObserver::errorStartNumber], IObserver::errorStartNumber);
}
