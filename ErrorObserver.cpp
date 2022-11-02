#include "ErrorObserver.h"

ErrorObserver::ErrorObserver(IObservable* obj): object(obj){
    obj->addObserver(this);
}

void ErrorObserver::update(int m, IObserver::Logger l) {
    switch(l){
        case someSteps:
            std::cout << "The player have gone " << m << " steps\n";
            break;

        case errorHeight:
            std::cout << "Height can not be negative. The height is set with default size 10.\n";
            break;

        case errorWidth:
            std::cout << "Width can not be negative. The width is set with default size 10.\n";
            break;

        case errorDirection:
            std::cout << "You entered error direction. You can enter: right, left, up, down\n";
            break;

        case errorStartNumber:
            std::cout << "You can not enter this number. The field is set with default sizes: 10x10\n";
            break;

        default:
            break;
    }

}
