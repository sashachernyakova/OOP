#include "Player.h"

Player::Player(): totalSkipEvent(3), totalSteps(0), totalChangeEvent(5) {};

void Player::makeStep(){
    totalSteps += 1;
}

int Player::getTotalSteps() const{
    return totalSteps;
}

int Player::getChangeEvent() const{
    return totalChangeEvent;
}

int Player::getSkipEVent() const {
    return totalSkipEvent;
}