#include "GameObserver.h"

GameObserver::GameObserver(IObservable* obj, ILog* pr): object(obj), pr(pr){
    obj->addObserver(this);
    type = Message::GAME;
}

void GameObserver::update(int m, IObserver::Logger l) {
    switch(l){
        case win:
            message = Message(type, "Congratulations! You have 5 treasures. You win!\n");
            pr->print(message);
            break;

        case lose:
            message = Message(type, "Game over, you lost all your health\n");
            pr->print(message);
            break;

        case gameStart:
            message = Message(type, "The game starts\n");
            pr->print(message);
            break;

        case stopGame:
            message = Message(type, "The player decided to stop game\n");
            pr->print(message);
            break;

        default:
            break;
    }
}