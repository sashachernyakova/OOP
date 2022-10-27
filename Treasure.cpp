#include "Treasure.h"

bool Treasure::makeEvent(void* ev){
    int playerHP = ((Player*)ev)->getHP();
    if(playerHP > 15){
        ((Player*)ev)->changeHP(playerHP - 15);
        ((Player*)ev)->changeTreasure();
        return true;
    }
    return false;
}