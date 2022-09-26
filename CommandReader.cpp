#include "CommandReader.h"

CommandReader::CommandReader(): n("") {};

std::string CommandReader::getResult(){
    return n;
}

void CommandReader::read(){
    getline(std::cin, n);
}

