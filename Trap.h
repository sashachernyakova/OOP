#ifndef UNTITLED57_TRAP_H
#define UNTITLED57_TRAP_H

#include "PersonEvent.h"

class Trap: public PersonEvent{
public:
    bool makeEvent(void* ev) override;
};

#endif
