#include "UnavailableFrame.h"
#include "../Field/Field.h"

bool UnavailableFrame::makeEvent(void* ev){
    ((Field*)ev)->makeFrame();
    return true;
}
