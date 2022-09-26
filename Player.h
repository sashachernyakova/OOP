#ifndef UNTITLED57_PLAYER_H
#define UNTITLED57_PLAYER_H

class Player{
    int hasSkipEvent;
    int totalSteps;
    int hasChangeEvent;
public:
    Player();

    void plusStep();

    int getTotalSteps() const;

    int numberChangeEvent() const;

    int numberSkipEvent() const;
};

#endif
