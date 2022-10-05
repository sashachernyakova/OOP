#include "CommandReader.h"

CommandReader::CommandReader(): n("") {};

bool CommandReader::isDirection(std::string direction){
    return (direction == "right" || direction == "left" || direction == "up" || direction == "down");
};

std::string CommandReader::read(){
    getline(std::cin, n);
    return n;
}

Field::Action CommandReader::getAction(std::string direction){
    if (direction == "right"){
        return Field::right;
    } else if(direction == "left"){
        return Field::left;
    } else if(direction == "up"){
        return Field::up;
    } else if(direction == "down"){
        return Field::down;
    }
}

