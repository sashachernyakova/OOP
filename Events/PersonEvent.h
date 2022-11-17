#ifndef UNTITLED57_PERSONEVENT_H
#define UNTITLED57_PERSONEVENT_H

#pragma once

#include "IEvent.h"
#include "../Player/Player.h"

class PersonEvent: public IEvent{
public:
    virtual bool makeEvent(void* ev) = 0;
};

#endif
