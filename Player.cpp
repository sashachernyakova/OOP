#include "Player.h"

Player::Player(): hasSkipEvent(3), totalSteps(0), hasChangeEvent(5) {};

void Player::plusStep(){
    totalSteps += 1;
}

int Player::getTotalSteps() const{
    return totalSteps;
}

int Player::numberChangeEvent() const{
    return hasChangeEvent;
}

int Player::numberSkipEvent() const {
    return hasSkipEvent;
}