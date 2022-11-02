#ifndef UNTITLED57_IOBSERVER_H
#define UNTITLED57_IOBSERVER_H

#pragma once

#include <iostream>
#include <map>

class IObserver{
public:
    enum Logger{
        win,
        lose,
        health,
        experience,
        treasure,
        someSteps,
        allSteps,
        stopGame,
        gameStart,
        errorHeight,
        errorWidth,
        errorDirection,
        errorStartNumber
    };
    virtual void update(int m, Logger l) = 0;
};

#endif
