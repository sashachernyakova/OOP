#include "Mediator.h"

Mediator::Mediator(): reader(CommandReader()){
    std::cout << "If you want to create a field with default sizes, then enter 1, with your own sizes - 2\n";
    reader.read();
    if (reader.getResult() == "1"){
        controller = Controller();
    } else{
        std::cout << "Enter field's height\n";
        reader.read();
        size1 = reader.getResult();
        std::cout << "Enter field's width\n";
        reader.read();
        size2 = reader.getResult();
        controller = Controller(std::stoi(size1), std::stoi(size2));
    }
    controller.printStartField();
    std::cout << "The game has begun. You can start moving the player. Input format: <number of steps><enter><action>\nTo find out the total number of steps, enter steps\n";
    while(5 == 5){
        reader.read();
        size1 = reader.getResult();
        if (size1 == "steps"){
            controller.level();
        }else if (size1 == "stop"){
            std::cout << "Game over" << "\n";
            break;
        }else{
            reader.read();
            size2 = reader.getResult();
            controller.movement(std::stoi(size1), size2);
        }
    }
}

