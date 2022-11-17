#ifndef UNTITLED57_FIELDEVENT_H
#define UNTITLED57_FIELDEVENT_H

#pragma once

#include "IEvent.h"

class FieldEvent: public IEvent{
public:
    virtual bool makeEvent(void* ev) = 0;
};

#endif
