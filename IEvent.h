#ifndef UNTITLED57_IEVENT_H
#define UNTITLED57_IEVENT_H

#include <iostream>

class IEvent{
public:
    virtual bool makeEvent(void* ev) = 0;
};

#endif
