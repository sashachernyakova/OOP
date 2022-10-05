#include "Mediator.h"

Mediator::Mediator(): reader(CommandReader()){
    std::cout << "If you want to create a field with default sizes 10x10, then enter 1, with your own sizes - 2\n";
    size1 = reader.read();
    if (size1 == "1"){
        controller = new Controller();
    } else if (size1 == "2"){
        std::cout << "Enter field's height\n";
        size1 = reader.read();
        if(size1[0] == '-'){
            std::cout << "Height can not be negative. The height is set with default size 10.\n";
            size1 = "10";
        }
        std::cout << "Enter field's width\n";
        size2 = reader.read();
        if(size2[0] == '-'){
            std::cout << "Width can not be negative. The width is set with default size 10.\n";
            size2 = "10";
        }
        controller = new Controller(std::stoi(size1), std::stoi(size2));
    } else {
        std::cout << "You can not enter this number. The field is set with default sizes: 10x10\n";
        controller = new Controller();
    }
    std::cout << "The game has begun. You can start moving the player. Input format: <number of steps><enter><action>\nTo find out the total number of steps, enter steps\n";
    while(5 == 5){
        size1 = reader.read();
        if (size1 == "steps"){
            controller->steps();
        }else if (size1 == "stop"){
            std::cout << "Game over" << "\n";
            break;
        }else{
            size2 = reader.read();
            if (reader.isDirection(size2 )){
                controller->movement(std::stoi(size1), reader.getAction(size2));
            } else {
                std::cout << "You entered error direction. You can enter: right, left, up, down\n";
            }
        }
    }
}

Mediator::~Mediator(){
    delete controller;
}


