#ifndef UNTITLED57_PLAYER_H
#define UNTITLED57_PLAYER_H

class Player{
    int totalSteps;
    int hp;
    int xp;
    int treasure;
public:
    Player();

    void makeStep();

    int getTotalSteps() const;

    int getHP() const;

    int getXP() const;

    int getTreasure() const;

    void changeHP(int newHP);

    void changeXP(int newXP);

    void changeTreasure();

};

#endif
