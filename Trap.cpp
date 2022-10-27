#include "Trap.h"

bool Trap::makeEvent(void* ev){
    int playerHP = ((Player*)ev)->getHP();
    if(playerHP > 25){
        ((Player*)ev)->changeHP(playerHP - 25);
        return true;
    }
    return false;
}

