#ifndef UNTITLED57_PLAYER_H
#define UNTITLED57_PLAYER_H

class Player{
    int totalSkipEvent;
    int totalSteps;
    int totalChangeEvent;
public:
    Player();

    void makeStep();

    int getTotalSteps() const;

    int getChangeEvent() const;

    int getSkipEVent() const;
};

#endif
