#ifndef UNTITLED57_FIELD_H
#define UNTITLED57_FIELD_H

#pragma once

#include <iostream>
#include <vector>
#include "Cell.h"
#include "Player.h"
#include "Trap.h"
#include "Treasure.h"
#include "Enemy.h"
#include "UnavailableFrame.h"
#include "FromStart.h"
#include "PlayerFieldObserver.h"
#include "ErrorObserver.h"
#include "GameObserver.h"

class Field: public IObservable{
    int h;
    int w;
    std::vector<std::vector<Cell>> field;
    int personX;
    int personY;
    Cell::Condition prevCondition;
    std::vector<IObserver*> observers;
    std::map <IObserver::Logger, int> mp;
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
    std::map <IObserver::Logger, int>& getMap();
    Cell::Condition getPrevCondition() const;
    bool canMove(Action action);
    void changePrevCondition(Cell::Condition condition);
    void makeFrame();
    void setPersonToStart();
    void addObserver(IObserver* o) override;
    void notify(int m, IObserver::Logger l) override;
    void stopGame();
    void gameStart();
    void errorHeight();
    void errorWidth();
    void errorDirection();
    void errorStartNumber();
};

#endif
