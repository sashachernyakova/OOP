#include "ConsoleReader.h"

std::string ConsoleReader::read(){
    getline(std::cin, n);
    return n;
}




