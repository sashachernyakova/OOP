#include "FromStart.h"
#include "../Field/Field.h"

bool FromStart::makeEvent(void* ev){
    ((Field*)ev)->setPersonToStart();
    return true;
}
