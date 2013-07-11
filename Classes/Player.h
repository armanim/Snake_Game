#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "cocos2d.h"
#include "Snake.h"

class Player
{
public:
    Player(Snake*);

    void play(CCPoint);    //  play game

private:
    void setDirection(int);    //  set a direction for snake
    int searchDirection(CCPoint);  //  search next direction
    bool checkUp(CCRect); //  check if up direcrion is avalible
    bool checkDown(CCRect);   //  check if down direction is avalible
    bool checkRight(CCRect);  //  check if right direction is avalible
    bool checkLeft(CCRect);   //  check if left direcrion is avalible
    void adjustDirection(int);

    Snake* mySnake;
    CCPoint headPosition;
    CCPoint nexPosition;
    CCRect upRect;
    CCRect downRect;
    CCRect rightRect;
    CCRect leftRect;
};

#endif // PLAYER_H_INCLUDED
