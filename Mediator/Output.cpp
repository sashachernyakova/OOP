#include "Output.h"

void Output::logger() {
    std::cout << "Choose the logging level\n";
}

void Output::createField() {
    std::cout << "If you want to create a field with default sizes 10x10, then enter 1, with your own sizes - 2\n";
}

void Output::getHeight() {
    std::cout << "Enter field's height\n";
}

void Output::getWidth() {
    std::cout << "Enter field's width\n";
}

void Output::gameRules() {
    std::cout << "You can start moving the player. Input format: <number of steps><enter><action>\nTo find out the total number of steps, enter steps\n";
}

void Output::howPrint() {
    std::cout << "chose how you want logging: 1 - no output, 2 - console output, 3 - file output, 4 - console and file output\n";
}
