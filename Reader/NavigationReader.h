#ifndef UNTITLED57_NAVIGATIONREADER_H
#define UNTITLED57_NAVIGATIONREADER_H

#include "../Controller/Controller.h"
class NavigationReader{
public:
    virtual void madeVecDirection(void* s) = 0;
    virtual std::vector <std::string> returnVec() = 0;
};

#endif
