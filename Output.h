#ifndef UNTITLED57_OUTPUT_H
#define UNTITLED57_OUTPUT_H

#include <iostream>

class Output{
public:
    void startGame();
    void getHeight();
    void getWidth();
    void errorHeight();
    void errorWidth();
    void errorStartNumber();
    void gameRules();
    void stopGame();
    void errorDirection();
    void gameOver();
    void win();
    void personInfo(int hp, int xp, int treasure);
    void someSteps(int steps);
    void allSteps(int steps);
};

#endif
