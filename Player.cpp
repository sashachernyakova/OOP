#include "Player.h"

Player::Player(): totalSteps(0), hp(100), xp(0), treasure(0) {}

int Player::getTotalSteps() const{
    return totalSteps;
}

int Player::getHP() const{
    return hp;
}

int Player::getXP() const {
    return xp;
}

int Player::getTreasure() const {
    return treasure;
}

void Player::makeStep(){
    totalSteps += 1;
}

void Player::changeHP(int newHP){
    hp = newHP;
}

void Player::changeXP(int newXP){
    xp = newXP;
}

void Player::changeTreasure(){
    treasure +=1 ;
}