#include "PlayerFieldObserver.h"

PlayerFieldObserver::PlayerFieldObserver(IObservable* obj, ILog* pr): object(obj), pr(pr){
    obj->addObserver(this);
    type = Message::STATUS;
}

void PlayerFieldObserver::update(int m, IObserver::Logger l) {
    switch(l){
        case health:
            message = Message(type, "The player's health is " + std::to_string(m) +  "\n");
            pr->print(message);
            break;

        case experience:
            message = Message(type, "The player's experience is " + std::to_string(m) +  "\n");
            pr->print(message);
            break;

        case treasure:
            message = Message(type, "The player's treasure is " + std::to_string(m) +  "\n");
            pr->print(message);
            break;

        case allSteps:
            message = Message(type, "The player have gone all " + std::to_string(m) +  " steps\n");
            pr->print(message);
            break;

        default:
            break;
    }
}



