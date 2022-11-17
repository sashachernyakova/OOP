#ifndef UNTITLED57_TREASURE_H
#define UNTITLED57_TREASURE_H

#pragma once

#include "PersonEvent.h"

class Treasure: public PersonEvent {
public:
    bool makeEvent(void* ev) override;
};

#endif