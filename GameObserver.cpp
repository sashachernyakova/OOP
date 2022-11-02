#include "GameObserver.h"

GameObserver::GameObserver(IObservable* obj, ILog* pr): object(obj), pr(pr){
    obj->addObserver(this);
}

void GameObserver::update(int m, IObserver::Logger l) {
    switch(l){
        case win:
            pr->print("Congratulations! You have 5 treasures. You win!\n");
            break;

        case lose:
            pr->print("Game over, you lost all your health\n");
            break;

        case gameStart:
            pr->print("The game starts\n");
            break;

        case stopGame:
            pr->print("The player decided to stop game\n");
            break;

        default:
            break;
    }

}