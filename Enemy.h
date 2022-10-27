#ifndef UNTITLED57_ENEMY_H
#define UNTITLED57_ENEMY_H

#include "PersonEvent.h"

class Enemy: public PersonEvent{
    int hp;
public:
    Enemy();
    bool makeEvent(void* ev) override;
};

#endif
