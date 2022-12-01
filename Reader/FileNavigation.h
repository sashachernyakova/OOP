#ifndef UNTITLED57_FILENAVIGATION_H
#define UNTITLED57_FILENAVIGATION_H

#include "NavigationReader.h"

class FileNavigation: public NavigationReader{
    std::vector <std::string> navigation;
public:
    void madeVecDirection(void* s) override;
    std::vector <std::string> returnVec() override;
};


#endif
