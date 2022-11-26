#include "ErrorObserver.h"

ErrorObserver::ErrorObserver(IObservable* obj, ILog* pr): object(obj), pr(pr){
    obj->addObserver(this);
    type = Message::ERROR;
}

void ErrorObserver::update(int m, IObserver::Logger l) {
    switch(l){
        case someSteps:
            message = Message(type, "The player have gone " + std::to_string(m) + " steps. Next cell is unavailable\n");
            pr->print(message);
            break;

        case errorHeight:
            message = Message(type, "Height can not be negative. The height is set with default size 10.\n");
            pr->print(message);
            break;

        case errorWidth:
            message = Message(type, "Width can not be negative. The width is set with default size 10.\n");
            pr->print(message);
            break;

        case errorDirection:
            message = Message(type, "You entered error direction\n");
            pr->print(message);
            break;

        case errorStartNumber:
            message = Message(type, "You can not enter this number. The field is set with default sizes: 10x10\n");
            pr->print(message);
            break;

        default:
            break;
    }
}

ErrorObserver::~ErrorObserver() {
    delete pr;
    delete object;
}
