#include "ErrorObserver.h"

ErrorObserver::ErrorObserver(IObservable* obj, ILog* pr): object(obj), pr(pr){
    obj->addObserver(this);
}

void ErrorObserver::update(int m, IObserver::Logger l) {
    switch(l){
        case someSteps:
            pr->print("The player have gone " + std::to_string(m) + " steps\n");
            break;

        case errorHeight:
            pr->print("Height can not be negative. The height is set with default size 10.\n");
            break;

        case errorWidth:
            pr->print("Width can not be negative. The width is set with default size 10.\n");
            break;

        case errorDirection:
            pr->print("You entered error direction. You can enter: right, left, up, down\n");
            break;

        case errorStartNumber:
            pr->print("You can not enter this number. The field is set with default sizes: 10x10\n");
            break;

        default:
            break;
    }

}
