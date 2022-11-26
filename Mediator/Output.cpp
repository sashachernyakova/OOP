#include "Output.h"

void Output::logger() {
    std::cout << "Choose the logging level\n";
}

void Output::createField() {
    std::cout << "If you want to create a field with default sizes 10x10, then enter 1, with your own sizes - 2\n";
}

void Output::getSize() {
    std::cout << "Enter field's <height><enter><width>\n";
}

void Output::gameRules() {
    std::cout << "You can start moving the player. Reader format: <number of steps> <action>\n";
}

void Output::howPrint() {
    std::cout << "chose how you want logging: 1 - no output, 2 - console output, 3 - file output, 4 - console and file output\n";
}

void Output::rules() {
    std::cout << "chose how you want to red rules: 1 - console, 2 - file\n";
}
