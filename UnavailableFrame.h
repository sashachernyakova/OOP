#ifndef UNTITLED57_UNAVAILABLEFRAME_H
#define UNTITLED57_UNAVAILABLEFRAME_H

#include "FieldEvent.h"

class UnavailableFrame: public FieldEvent{
public:
    bool makeEvent(void* ev) override;
};

#endif
