#include "PlayerFieldObserver.h"

PlayerFieldObserver::PlayerFieldObserver(IObservable* obj, ILog* pr): object(obj), pr(pr){
    obj->addObserver(this);
}

void PlayerFieldObserver::update(int m, IObserver::Logger l) {
    switch(l){
        case health:
            pr->print("The player's health is " + std::to_string(m) +  "\n");
            break;

        case experience:
            pr->print("The player's experience is " + std::to_string(m) +  "\n");
            break;

        case treasure:
            pr->print("The player's treasure is " + std::to_string(m) +  "\n");
            break;

        case allSteps:
            pr->print("The player have gone all " + std::to_string(m) +  " steps\n");
            break;

        default:
            break;
    }
}



