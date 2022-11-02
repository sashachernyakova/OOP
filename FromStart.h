#ifndef UNTITLED57_FROMSTART_H
#define UNTITLED57_FROMSTART_H

#pragma once

#include "FieldEvent.h"

class FromStart: public FieldEvent{
public:
    bool makeEvent(void* ev) override;
};

#endif
