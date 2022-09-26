#ifndef UNTITLED57_COMMANDREADER_H
#define UNTITLED57_COMMANDREADER_H


#include <string>
#include <iostream>

class CommandReader{
    std::string n;
public:
    CommandReader();

    std::string getResult();

    void read();
};

#endif
