#include "PlayerFieldObserver.h"

PlayerFieldObserver::PlayerFieldObserver(IObservable* obj): object(obj){
    obj->addObserver(this);
}

void PlayerFieldObserver::update(int m, IObserver::Logger l) {
    switch(l){
        case health:
            std::cout << "The player's health is " << m << "\n";
            break;

        case experience:
            std::cout << "The player's experience is " << m << "\n";
            break;

        case treasure:
            std::cout << "The player's treasure is " << m << "\n";
            break;

        case allSteps:
            std::cout << "The player have gone all " << m  << " steps\n";
            break;

        default:
            break;
    }
}



