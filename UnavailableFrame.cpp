#include "UnavailableFrame.h"
#include "Field.h"

bool UnavailableFrame::makeEvent(void* ev){
    ((Field*)ev)->makeFrame();
    return true;
}
