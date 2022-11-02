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

//void Output::errorHeight() {
//    std::cout << "Height can not be negative. The height is set with default size 10.\n";
//}

//void Output::errorWidth() {
//    std::cout << "Width can not be negative. The width is set with default size 10.\n";
//}

//void Output::errorStartNumber() {
//    std::cout << "You can not enter this number. The field is set with default sizes: 10x10\n";
//}

//void Output::stopGame() {
//    std::cout << "The player decided to stop game" << "\n";
//}

//void Output::errorDirection() {
//    std::cout << "You entered error direction. You can enter: right, left, up, down\n";
//}

//void Output::gameOver() {
//    std::cout << "game over, you lost all your health" << "\n";
//}
//
//void Output::win() {
//    std::cout << "Congratulations! You have 5 treasures. You win!" << "\n";
//}

//void Output::personInfo(int hp, int xp, int treasure) {
//    std::cout << "Health: " << hp << ", experience: " << xp << ", treasure: " << treasure << "/5" << "\n";
//}

//void Output::someSteps(int steps) {
//    std::cout << "The player have gone only " << steps << " steps. Next cell is unavailable.\n";
//}

//void Output::allSteps(int steps) {
//    std::cout << "The player have gone all " << steps << " steps\n";
//}
