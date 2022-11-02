#include "GameObserver.h"

GameObserver::GameObserver(IObservable* obj): object(obj){
    obj->addObserver(this);
}

void GameObserver::update(int m, IObserver::Logger l) {
    switch(l){
        case win:
            std::cout << "Congratulations! You have 5 treasures. You win!" << "\n";
            break;

        case lose:
            std::cout << "game over, you lost all your health" << "\n";
            break;

        case gameStart:
            std::cout << "The game starts" << "\n";
            break;

        case stopGame:
            std::cout << "The player decided to stop game" << "\n";
            break;

        default:
            break;
    }

}