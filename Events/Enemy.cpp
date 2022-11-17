#include "Enemy.h"

Enemy::Enemy(){
    srand(time(nullptr));
    hp = rand() % 80;
}

bool Enemy::makeEvent(void* ev){
    int playerHP = ((Player*)ev)->getHP();
    int playerXP = ((Player*)ev)->getXP();
    if(playerHP > hp){
        ((Player*)ev)->changeHP(playerHP + hp);
        ((Player*)ev)->changeXP(playerXP + 50);
        return true;
    }
    return false;
}

