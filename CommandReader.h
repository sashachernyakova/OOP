#ifndef UNTITLED57_COMMANDREADER_H
#define UNTITLED57_COMMANDREADER_H

#include <string>
#include <iostream>
#include "Field.h"

class CommandReader{
    std::string n;
public:
    CommandReader();

    bool isDirection(std::string direction);

    Field::Action getAction(std::string direction);

    std::string read();
};

#endif
