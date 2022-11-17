#include "CommandReader.h"

std::string CommandReader::read(){
    getline(std::cin, n);
    return n;
}




