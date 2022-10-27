#ifndef UNTITLED57_TREASURE_H
#define UNTITLED57_TREASURE_H

#include "PersonEvent.h"

class Treasure: public PersonEvent {
public:
    bool makeEvent(void* ev) override;
};

#endif