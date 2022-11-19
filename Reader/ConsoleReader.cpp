#include "ConsoleReader.h"

std::string ConsoleReader::read(){
    getline(std::cin, str);
    return str;
}

bool ConsoleReader::canRead() {
    return true;
}




